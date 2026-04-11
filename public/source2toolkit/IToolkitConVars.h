//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz.
//

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

class IToolkitConVars
{
public:
    virtual ~IToolkitConVars() = default;

    virtual uint16 GetConvarAccessIndexByName(const char* name) = 0;
    virtual ConVarRefAbstract GetConvarRef(uint16 accessIndex) = 0;

    virtual const char* GetName(uint16 accessIndex) = 0;
    virtual const char* GetHelpText(uint16 accessIndex) = 0;

    virtual EConVarType GetType(uint16 accessIndex) = 0;

    virtual uint64 GetFlags(uint16 accessIndex) = 0;
    virtual void SetFlags(uint16 accessIndex, uint64 flags) = 0;

    virtual void* GetValueAddress(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;

    virtual const char* GetString(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;
    virtual void SetString(uint16 accessIndex, const char* value, CSplitScreenSlot slot = -1) = 0;

    virtual bool GetBool(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;
    virtual int32 GetInt(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;
    virtual float GetFloat(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;
    virtual double GetDouble(uint16 accessIndex, CSplitScreenSlot slot = -1) = 0;

    virtual void SetBool(uint16 accessIndex, bool value, CSplitScreenSlot slot = -1) = 0;
    virtual void SetInt(uint16 accessIndex, int32 value, CSplitScreenSlot slot = -1) = 0;
    virtual void SetFloat(uint16 accessIndex, float value, CSplitScreenSlot slot = -1) = 0;
    virtual void SetDouble(uint16 accessIndex, double value, CSplitScreenSlot slot = -1) = 0;

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

    virtual void GetValue(uint16 accessIndex, void* outValue, CSplitScreenSlot slot = -1) = 0;
    virtual void SetValue(uint16 accessIndex, const void* value, CSplitScreenSlot slot = -1) = 0;

    virtual uint16 CreateConVar(const char* name, EConVarType type, const char* help, uint64 flags, bool hasMin, bool hasMax, void* defaultValue, const void* minValue, const void* maxValue) = 0;
    virtual void DeleteConVar(uint16 accessIndex) = 0;
};

#endif //_INCLUDE_ITOOLKIT_CONVARS_H
