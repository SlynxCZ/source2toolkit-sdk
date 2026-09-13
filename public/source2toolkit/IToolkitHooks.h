/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
 * AlliedModders LLC. All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
 * AlliedModders LLC give you permission to link the code of this program
 * (as well as its derivative works) to "Counter-Strike 2," "Source 2,"
 * "Steam," and any Game MODs or server software running on software by
 * Valve Corporation. You must obey the GNU General Public License in all
 * respects for all other code used.
 *
 * Additionally, this exception applies to all derivative works unless
 * otherwise stated in LICENSE.txt.
 *
 * Authors:
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

/**

* @file IToolkitHooks.h
* @brief One-line KHook hooks: declared, resolved, attached and taken down
* from a single place.
*
* A raw KHook hook needs four places: the type in the header, `new` in the
* constructor, the address lookup plus Configure/Add in Init, and
* Remove/delete in Unload. The wrappers here fold all of that into one
* member declared with a macro in the class body:
*
* @code
* class CHooks
* {
* public:
*     KHook::Return<void> OnPostThink(CCSPlayerPawn* pThis, double a2, float a3);
*     KHook::Return<void> OnGameFrame(ISource2Server* pThis, bool a, bool b, bool c);
*     KHook::Return<int>  OnLoadEventsFromFile(IGameEventManager2* pThis, const char* pszFile, bool bSearchAll);
*     KHook::Return<void> OnRespawn(CCSPlayerController* pThis);
*
*     KHOOK_MEMBER(m_hPostThink, "CCSPlayerPawn::PostThink", &CHooks::OnPostThink, nullptr);
*     KHOOK_VIRTUAL(m_hGameFrame, &ISource2Server::GameFrame, &g_pSource2Server, nullptr, &CHooks::OnGameFrame);
*     KHOOK_VIRTUAL(m_hLoadEventsFromFile, &IGameEventManager2::LoadEventsFromFile, KHOOK_VTABLE("server", "CGameEventManager"), &CHooks::OnLoadEventsFromFile, nullptr);
*     KHOOK_VIRTUAL(m_hRespawn, "CCSPlayerController::Respawn", KHOOK_VTABLE("server", "CCSPlayerController"), &CHooks::OnRespawn, nullptr);
* };
* @endcode
*
* The hook's type is taken from the handler's signature (the first parameter
* is the hooked class, the rest are the function's own arguments), so nothing
* is spelled twice and MSVC needs no CTAD. The handler has to be declared
* above the macro that names it. The context is the enclosing object.
*
* `KHOOK_INIT()` in Load() (after TOOLKIT_SAVEVARS()) resolves and installs
* every hook declared this way; `KHOOK_DESTRUCT()` in Unload() takes them
* all down. A hook whose target is `nullptr` is left to the caller:
* `m_hX.Init(address)`, `m_hX.Init(pInstance)` or `m_hX.InitGlobal(vtable)`.
*
* Targets:
* * KHOOK_MEMBER / KHOOK_FUNCTION -- a gamedata entry name (resolved through
*   IToolkitGameConfig::ResolveSignature), an IToolkitMemory address, a
*   capture-less lambda returning the address when called at KHOOK_INIT()
*   (`[] { return ADDR_TAKE_DAMAGE_OLD(); }` -- for what the toolkit already
*   resolved), or `nullptr`.
* * KHOOK_VIRTUAL -- the function is a member function pointer (index read
*   from the vtable), an integer index, or a gamedata offset name; the
*   target is a pointer to the instance pointer (`&g_pSource2Server`, read
*   at Init so it may still be null when the hook is constructed),
*   `KHOOK_VTABLE(module, class)` for a whole vtable by RTTI name -- the
*   module as a name or as `&pModule` (an IToolkitModule* filled in at
*   load) -- or `nullptr`.
*
* `KHOOK_NEW` (IToolkitTypes.h) is still there for a raw KHook object with
* none of this on top.
  */

#ifndef _INCLUDE_ITOOLKIT_HOOKS_H
#define _INCLUDE_ITOOLKIT_HOOKS_H

#pragma once

#ifndef SOURCE2TOOLKIT_CORE

#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <vector>

// Deliberately nothing from IToolkitPlugin.h / IToolkitGameConfig.h /
// IToolkitApi.h here: this header lands at the end of IToolkitPlugin.h, which
// most SDK headers include first, so anything from them would still be
// incomplete. Whatever needs the plugin globals is in src/utils/hooks.cpp.
#include "IToolkitTypes.h"
#include "IToolkitMemory.h"
#include "IToolkitModule.h"

// Everything below is per plugin binary: the hook list must never be shared
// with (or interposed by) another plugin's copy of this header.
#if defined(__GNUC__)
#pragma GCC visibility push(hidden)
#endif

/* =========================
Base + registry
========================= */

/**

* @brief A hook the plugin declared through one of the KHOOK_* macros.
*
* Every instance registers itself on construction; KHOOK_INIT() and
* KHOOK_DESTRUCT() walk that list.
  */
class IToolkitHook
{
public:
    virtual ~IToolkitHook()
    {
        std::vector<IToolkitHook*>& vecHooks = List();
        for (size_t i = 0; i < vecHooks.size(); ++i)
        {
            if (vecHooks[i] == this)
            {
                vecHooks.erase(vecHooks.begin() + i);
                break;
            }
        }
    }

    /**

    * @brief Resolves the target given at construction and installs the hook.
    *
    * @return false when the target could not be resolved. A hook with no
    *         target (nullptr) is left alone and counts as success.
      */
    virtual bool Init() = 0;

    /**

    * @brief Detaches and deletes the underlying KHook object.
    *
    * Deleting is what takes the detour down. Safe to call more than once.
      */
    virtual void Destruct() = 0;

    /**

    * @brief Whether the hook is currently installed.
      */
    virtual bool IsInstalled() const = 0;

    /**

    * @brief Init() on every hook declared in this plugin.
    *
    * @return false when any of them failed; the rest are installed anyway.
      */
    static bool InitAll()
    {
        bool bOk = true;
        for (IToolkitHook* pHook : List())
        {
            if (!pHook->Init())
                bOk = false;
        }
        return bOk;
    }

    /**

    * @brief Destruct() on every hook declared in this plugin, last first.
      */
    static void DestructAll()
    {
        std::vector<IToolkitHook*>& vecHooks = List();
        for (size_t i = vecHooks.size(); i-- > 0;)
            vecHooks[i]->Destruct();
    }

protected:
    IToolkitHook()
    {
        List().push_back(this);
    }

    IToolkitHook(const IToolkitHook&) = delete;
    IToolkitHook& operator=(const IToolkitHook&) = delete;

    // Function-local so it exists before the first hook (a member of some
    // global object) registers, whatever the translation-unit order.
    static std::vector<IToolkitHook*>& List()
    {
        static std::vector<IToolkitHook*> s_vecHooks;
        return s_vecHooks;
    }

    // These go through IToolkitAPI and IToolkitGameConfig, which are only
    // forward-declared where this header lands (the end of IToolkitPlugin.h),
    // so they are defined in the SDK's src/utils/hooks.cpp.
    static void Warn(const char* pszFormat, const char* pszName);
    static void FreeModule(IToolkitModule* pModule);
    static int GetOffset(const char* pszName);
    static IToolkitMemory ResolveSignature(const char* pszName);
};

/**

* @brief The vtable a global virtual hook attaches to: an RTTI class name
* inside a module ("server", "engine2", ...).
  */
struct CToolkitVTableName
{
    CToolkitVTableName() = default;

    /// The module by name -- loaded through IToolkitModule::New at Init.
    CToolkitVTableName(const char* module, const char* name) :
        pszModule(module), pszClass(name)
    {
    }

    /// The module through a pointer to an IToolkitModule* the plugin fills
    /// in at load (read at Init, so it may still be null now).
    CToolkitVTableName(IToolkitModule** module, const char* name) :
        ppModule(module), pszClass(name)
    {
    }

    const char* pszModule = nullptr;
    IToolkitModule** ppModule = nullptr;
    const char* pszClass = nullptr;
};

namespace toolkithook
{
    // What a lambda target may hand back: an IToolkitMemory, anything that
    // converts to one (void*, uintptr_t), or a typed function pointer such as
    // the ADDR_* getters return.
    inline IToolkitMemory ToMemory(IToolkitMemory address)
    {
        return address;
    }

    template <typename R, typename... A>
    inline IToolkitMemory ToMemory(R (*pfnFunction)(A...))
    {
        return IToolkitMemory(reinterpret_cast<const void*>(pfnFunction));
    }
} // namespace toolkithook

/* =========================
Virtual
========================= */

/**

* @brief A KHook::Virtual plus where it goes.
*
* @tparam CLASS  The hooked class -- the handler's first parameter.
* @tparam RETURN The hooked function's return type.
* @tparam ARGS   The hooked function's own arguments.
  */
template <typename CLASS, typename RETURN, typename... ARGS>
class CToolkitVirtualHook : public IToolkitHook
{
public:
    using HookType = KHook::Virtual<CLASS, RETURN, ARGS...>;

    /**

    * @param function A member function pointer, a vtable index, or the name
    *                 of a gamedata offset.
    * @param target   `&pInstance` (read at Init), KHOOK_VTABLE(module, class),
    *                 or nullptr.
    * @param pContext The object the callbacks are members of.
    * @param pre      Callback before the original, or nullptr.
    * @param post     Callback after the original, or nullptr.
      */
    template <typename FUNCTION, typename TARGET, typename CONTEXT, typename PRE, typename POST>
    CToolkitVirtualHook(FUNCTION function, TARGET target, CONTEXT* pContext, PRE pre, POST post)
    {
        Create(function, pContext, pre, post);
        SetTarget(target);
    }

    ~CToolkitVirtualHook() override
    {
        Destruct();
    }

    bool Init() override
    {
        if (!m_pHook)
            return false;

        if (m_bInstalled)
            return true;

        if (m_pfnInstance)
        {
            CLASS* pInstance = m_pfnInstance(m_pInstanceSource);
            if (!pInstance)
            {
                Warn("KHook: the instance to hook is still null at init; hook not installed (%s)\n", m_pszIndexName ? m_pszIndexName : "virtual hook");
                return false;
            }

            return Init(pInstance);
        }

        if (m_VTable.pszClass)
        {
            if (m_VTable.ppModule)
                return InitGlobal(*m_VTable.ppModule, m_VTable.pszClass);

            return InitGlobal(m_VTable.pszModule, m_VTable.pszClass);
        }

        return true;
    }

    /**

    * @brief Installs the hook on one instance.
      */
    bool Init(CLASS* pInstance)
    {
        if (!m_pHook || !pInstance || !ResolveIndex())
            return false;

        m_pHook->Add(pInstance);
        m_pInstance = pInstance;
        m_bInstalled = true;
        return true;
    }

    /**

    * @brief Installs the hook on a whole vtable -- every object sharing it.
      */
    bool InitGlobal(IToolkitMemory vtable)
    {
        if (!m_pHook || !vtable || !ResolveIndex())
            return false;

        // AddGlobal only ever reads the first pointer of what it is handed,
        // so a plain pointer holding the vtable is a valid stand-in.
        m_pVTable = vtable.GetPtr();
        m_pHook->AddGlobal(reinterpret_cast<CLASS*>(&m_pVTable));
        m_bInstalled = true;
        return true;
    }

    /**

    * @brief Installs the hook on the vtable of an RTTI class name in a module.
      */
    bool InitGlobal(IToolkitModule* pModule, const char* pszClass)
    {
        if (!pModule)
        {
            Warn("KHook: no module to look '%s' up in; hook not installed\n", pszClass);
            return false;
        }

        const IToolkitMemory vtable = pModule->GetVirtualTableByName(pszClass);
        if (!vtable)
        {
            Warn("KHook: vtable '%s' was not found; hook not installed\n", pszClass);
            return false;
        }

        return InitGlobal(vtable);
    }

    /**

    * @brief Same, with the module loaded by name for the lookup.
      */
    bool InitGlobal(const char* pszModule, const char* pszClass)
    {
        IToolkitModule* pModule = IToolkitModule::New(pszModule);
        if (!pModule)
        {
            Warn("KHook: module '%s' is not loaded; hook not installed\n", pszModule);
            return false;
        }

        const bool bInstalled = InitGlobal(pModule, pszClass);
        FreeModule(pModule);
        return bInstalled;
    }

    void Destruct() override
    {
        if (!m_pHook)
            return;

        if (m_pInstance)
            m_pHook->Remove(m_pInstance);

        if (m_pVTable)
            m_pHook->RemoveGlobal(reinterpret_cast<CLASS*>(&m_pVTable));

        delete m_pHook;
        m_pHook = nullptr;
        m_pInstance = nullptr;
        m_pVTable = nullptr;
        m_bIndexResolved = false;
        m_bInstalled = false;
    }

    bool IsInstalled() const override
    {
        return m_bInstalled;
    }

    /// The KHook object itself, for anything the wrapper does not cover.
    HookType* Get() const
    {
        return m_pHook;
    }

    HookType* operator->() const
    {
        return m_pHook;
    }

    /// Runs the original on pThis, bypassing the hook chain.
    RETURN CallOriginal(CLASS* pThis, ARGS... args)
    {
        return m_pHook->CallOriginal(pThis, args...);
    }

private:
    // A gamedata offset is read once, on the first install.
    bool ResolveIndex()
    {
        if (!m_pszIndexName || m_bIndexResolved)
            return true;

        // -1 must never reach the vtable: one slot before it is the typeinfo
        // pointer, and a hook there breaks every later by-name vtable lookup
        // on that class.
        const int index = GetOffset(m_pszIndexName);
        if (index < 0)
        {
            Warn("KHook: offset '%s' is missing from gamedata; hook not installed\n", m_pszIndexName);
            return false;
        }

        m_pHook->Configure(index);
        m_bIndexResolved = true;
        return true;
    }

    template <typename CONTEXT, typename PRE, typename POST>
    void Create(RETURN (CLASS::*function)(ARGS...), CONTEXT* pContext, PRE pre, POST post)
    {
        m_pHook = new HookType(function, pContext, pre, post);
    }

    template <typename CONTEXT, typename PRE, typename POST>
    void Create(RETURN (CLASS::*function)(ARGS...) const, CONTEXT* pContext, PRE pre, POST post)
    {
        m_pHook = new HookType(function, pContext, pre, post);
    }

    template <typename INDEX, typename CONTEXT, typename PRE, typename POST,
              std::enable_if_t<std::is_integral_v<INDEX>, int> = 0>
    void Create(INDEX index, CONTEXT* pContext, PRE pre, POST post)
    {
        m_pHook = new HookType(static_cast<std::uint32_t>(index), pContext, pre, post);
    }

    template <typename CONTEXT, typename PRE, typename POST>
    void Create(const char* pszIndexName, CONTEXT* pContext, PRE pre, POST post)
    {
        // Placeholder index; Init() reads the real one from gamedata.
        m_pszIndexName = pszIndexName;
        m_pHook = new HookType(0u, pContext, pre, post);
    }

    // The instance is read at Init, not now: engine interfaces are only
    // filled in by Load(), long after a global object's constructor ran.
    // T may be a class derived from CLASS (ISource2Server for IServerGameDLL).
    template <typename T>
    void SetTarget(T** ppInstance)
    {
        m_pInstanceSource = ppInstance;
        m_pfnInstance = [](void* pSource) -> CLASS*
        {
            return static_cast<CLASS*>(*static_cast<T**>(pSource));
        };
    }

    void SetTarget(CToolkitVTableName vtable)
    {
        m_VTable = vtable;
    }

    void SetTarget(std::nullptr_t)
    {
    }

    HookType* m_pHook = nullptr;
    const char* m_pszIndexName = nullptr;
    void* m_pInstanceSource = nullptr;
    CLASS* (*m_pfnInstance)(void*) = nullptr;
    CToolkitVTableName m_VTable;
    CLASS* m_pInstance = nullptr;
    void* m_pVTable = nullptr;
    bool m_bIndexResolved = false;
    bool m_bInstalled = false;
};

/* =========================
Member
========================= */

/**

* @brief A KHook::Member (a function with a `this`, found by address) plus
* where its address comes from.
  */
template <typename CLASS, typename RETURN, typename... ARGS>
class CToolkitMemberHook : public IToolkitHook
{
public:
    using HookType = KHook::Member<CLASS, RETURN, ARGS...>;

    /**

    * @param target   A gamedata entry name, an IToolkitMemory address, a
    *                 capture-less lambda returning the address, or nullptr.
    * @param pContext The object the callbacks are members of.
    * @param pre      Callback before the original, or nullptr.
    * @param post     Callback after the original, or nullptr.
      */
    template <typename TARGET, typename CONTEXT, typename PRE, typename POST>
    CToolkitMemberHook(TARGET target, CONTEXT* pContext, PRE pre, POST post)
    {
        m_pHook = new HookType(pContext, pre, post);
        SetTarget(target);
    }

    ~CToolkitMemberHook() override
    {
        Destruct();
    }

    bool Init() override
    {
        if (!m_pHook)
            return false;

        if (m_bInstalled)
            return true;

        if (m_Address)
            return Init(m_Address);

        if (m_pfnResolve)
        {
            const IToolkitMemory address = m_pfnResolve();
            if (!address)
            {
                Warn("KHook: %s; hook not installed\n", "the address resolver returned null");
                return false;
            }

            return Init(address);
        }

        if (m_pszName)
        {
            const IToolkitMemory address = ResolveSignature(m_pszName);
            if (!address)
            {
                Warn("KHook: '%s' was not resolved; hook not installed\n", m_pszName);
                return false;
            }

            return Init(address);
        }

        return true;
    }

    /**

    * @brief Places the detour at an address.
      */
    bool Init(IToolkitMemory address)
    {
        if (!m_pHook || !address)
            return false;

        m_pHook->Configure(address.RCast<const void*>());
        m_bInstalled = true;
        return true;
    }

    /// Same, from a typed function pointer (an ADDR_* getter, say).
    template <typename R, typename... A>
    bool Init(R (*pfnFunction)(A...))
    {
        return Init(IToolkitMemory(reinterpret_cast<const void*>(pfnFunction)));
    }

    void Destruct() override
    {
        delete m_pHook;
        m_pHook = nullptr;
        m_bInstalled = false;
    }

    bool IsInstalled() const override
    {
        return m_bInstalled;
    }

    HookType* Get() const
    {
        return m_pHook;
    }

    HookType* operator->() const
    {
        return m_pHook;
    }

    RETURN CallOriginal(CLASS* pThis, ARGS... args)
    {
        return m_pHook->CallOriginal(pThis, args...);
    }

private:
    void SetTarget(const char* pszName)
    {
        m_pszName = pszName;
    }

    void SetTarget(IToolkitMemory address)
    {
        m_Address = address;
    }

    // Called at Init through a plain function pointer, hence capture-less.
    template <typename RESOLVER, std::enable_if_t<std::is_invocable_v<RESOLVER>, int> = 0>
    void SetTarget(RESOLVER)
    {
        static_assert(std::is_default_constructible_v<RESOLVER>, "a hook's address resolver must capture nothing");
        m_pfnResolve = []() -> IToolkitMemory
        {
            return toolkithook::ToMemory(RESOLVER{}());
        };
    }

    void SetTarget(std::nullptr_t)
    {
    }

    HookType* m_pHook = nullptr;
    const char* m_pszName = nullptr;
    IToolkitMemory m_Address;
    IToolkitMemory (*m_pfnResolve)() = nullptr;
    bool m_bInstalled = false;
};

/* =========================
Function
========================= */

/**

* @brief A KHook::Function (a free function, found by address) plus where
* its address comes from.
  */
template <typename RETURN, typename... ARGS>
class CToolkitFunctionHook : public IToolkitHook
{
public:
    using HookType = KHook::Function<RETURN, ARGS...>;

    template <typename TARGET, typename CONTEXT, typename PRE, typename POST>
    CToolkitFunctionHook(TARGET target, CONTEXT* pContext, PRE pre, POST post)
    {
        m_pHook = new HookType(pContext, pre, post);
        SetTarget(target);
    }

    ~CToolkitFunctionHook() override
    {
        Destruct();
    }

    bool Init() override
    {
        if (!m_pHook)
            return false;

        if (m_bInstalled)
            return true;

        if (m_Address)
            return Init(m_Address);

        if (m_pfnResolve)
        {
            const IToolkitMemory address = m_pfnResolve();
            if (!address)
            {
                Warn("KHook: %s; hook not installed\n", "the address resolver returned null");
                return false;
            }

            return Init(address);
        }

        if (m_pszName)
        {
            const IToolkitMemory address = ResolveSignature(m_pszName);
            if (!address)
            {
                Warn("KHook: '%s' was not resolved; hook not installed\n", m_pszName);
                return false;
            }

            return Init(address);
        }

        return true;
    }

    bool Init(IToolkitMemory address)
    {
        if (!m_pHook || !address)
            return false;

        m_pHook->Configure(address.RCast<const void*>());
        m_bInstalled = true;
        return true;
    }

    template <typename R, typename... A>
    bool Init(R (*pfnFunction)(A...))
    {
        return Init(IToolkitMemory(reinterpret_cast<const void*>(pfnFunction)));
    }

    void Destruct() override
    {
        delete m_pHook;
        m_pHook = nullptr;
        m_bInstalled = false;
    }

    bool IsInstalled() const override
    {
        return m_bInstalled;
    }

    HookType* Get() const
    {
        return m_pHook;
    }

    HookType* operator->() const
    {
        return m_pHook;
    }

    RETURN CallOriginal(ARGS... args)
    {
        return m_pHook->CallOriginal(args...);
    }

private:
    void SetTarget(const char* pszName)
    {
        m_pszName = pszName;
    }

    void SetTarget(IToolkitMemory address)
    {
        m_Address = address;
    }

    template <typename RESOLVER, std::enable_if_t<std::is_invocable_v<RESOLVER>, int> = 0>
    void SetTarget(RESOLVER)
    {
        static_assert(std::is_default_constructible_v<RESOLVER>, "a hook's address resolver must capture nothing");
        m_pfnResolve = []() -> IToolkitMemory
        {
            return toolkithook::ToMemory(RESOLVER{}());
        };
    }

    void SetTarget(std::nullptr_t)
    {
    }

    HookType* m_pHook = nullptr;
    const char* m_pszName = nullptr;
    IToolkitMemory m_Address;
    IToolkitMemory (*m_pfnResolve)() = nullptr;
    bool m_bInstalled = false;
};

/* =========================
Type deduction for the macros
========================= */

namespace toolkithook
{
    // Whichever of pre/post is not nullptr carries the signature.
    template <typename PRE, typename POST>
    struct Callback
    {
        using type = PRE;
    };

    template <typename POST>
    struct Callback<std::nullptr_t, POST>
    {
        using type = POST;
    };

    // Handler with the hooked object first: Virtual and Member hooks.
    template <typename CALLBACK>
    struct MemberTraits;

    template <typename CONTEXT, typename RETURN, typename CLASS, typename... ARGS>
    struct MemberTraits<KHook::Return<RETURN> (CONTEXT::*)(CLASS*, ARGS...)>
    {
        using Virtual = CToolkitVirtualHook<std::remove_const_t<CLASS>, RETURN, ARGS...>;
        using Member = CToolkitMemberHook<std::remove_const_t<CLASS>, RETURN, ARGS...>;
    };

    // Handler with no hooked object: Function hooks.
    template <typename CALLBACK>
    struct FunctionTraits;

    template <typename CONTEXT, typename RETURN, typename... ARGS>
    struct FunctionTraits<KHook::Return<RETURN> (CONTEXT::*)(ARGS...)>
    {
        using Function = CToolkitFunctionHook<RETURN, ARGS...>;
    };

    template <typename PRE, typename POST>
    using VirtualHookFor = typename MemberTraits<typename Callback<PRE, POST>::type>::Virtual;

    template <typename PRE, typename POST>
    using MemberHookFor = typename MemberTraits<typename Callback<PRE, POST>::type>::Member;

    template <typename PRE, typename POST>
    using FunctionHookFor = typename FunctionTraits<typename Callback<PRE, POST>::type>::Function;
} // namespace toolkithook

#if defined(__GNUC__)
#pragma GCC visibility pop
#endif

/* =========================
Macros
========================= */

/**

* @brief A whole vtable as a virtual hook's target: an RTTI class name in a
* module -- the module's name ("server", "engine2", "tier0", ...) or a
* pointer to an IToolkitModule* the plugin fills in at load (`&modules::server`).
  */
#define KHOOK_VTABLE(module, name) ::CToolkitVTableName{ module, name }

/**

* @brief Declares a virtual hook as a class member.
*
* @param member   Member name.
* @param function `&Class::Method`, a vtable index, or a gamedata offset name.
* @param target   `&pInstance`, KHOOK_VTABLE(module, class), or nullptr.
* @param pre      `&Self::Handler` or nullptr.
* @param post     `&Self::Handler` or nullptr.
*
* @code
* KHOOK_VIRTUAL(m_hGameFrame, &ISource2Server::GameFrame, &g_pSource2Server, nullptr, &Plugin::Hook_GameFrame);
* @endcode
  */
#define KHOOK_VIRTUAL(member, function, target, pre, post) \
    ::toolkithook::VirtualHookFor<decltype(pre), decltype(post)> member { function, target, this, pre, post }

/**

* @brief Declares a hook on a member function found by address.
*
* @param member Member name.
* @param target A gamedata entry name, an IToolkitMemory, a capture-less
*               lambda returning the address, or nullptr.
* @param pre    `&Self::Handler` or nullptr.
* @param post   `&Self::Handler` or nullptr.
*
* @code
* KHOOK_MEMBER(m_hPostThink, "CCSPlayerPawn::PostThink", &Plugin::Hook_PostThink, nullptr);
* KHOOK_MEMBER(m_hTakeDamageOld, [] { return ADDR_TAKE_DAMAGE_OLD(); }, &Plugin::Hook_TakeDamageOld, nullptr);
* @endcode
  */
#define KHOOK_MEMBER(member, target, pre, post) \
    ::toolkithook::MemberHookFor<decltype(pre), decltype(post)> member { target, this, pre, post }

/**

* @brief Declares a hook on a free function found by address. Same
* parameters as KHOOK_MEMBER; the handler takes no hooked object.
  */
#define KHOOK_FUNCTION(member, target, pre, post) \
    ::toolkithook::FunctionHookFor<decltype(pre), decltype(post)> member { target, this, pre, post }

/**

* @brief Installs every hook declared with the macros above. Call in Load(),
* after TOOLKIT_SAVEVARS() and once the instance pointers hooks read are set.
*
* @return false when any hook could not be resolved (each one is logged).
  */
#define KHOOK_INIT()     ::IToolkitHook::InitAll()

/**

* @brief Takes every hook down. Call in Unload().
  */
#define KHOOK_DESTRUCT() ::IToolkitHook::DestructAll()

#endif // SOURCE2TOOLKIT_CORE

#endif //_INCLUDE_ITOOLKIT_HOOKS_H
