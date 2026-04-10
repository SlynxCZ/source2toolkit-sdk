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

#include "CBaseToggle.h"
#include "../enums/FuncDoorSpawnPos_t.h"
#include "locksound_t.h"

class CBaseDoor : public CBaseToggle
{
public:
    DECLARE_SCHEMA_CLASS(CBaseDoor);

    SCHEMA_FIELD(QAngle, m_angMoveEntitySpace);
    SCHEMA_FIELD(Vector, m_vecMoveDirParentSpace);
    SCHEMA_FIELD(locksound_t, m_ls);
    SCHEMA_FIELD(bool, m_bForceClosed);
    SCHEMA_FIELD(bool, m_bDoorGroup);
    SCHEMA_FIELD(bool, m_bLocked);
    SCHEMA_FIELD(bool, m_bIgnoreDebris);
    SCHEMA_FIELD(bool, m_bNoNPCs);
    SCHEMA_FIELD(FuncDoorSpawnPos_t, m_eSpawnPosition);
    SCHEMA_FIELD(float, m_flBlockDamage);
    SCHEMA_FIELD(CUtlSymbolLarge, m_NoiseMoving);
    SCHEMA_FIELD(CUtlSymbolLarge, m_NoiseArrived);
    SCHEMA_FIELD(CUtlSymbolLarge, m_NoiseMovingClosed);
    SCHEMA_FIELD(CUtlSymbolLarge, m_NoiseArrivedClosed);
    SCHEMA_FIELD(CUtlSymbolLarge, m_ChainTarget);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBlockedClosing);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBlockedOpening);
    SCHEMA_FIELD(CEntityIOOutput, m_OnUnblockedClosing);
    SCHEMA_FIELD(CEntityIOOutput, m_OnUnblockedOpening);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFullyClosed);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFullyOpen);
    SCHEMA_FIELD(CEntityIOOutput, m_OnClose);
    SCHEMA_FIELD(CEntityIOOutput, m_OnOpen);
    SCHEMA_FIELD(CEntityIOOutput, m_OnLockedUse);
    SCHEMA_FIELD(bool, m_bLoopMoveSound);
    SCHEMA_FIELD(bool, m_bCreateNavObstacle);
    SCHEMA_FIELD(bool, m_isChaining);
    SCHEMA_FIELD(bool, m_bIsUsable);

public:
    static CBaseDoor* New(const char* className)
    {
        return CBaseEntity::New<CBaseDoor>(className);
    }

    static CBaseDoor* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseDoor>(iIndex);
    }

    static CBaseDoor* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
