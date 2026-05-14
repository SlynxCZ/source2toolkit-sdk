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

* @file IToolkitGameConfig.h
* @brief Interface for accessing game configuration (gamedata).
*
* Provides access to external configuration data used for:
* * Signature scanning
* * Symbol resolution
* * Memory patching
* * Offset lookup
*
* @note Typically backed by external config files (JSON, KV, etc.).
  */

#ifndef _INCLUDE_ITOOLKIT_GAMECONFIG_H
#define _INCLUDE_ITOOLKIT_GAMECONFIG_H

#pragma once
#include "IToolkitTypes.h"

#include "eiface.h"

/**

* @brief Interface for accessing game configuration entries.
  */
class IToolkitGameConfig
{
public:
    virtual ~IToolkitGameConfig() = default;

    /**

    * @brief Gets library/module name.
    *
    * @param pchName Config entry name
    * @return Library name
      */
    virtual const char* GetLibrary(const char* pchName) = 0;

    /**

    * @brief Gets signature (pattern).
    *
    * @param pchName Config entry name
    * @return Pattern string
      */
    virtual const char* GetSignature(const char* pchName) = 0;

    /**

    * @brief Gets symbol name.
    *
    * @param pchName Config entry name
    * @return Symbol string
      */
    virtual const char* GetSymbol(const char* pchName) = 0;

    /**

    * @brief Gets patch definition.
    *
    * @param pchName Config entry name
    * @return Patch data
      */
    virtual const char* GetPatch(const char* pchName) = 0;

    /**

    * @brief Gets integer offset.
    *
    * @param pchName Config entry name
    * @return Offset value
      */
    virtual int GetOffset(const char* pchName) = 0;
};

#endif //_INCLUDE_ITOOLKIT_GAMECONFIG_H
