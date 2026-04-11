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
#include "eiface.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

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
