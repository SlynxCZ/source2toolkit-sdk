/**

* @file addresses.h
* @brief High-level helper functions for address and memory utilities.
*
* These functions provide simplified access to the IToolkitAddresses interface.
* They are commonly used for:
* * Pattern scanning
* * Symbol resolution
* * Pointer manipulation
* * Reverse engineering utilities
*
* @note These are low-level utilities intended for advanced usage.
* @note Internally wraps IToolkitAddresses.
  */

#pragma once

#ifdef SOURCE2TOOLKIT_CORE
#include "core/addresses.h"
#else
#include "source2toolkit/IToolkitAddresses.h"
#endif

/* =========================
Module utilities
========================= */

/**

* @brief Retrieves the OS-specific module handle.
*
* @param module Module identifier or pointer
* @return Native module handle
*
* @note Wrapper around IToolkitAddresses::GetModuleHandle()
  */
void* UTIL_GetModuleHandle(void* module);

/**

* @brief Gets the base address of a module.
*
* @param module Module identifier
* @return Base address of the module
*
* @note Wrapper around IToolkitAddresses::GetModuleBase()
  */
uintptr_t UTIL_GetModuleBase(void* module);

/**

* @brief Gets the absolute path of a module.
*
* @param module Module identifier
* @return Absolute path of the module
*
* @note Wrapper around IToolkitAddresses::GetModulePath()
  */
const char* UTIL_GetModulePath(void* module);

/* =========================
Pattern scanning
========================= */

/**

* @brief Finds a byte pattern in a module.
*
* @param module Module to scan
* @param pattern Pattern string (IDA-style, e.g. "48 8B ?? ?? ??")
* @return Address of the first match, or 0 if not found
*
* @note Wrapper around IToolkitAddresses::FindPattern()
  */
uintptr_t UTIL_FindPattern(void* module, const char* pattern);

/**

* @brief Finds a byte pattern in a specific section of a module.
*
* @param module Module to scan
* @param section Section name (e.g. ".text", ".data")
* @param pattern Pattern string
* @return Address of the match, or 0 if not found
*
* @note Wrapper around IToolkitAddresses::FindPatternInSection()
  */
uintptr_t UTIL_FindPatternInSection(void* module, const char* section, const char* pattern);

/* =========================
Symbol / VTable
========================= */

/**

* @brief Resolves a function by exported symbol name.
*
* @param module Module to search
* @param symbol Symbol name
* @return Address of the function, or 0 if not found
*
* @note Wrapper around IToolkitAddresses::GetFunctionByName()
  */
uintptr_t UTIL_GetFunctionByName(void* module, const char* symbol);

/**

* @brief Retrieves a virtual table by class name.
*
* @param module Module to search
* @param name Class name
* @return Address of the virtual table
*
* @note Wrapper around IToolkitAddresses::GetVirtualTableByName()
  */
uintptr_t UTIL_GetVirtualTableByName(void* module, const char* name);

/* =========================
Pointer utilities
========================= */

/**

* @brief Applies an offset to an address.
*
* @param address Base address
* @param offset Offset to apply
* @return Resulting address
*
* @note Wrapper around IToolkitAddresses::Offset()
  */
uintptr_t UTIL_Offset(uintptr_t address, ptrdiff_t offset);

/**

* @brief Applies an offset directly to a variable.
*
* @param address Reference to address
* @param offset Offset to apply
* @return Resulting address
*
* @note Wrapper around IToolkitAddresses::OffsetSelf()
  */
uintptr_t UTIL_OffsetSelf(uintptr_t& address, ptrdiff_t offset);

/**

* @brief Dereferences a pointer multiple times.
*
* @param address Starting address
* @param count Number of dereferences
* @return Final dereferenced address
*
* @note Wrapper around IToolkitAddresses::Deref()
  */
uintptr_t UTIL_Deref(uintptr_t address, int count = 1);

/**

* @brief Dereferences a pointer in-place.
*
* @param address Reference to address
* @param count Number of dereferences
* @return Final address
*
* @note Wrapper around IToolkitAddresses::DerefSelf()
  */
uintptr_t UTIL_DerefSelf(uintptr_t& address, int count = 1);

/**

* @brief Resolves a relative address (RIP-relative).
*
* @param address Instruction address
* @param offset Offset to relative value
* @param size Size of instruction (default = 4 bytes)
* @return Resolved absolute address
*
* @note Commonly used for x86_64 RIP-relative addressing
* @note Wrapper around IToolkitAddresses::ResolveRelativeAddress()
  */
uintptr_t UTIL_ResolveRelativeAddress(uintptr_t address, ptrdiff_t offset = 0x0, ptrdiff_t size = 0x4);

/**

* @brief Follows a near CALL instruction to its destination.
*
* @param address Address of CALL instruction
* @param offset Offset to relative operand
* @param size Instruction size (default = 5 bytes)
* @return Target function address
*
* @note Wrapper around IToolkitAddresses::FollowNearCall()
  */
uintptr_t UTIL_FollowNearCall(uintptr_t address, ptrdiff_t offset = 0x1, ptrdiff_t size = 0x5);
