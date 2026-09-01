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
* @file IToolkitJSON.h
* @brief Reading JSON without the plugin owning a JSON library.
*
* The toolkit parses; a plugin walks the result through this interface. Nothing
* library-specific crosses the boundary, so a plugin does not have to vendor a
* matching JSON implementation or agree with the toolkit on its ABI.
*/

#ifndef _INCLUDE_ITOOLKIT_JSON_H
#define _INCLUDE_ITOOLKIT_JSON_H

#pragma once

#include <cstdint>

/**

* @brief One node of a parsed document: an object, array, or scalar.
*
* Nodes are owned by the document they came from and stay valid until it is
* released. Every accessor is total -- asking a string for its integer value,
* or an object for element 3, returns the default you passed rather than
* throwing.
  */
class IToolkitJSONValue
{
public:
    virtual ~IToolkitJSONValue() = default;

    virtual bool IsNull() const = 0;
    virtual bool IsObject() const = 0;
    virtual bool IsArray() const = 0;
    virtual bool IsString() const = 0;
    virtual bool IsNumber() const = 0;
    virtual bool IsBool() const = 0;

    /// @brief Whether this object has the key. False for anything but an object.
    virtual bool Has(const char* pszKey) const = 0;

    /// @brief The value at a key, or null when absent or not an object.
    virtual const IToolkitJSONValue* Get(const char* pszKey) const = 0;

    /// @brief Elements in an array, or members in an object. Zero otherwise.
    virtual int Count() const = 0;

    /// @brief The element at an index, or null when out of range or not an array.
    virtual const IToolkitJSONValue* At(int nIndex) const = 0;

    /// @brief The key of the member at an index, for walking an object.
    ///        Null when out of range or not an object.
    virtual const char* KeyAt(int nIndex) const = 0;

    /**

    * @brief This node's value, or pszDefault when it is not a string.
    *
    * The pointer stays valid as long as the document does.
      */
    virtual const char* AsString(const char* pszDefault = "") const = 0;

    virtual int64_t AsInt64(int64_t nDefault = 0) const = 0;
    virtual int AsInt(int nDefault = 0) const = 0;
    virtual double AsDouble(double flDefault = 0.0) const = 0;
    virtual float AsFloat(float flDefault = 0.0f) const = 0;
    virtual bool AsBool(bool bDefault = false) const = 0;

    /// @brief Shorthand for Get(key) then the matching As*, with the default
    ///        when the key is missing or the wrong type.
    virtual const char* GetString(const char* pszKey, const char* pszDefault = "") const = 0;
    virtual int64_t GetInt64(const char* pszKey, int64_t nDefault = 0) const = 0;
    virtual int GetInt(const char* pszKey, int nDefault = 0) const = 0;
    virtual double GetDouble(const char* pszKey, double flDefault = 0.0) const = 0;
    virtual float GetFloat(const char* pszKey, float flDefault = 0.0f) const = 0;
    virtual bool GetBool(const char* pszKey, bool bDefault = false) const = 0;

    /**

    * @brief This node serialised back to text.
    *
    * @param nIndent Spaces per level, or -1 for the compact form.
    * @return Text owned by the document; valid until it is released.
      */
    virtual const char* Dump(int nIndent = -1) const = 0;
};

/**

* @brief A parsed document, and the root node it owns.
*
* Release() invalidates every node reached through it.
  */
class IToolkitJSONDocument
{
public:
    virtual ~IToolkitJSONDocument() = default;

    /// @brief Whether the text parsed. A failed parse still returns a document,
    ///        whose root reads as null, so a caller can skip the check.
    virtual bool IsValid() const = 0;

    /// @brief The parser's complaint, or an empty string when IsValid().
    virtual const char* GetError() const = 0;

    virtual const IToolkitJSONValue* Root() const = 0;

    /// @brief Frees the document and everything reached through it.
    virtual void Release() = 0;
};

#define TOOLKIT_JSON_INTERFACE "IToolkitJSON001"

class IToolkitJSON
{
public:
    virtual ~IToolkitJSON() = default;

    /**

    * @brief Parses text into a document the caller then owns.
    *
    * Never returns null: on a parse error the document reports IsValid() false
    * and its root reads as null, so walking it is safe without checking.
    *
    * @param pszText JSON text.
    * @param nLength Length, or -1 to read up to the terminator.
    * @return A document; call Release() on it when done.
      */
    virtual IToolkitJSONDocument* Parse(const char* pszText, int nLength = -1) = 0;
};

#endif //_INCLUDE_ITOOLKIT_JSON_H
