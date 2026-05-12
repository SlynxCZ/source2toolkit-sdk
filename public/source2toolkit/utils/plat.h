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

* @file platform.h
* @brief Platform abstraction utilities and module helpers.
*
* Provides:
* * Cross-platform calling conventions
* * Module representation (base, size)
* * Memory patching utilities
*
* @note Used internally by address/pattern systems.
  */

#pragma once
#include <cstdint>
#include <string>
#include <vector>

/* =========================
Module sections
========================= */

/**

* @brief Represents a section of a loaded module.
*
* Used for:
* * Pattern scanning in specific sections
* * Memory analysis
    */
struct Section
{
    /// Section name (e.g. ".text", ".data")
    std::string m_szName;

    /// Pointer to section base
    void* m_pBase;

    /// Section size in bytes
    size_t m_iSize;
};

/* =========================
Calling conventions
========================= */

/**

* @brief Platform-specific calling conventions.
  */
#if defined(_WIN32)

  /// Fastcall convention (Windows)
  #define FASTCALL __fastcall

  /// Thiscall convention (Windows)
  #define THISCALL __thiscall

#else

/// Fastcall not used on Linux
#define FASTCALL

/// Thiscall not used on Linux
#define THISCALL

/// Secure strtok alternative
#define strtok_s strtok_r

#endif

/* =========================
Module representation
========================= */

/**

* @brief Represents a loaded module (library).
*
* Used for:
* * Pattern scanning
* * Address resolution
    */
struct Module
{
#ifndef _WIN32
    /// Handle to loaded module (Linux)
    void* pHandle;
#endif

    /// Base address of module
    uint8_t* pBase;

    /// Module size in bytes
    unsigned int nSize;
};

/* =========================
Module naming
========================= */

#ifdef _WIN32

/// Windows module prefix
#define MODULE_PREFIX ""

/// Windows module extension
#define MODULE_EXT ".dll"

#else

/// Linux module prefix
#define MODULE_PREFIX "lib"

/// Linux module extension
#define MODULE_EXT ".so"

#endif

/* =========================
Memory utilities
========================= */

/**

* @brief Writes raw memory to a given address.
*
* @param pPatchAddress Destination address
* @param pPatch Pointer to data
* @param iPatchSize Size in bytes
*
* @warning This modifies process memory directly.
* Use with caution.
*
* @note Typically used for:
* * Patching instructions
* * Hooking functions
    */
void Plat_WriteMemory(void* pPatchAddress, uint8_t* pPatch, int iPatchSize);
