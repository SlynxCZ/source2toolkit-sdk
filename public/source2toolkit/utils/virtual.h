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
} // namespace vmt
