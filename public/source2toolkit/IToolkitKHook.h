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
 * @file IToolkitKHook.h
 * @brief KHook's virtual hook object, with a way to let go of it from inside
 *        a hook.
 *
 * KHook::Virtual removes its hooks in its destructor, synchronously, and a
 * synchronous removal waits for every call of the hooked function that is in
 * flight -- the one on this thread included. `meta unload` and `toolkit unload`
 * both arrive through ICvar::DispatchConCommand, so anything that hooked it
 * (the toolkit core does) deadlocked the server the moment it was unloaded
 * from the console, and the watchdog then killed the process.
 *
 * Asking KHook for an asynchronous removal from here is no better: its worker
 * takes a global lock and then waits for the same in-flight call, and the
 * next KHook call on this thread -- metamod's own unloader makes one -- waits
 * for the worker.
 *
 * So an unload does not remove virtual hooks at all. Abandon() makes the
 * object inert and parks it; the hooks come out later, from outside the call
 * that unloaded the plugin: metamod's unloader takes the toolkit's own down
 * once Unload() has returned, and the toolkit takes a plugin's down from a
 * thread of its own. Whoever does that keeps the library mapped until it is
 * done -- KHook calls back into it for every hook it removes -- and the
 * parked objects are deleted when the library is finally closed.
 *
 * Only Virtual gets this. A virtual hook is filtered by instance, so
 * Remove()/RemoveGlobal() first makes the callbacks inert at once and the
 * removal itself can take its time. A Member/Function detour has no such
 * filter -- removed late it would still call into a plugin that has finished
 * unloading -- and the functions those hook are not the ones an unload command
 * travels through, so they keep the synchronous destructor.
 */

#ifndef _INCLUDE_ITOOLKIT_KHOOK_H
#define _INCLUDE_ITOOLKIT_KHOOK_H

#pragma once

#include <mutex>
#include <utility>
#include <vector>

#include "khook.hpp"

// Per library, like IToolkitHooks.h: the parked objects belong to the binary
// whose hooks they are, and go when it does.
#if defined(__GNUC__)
#pragma GCC visibility push(hidden)
#endif

namespace ToolkitKHook
{
    /// The parked hook objects of this library, deleted with it. By then
    /// KHook has taken their hooks out, so the destructors find nothing left
    /// to remove.
    class Graveyard
    {
    public:
        static Graveyard& Get()
        {
            static Graveyard s_instance;
            return s_instance;
        }

        void Park(void* pObject, void (*pfnDelete)(void*))
        {
            std::lock_guard guard(m_mutex);
            m_parked.emplace_back(pObject, pfnDelete);
        }

        ~Graveyard()
        {
            for (auto& [pObject, pfnDelete] : m_parked)
                pfnDelete(pObject);
        }

    private:
        std::mutex m_mutex;
        std::vector<std::pair<void*, void (*)(void*)>> m_parked;
    };

    template <typename CLASS, typename RETURN, typename... ARGS>
    class Virtual : public KHook::Virtual<CLASS, RETURN, ARGS...>
    {
        using Base = KHook::Virtual<CLASS, RETURN, ARGS...>;

    public:
        using Base::Base;

        /**
         * Lets go of the object without removing its hooks: from here on it
         * accepts no new ones, and it is deleted when this library is closed.
         * Call Remove()/RemoveGlobal() first, so the callbacks stop right
         * away. Nothing may touch `self` after this call.
         */
        static void Abandon(Virtual* self)
        {
            if (!self)
                return;

            {
                std::lock_guard guard(self->_hooks_stored);
                // What ~Virtual sets too: _Setup() adds no hook from here on.
                self->_in_deletion = true;
            }

            Graveyard::Get().Park(self, [](void* p) { delete static_cast<Virtual*>(p); });
        }
    };

    /// Abandon() for a pointer of any ToolkitKHook::Virtual type. The pointer
    /// itself is the caller's to reset.
    template <typename CLASS, typename RETURN, typename... ARGS>
    inline void Abandon(Virtual<CLASS, RETURN, ARGS...>* pHook)
    {
        Virtual<CLASS, RETURN, ARGS...>::Abandon(pHook);
    }
}

#if defined(__GNUC__)
#pragma GCC visibility pop
#endif

#endif //_INCLUDE_ITOOLKIT_KHOOK_H
