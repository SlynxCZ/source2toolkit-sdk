#pragma once
#include "CBaseEntity.h"
#include "igameevents.h"
#include "ehandle.h"
#include "entityhandle.h"
#include "vector.h"
#include "utlsymbol.h"
#include "utlsymbollarge.h"
#include "utlstring.h"
#include "utlstringtoken.h"
#include "source2toolkit/IToolkitTypes.h"
#include "source2toolkit/schema/entityio.h"
#include "source2toolkit/schema/schema.h"
#include <cstdint>

#include "CDynamicProp.h"
#include "../enums/DoorState_t.h"
#include "locksound_t.h"

class CBaseEntity;

class CBasePropDoor : public CDynamicProp
{
public:
    DECLARE_SCHEMA_CLASS(CBasePropDoor);

    SCHEMA_FIELD(float, m_flAutoReturnDelay);
    SCHEMA_FIELD(CUtlVector<CHandle<CBasePropDoor>>, m_hDoorList);
    SCHEMA_FIELD(int32_t, m_nHardwareType);
    SCHEMA_FIELD(bool, m_bNeedsHardware);
    SCHEMA_FIELD(DoorState_t, m_eDoorState);
    SCHEMA_FIELD(bool, m_bLocked);
    SCHEMA_FIELD(bool, m_bNoNPCs);
    SCHEMA_FIELD(Vector, m_closedPosition);
    SCHEMA_FIELD(QAngle, m_closedAngles);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hBlocker);
    SCHEMA_FIELD(bool, m_bFirstBlocked);
    SCHEMA_FIELD(locksound_t, m_ls);
    SCHEMA_FIELD(bool, m_bForceClosed);
    SCHEMA_FIELD(Vector, m_vecLatchWorldPosition);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hActivator);
    SCHEMA_FIELD(CUtlSymbolLarge, m_SoundMoving);
    SCHEMA_FIELD(CUtlSymbolLarge, m_SoundOpen);
    SCHEMA_FIELD(CUtlSymbolLarge, m_SoundClose);
    SCHEMA_FIELD(CUtlSymbolLarge, m_SoundLock);
    SCHEMA_FIELD(CUtlSymbolLarge, m_SoundUnlock);
    SCHEMA_FIELD(CUtlSymbolLarge, m_SoundLatch);
    SCHEMA_FIELD(CUtlSymbolLarge, m_SoundPound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_SoundJiggle);
    SCHEMA_FIELD(CUtlSymbolLarge, m_SoundLockedAnim);
    SCHEMA_FIELD(int32_t, m_numCloseAttempts);
    SCHEMA_FIELD_POINTER(CUtlStringToken, m_nPhysicsMaterial);
    SCHEMA_FIELD(CUtlSymbolLarge, m_SlaveName);
    SCHEMA_FIELD(CHandle<CBasePropDoor>, m_hMaster);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBlockedClosing);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBlockedOpening);
    SCHEMA_FIELD(CEntityIOOutput, m_OnUnblockedClosing);
    SCHEMA_FIELD(CEntityIOOutput, m_OnUnblockedOpening);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFullyClosed);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFullyOpen);
    SCHEMA_FIELD(CEntityIOOutput, m_OnClose);
    SCHEMA_FIELD(CEntityIOOutput, m_OnOpen);
    SCHEMA_FIELD(CEntityIOOutput, m_OnLockedUse);
    SCHEMA_FIELD(CEntityIOOutput, m_OnAjarOpen);

public:
    static CBasePropDoor* New(const char* className)
    {
        return CBaseEntity::New<CBasePropDoor>(className);
    }

    static CBasePropDoor* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBasePropDoor>(iIndex);
    }

    static CBasePropDoor* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
