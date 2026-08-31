/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
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
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
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
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

/**

* @file virtual.h
* @brief Virtual method table (VMT) utilities for calling virtual functions.
*
* Provides low-level helpers for:
* * Retrieving virtual functions from objects
* * Calling virtual methods by index
*
* @warning This is unsafe low-level functionality.
* Incorrect usage may lead to crashes or undefined behavior.
*/

#ifndef _INCLUDE_ITOOLKIT_UTILS_VIRTUAL_H
#define _INCLUDE_ITOOLKIT_UTILS_VIRTUAL_H

#pragma once

#ifdef SOURCE2TOOLKIT_CORE
#include "utils/log.h"
#endif
#include "platform.h"

/**

* @brief Convenience macro for calling virtual functions.
*
* @param retType Return type
* @param idx Virtual table index
* @param ... Arguments (must include class pointer as first arg)
*
* @code
* CALL_VIRTUAL(void, 5, entity, arg1, arg2);
* @endcode
  */
#define CALL_VIRTUAL(retType, idx, ...) \
vmt::CallVirtual<retType>(idx, __VA_ARGS__)

/**

* @brief Calls a virtual function through a vtable the caller supplies.
*
* For objects whose vtable is not the one stored in the instance -- a filter
* whose table was looked up in the server module by name, say -- where
* CALL_VIRTUAL would dispatch through the wrong table.
*
* @param retType Return type
* @param idx Virtual table index
* @param vtable The vtable to dispatch through
* @param ... Arguments (must include the class pointer as the first one)
*
* @code
* CALL_VIRTUAL_OVERRIDE_VTBL(bool, offset, pVTable, this, pEntity);
* @endcode
  */
#define CALL_VIRTUAL_OVERRIDE_VTBL(retType, idx, vtable, ...) \
vmt::CallVirtualOverrideVTable<retType>(idx, vtable, __VA_ARGS__)

namespace vmt
{
    /**
    * @brief Retrieves a virtual function pointer from an object's VTable.
    *
    * @tparam T Function pointer type
    * @param uIndex Index in virtual table
    * @param pClass Pointer to class instance
    *
    * @return Function pointer or nullptr if invalid
    *
    * @warning No bounds checking is performed.
    */
    template <typename T = void*>
    inline T GetVMethod(uint32 uIndex, void* pClass)
    {
        if (!pClass)
        {
#ifdef SOURCE2TOOLKIT_CORE
FP_WARN("Tried getting virtual function from a null class.");
#endif
            return T();
        }

        void** pVTable = *static_cast<void***>(pClass);
        if (!pVTable)
        {
#ifdef SOURCE2TOOLKIT_CORE
FP_WARN("Tried getting virtual function from a null vtable.");
#endif
            return T();
        }

        return reinterpret_cast<T>(pVTable[uIndex]);
    }

    /**
     * @brief Calls a virtual function by index.
     *
     * @tparam T Return type
     * @tparam Args Argument types
     * @param uIndex Virtual table index
     * @param pClass Pointer to class instance
     * @param args Arguments passed to function
     *
     * @return Function result or default value if failed
     *
     * @note Calling convention differs between platforms:
     * - Windows: __thiscall
     * - Linux: __cdecl
     *
     * @warning Index must match correct function signature.
     *
     * @code
     * int result = vmt::CallVirtual<int>(10, entity, arg1);
     * @endcode
     */
    template <typename T, typename... Args>
    inline T CallVirtual(uint32 uIndex, void* pClass, Args... args)
    {
#ifdef _WIN32
auto pFunc = GetVMethod<T(__thiscall*)(void*, Args...)>(uIndex, pClass);
#else
        auto pFunc = GetVMethod<T(__cdecl*)(void*, Args...)>(uIndex, pClass);
#endif
        if (!pFunc)
        {
#ifdef SOURCE2TOOLKIT_CORE
FP_WARN("Tried calling a null virtual function.");
#endif
            return T();
        }

        return pFunc(pClass, args...);
    }

    /**
    * @brief Calls a virtual function through a caller-supplied vtable.
    *
    * Same as CallVirtual, except the table is passed in rather than read out of
    * the object. Needed when the instance does not carry the vtable you want to
    * dispatch through -- e.g. a trace filter whose table was resolved from the
    * server module by name.
    *
    * @tparam T Return type
    * @tparam Args Argument types
    * @param uIndex Virtual table index
    * @param pVTable The vtable to dispatch through
    * @param pClass Pointer passed as the implicit this
    * @param args Arguments passed to the function
    *
    * @return Function result, or a default-constructed T if the table or entry
    *         is null.
    */
    template <typename T = void, typename... Args>
    inline T CallVirtualOverrideVTable(uint32 uIndex, void** pVTable, void* pClass, Args... args)
    {
        if (!pVTable)
        {
#ifdef SOURCE2TOOLKIT_CORE
            FP_WARN("Tried calling a virtual function through a null vtable.");
#endif
            return T();
        }

#ifdef _WIN32
        auto pFunc = reinterpret_cast<T(__thiscall*)(void*, Args...)>(pVTable[uIndex]);
#else
        auto pFunc = reinterpret_cast<T(__cdecl*)(void*, Args...)>(pVTable[uIndex]);
#endif
        if (!pFunc)
        {
#ifdef SOURCE2TOOLKIT_CORE
            FP_WARN("Tried calling a null virtual function.");
#endif
            return T();
        }

        return pFunc(pClass, args...);
    }
} // namespace vmt

#endif //_INCLUDE_ITOOLKIT_UTILS_VIRTUAL_H

