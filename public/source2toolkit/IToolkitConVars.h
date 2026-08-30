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

* @file IToolkitConVars.h
* @brief Interface for managing and interacting with console variables (ConVars).
*
* Provides functionality for:
* * Querying ConVars by name
* * Reading and writing values
* * Accessing metadata (type, flags, help text)
* * Creating and deleting ConVars
*
* @note ConVars are identified by an internal access index.
  */

#ifndef _INCLUDE_ITOOLKIT_CONVARS_H
#define _INCLUDE_ITOOLKIT_CONVARS_H

#pragma once
#include "IToolkitPlugin.h"

#include "convar.h"
#include "eiface.h"

/* =========================
Forward declarations
========================= */

class ConVarRefAbstract;

/* =========================
Core Toolkit ConVars
========================= */

/**

* @brief Interface for interacting with engine ConVars.
  */
/**
 * @brief Callback type for ConVar value changes.
 *
 * @param ref The ConVar that changed
 * @param slot Split-screen slot the change applies to
 * @param pszNewValue Value being set
 * @param pszOldValue Value being replaced
 */
using ConVarChangeHandler = std::function<void(ConVarRefAbstract* ref, CSplitScreenSlot slot,
                                               const char* pszNewValue, const char* pszOldValue)>;

#define TOOLKIT_CONVARS_INTERFACE "IToolkitConVars001"

class IToolkitConVars
{
public:
    virtual ~IToolkitConVars() = default;

    /**

    * @brief Retrieves access index of a ConVar by name.
    *
    * @param name ConVar name
    * @return Access index
      */
    virtual uint16 GetConvarAccessIndexByName(const char* name) = 0;

    /**

    * @brief Gets a ConVar reference wrapper.
      */
    virtual ConVarRefAbstract GetConvarRef(uint16 accessIndex) = 0;

    /**

    * @brief Gets ConVar name.
      */
    virtual const char* GetName(uint16 accessIndex) = 0;

    /**

    * @brief Gets help/description text.
      */
    virtual const char* GetHelpText(uint16 accessIndex) = 0;

    /**

    * @brief Gets ConVar type.
      */
    virtual EConVarType GetType(uint16 accessIndex) = 0;

    /**

    * @brief Gets flags (FCVAR_*).
      */
    virtual uint64 GetFlags(uint16 accessIndex) = 0;

    /**

    * @brief Sets flags (FCVAR_*).
      */
    virtual void SetFlags(uint16 accessIndex, uint64 flags) = 0;

    /**

    * @brief Gets pointer to underlying value.
    *
    * @note Type depends on ConVar type.
      */
    virtual void* GetValueAddress(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;

    /* =========================
    Typed getters
    ========================= */

    virtual const char* GetString(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;
    virtual bool GetBool(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;
    virtual int32 GetInt(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;
    virtual float GetFloat(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;
    virtual double GetDouble(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;

    /* =========================
    Typed setters
    ========================= */

    virtual void SetString(uint16 accessIndex, const char* value, CSplitScreenSlot slot = -1) = 0;
    virtual void SetBool(uint16 accessIndex, bool value, CSplitScreenSlot slot = -1) = 0;
    virtual void SetInt(uint16 accessIndex, int32 value, CSplitScreenSlot slot = -1) = 0;
    virtual void SetFloat(uint16 accessIndex, float value, CSplitScreenSlot slot = -1) = 0;
    virtual void SetDouble(uint16 accessIndex, double value, CSplitScreenSlot slot = -1) = 0;

    /* =========================
    Complex types
    ========================= */

    virtual Vector2D GetVector2(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;
    virtual Vector GetVector3(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;
    virtual Vector4D GetVector4(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;
    virtual QAngle GetQAngle(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;
    virtual Color GetColor(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;

    virtual void SetVector2(uint16 accessIndex, const Vector2D& value, CSplitScreenSlot slot = -1) = 0;
    virtual void SetVector3(uint16 accessIndex, const Vector& value, CSplitScreenSlot slot = -1) = 0;
    virtual void SetVector4(uint16 accessIndex, const Vector4D& value, CSplitScreenSlot slot = -1) = 0;
    virtual void SetQAngle(uint16 accessIndex, const QAngle& value, CSplitScreenSlot slot = -1) = 0;
    virtual void SetColor(uint16 accessIndex, const Color& value, CSplitScreenSlot slot = -1) = 0;

    /* =========================
    Generic access
    ========================= */

    /**

    * @brief Gets value into user-provided buffer.
      */
    virtual void GetValue(uint16 accessIndex, void* outValue, CSplitScreenSlot slot = -1) = 0;

    /* =========================
    Change callbacks
    ========================= */

    /**
     * @brief Registers a listener for every ConVar value change.
     *
     * The engine only takes plain function pointers here, and only keeps one
     * list of them for the whole process. The toolkit installs a single one of
     * those and fans out to the handlers registered through this, so a plugin
     * can use a capturing lambda and does not have to unregister on unload.
     *
     * @param owner Plugin ID that owns the listener
     * @param handler Callback function
     */
    virtual void HookConVarChange(PluginId owner, ConVarChangeHandler handler) = 0;

    /**
     * @brief Drops every change listener a plugin registered.
     *
     * Done for you when the plugin unloads; call it only to stop listening
     * earlier than that.
     *
     * @param owner Plugin ID whose listeners to drop
     */
    virtual void UnhookConVarChange(PluginId owner) = 0;

    /**

    * @brief Sets value from user-provided buffer.
      */
    virtual void SetValue(uint16 accessIndex, const void* value, CSplitScreenSlot slot = -1) = 0;

    /* =========================
    Creation / destruction
    ========================= */

    /**

    * @brief Creates a new ConVar.
    *
    * @param name ConVar name
    * @param type Variable type
    * @param help Description text
    * @param flags FCVAR flags
    * @param hasMin Whether min value is enforced
    * @param hasMax Whether max value is enforced
    * @param defaultValue Default value pointer
    * @param minValue Minimum value pointer
    * @param maxValue Maximum value pointer
    *
    * @return Access index of created ConVar
      */
    virtual uint16 CreateConVar(const char* name, EConVarType type, const char* help, uint64 flags, bool hasMin,
                                bool hasMax, void* defaultValue, const void* minValue, const void* maxValue) = 0;

    /**

    * @brief Deletes a ConVar.
      */
    virtual void DeleteConVar(uint16 accessIndex) = 0;
};

#define CVAR_IDX(name)                  g_pToolkitConVars->GetConvarAccessIndexByName(name)
#define CVAR_REF(idx)                   g_pToolkitConVars->GetConvarRef(idx)
#define CVAR_GET_STR(idx, ...)          g_pToolkitConVars->GetString(idx, ##__VA_ARGS__)
#define CVAR_GET_BOOL(idx, ...)         g_pToolkitConVars->GetBool(idx, ##__VA_ARGS__)
#define CVAR_GET_INT(idx, ...)          g_pToolkitConVars->GetInt(idx, ##__VA_ARGS__)
#define CVAR_GET_FLOAT(idx, ...)        g_pToolkitConVars->GetFloat(idx, ##__VA_ARGS__)
#define CVAR_GET_DOUBLE(idx, ...)       g_pToolkitConVars->GetDouble(idx, ##__VA_ARGS__)
#define CVAR_SET_STR(idx, v, ...)       g_pToolkitConVars->SetString(idx, v, ##__VA_ARGS__)
#define CVAR_SET_BOOL(idx, v, ...)      g_pToolkitConVars->SetBool(idx, v, ##__VA_ARGS__)
#define CVAR_SET_INT(idx, v, ...)       g_pToolkitConVars->SetInt(idx, v, ##__VA_ARGS__)
#define CVAR_SET_FLOAT(idx, v, ...)     g_pToolkitConVars->SetFloat(idx, v, ##__VA_ARGS__)
#define CVAR_SET_DOUBLE(idx, v, ...)    g_pToolkitConVars->SetDouble(idx, v, ##__VA_ARGS__)
#define CVAR_CREATE(name, type, help, flags, hasMin, hasMax, def, minVal, maxVal) \
    g_pToolkitConVars->CreateConVar(name, type, help, flags, hasMin, hasMax, def, minVal, maxVal)
#define CVAR_DELETE(idx)                g_pToolkitConVars->DeleteConVar(idx)

/**
 * @brief Macro for listening to ConVar value changes.
 *
 * @param passfunc Callback function.
 */
#define HOOK_CONVAR_CHANGE(passfunc) \
    g_pToolkitConVars->HookConVarChange(g_PluginID, passfunc)

#endif //_INCLUDE_ITOOLKIT_CONVARS_H
