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
#include "IToolkitTypes.h"

#include "convar.h"
#include "eiface.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

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

#endif //_INCLUDE_ITOOLKIT_CONVARS_H
