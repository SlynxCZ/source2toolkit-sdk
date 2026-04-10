//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz.
//

#ifndef _INCLUDE_ITOOLKIT_ENTITYIO_H
#define _INCLUDE_ITOOLKIT_ENTITYIO_H

#pragma once
#include "IToolkitTypes.h"

#include "igameevents.h"
#include "eiface.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

/* =========================
   Forward declarations
   ========================= */

class CEntityInstance;
class CBaseEntity;
class CBasePlayerController;
class CCSGameRules;
class IEntityFindFilter;
class IEntityIOListener;

/* =========================
   Core Toolkit EntityIO
   ========================= */

class IToolkitEntityIO
{
public:
    virtual ~IToolkitEntityIO() = default;

    virtual CBaseEntity* FindPickerEntity(CBasePlayerController* pPlayer, CCSGameRules* pGameRules = nullptr) = 0;
    virtual CBaseEntity* FindEntityByClassname(CEntityInstance* pStart, const char* name) = 0;
    virtual CBaseEntity* FindEntityByName(CEntityInstance* pStartEntity, const char* szName, CEntityInstance* pSearchingEntity = nullptr, CEntityInstance* pActivator = nullptr, CEntityInstance* pCaller = nullptr, IEntityFindFilter* pFilter = nullptr) = 0;

    virtual CBaseEntity* CreateEntityByName(const char* pszClassName) = 0;

    virtual void AcceptInput(CEntityInstance* pTarget, const char* pszInput, CEntityInstance* pActivator, CEntityInstance* pCaller, const char* pszValue = "") = 0;
    virtual void AddEntityIOEvent(CEntityInstance* pTarget, const char* pszInput, CEntityInstance* pActivator = nullptr, CEntityInstance* pCaller = nullptr, const char* pszValue = "", float flDelay = 0.0f) = 0;

    virtual void AddEntityIOListener(IEntityIOListener* pListener, const char* pchClassName, const char* pchOutputName, Mode nMode = Mode::Pre) = 0;
    virtual void RemoveEntityIOListener(IEntityIOListener* pListener, const char* pchClassName, const char* pchOutputName, Mode nMode = Mode::Pre) = 0;
};

#endif //_INCLUDE_ITOOLKIT_ENTITYIO_H
