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

#include "CBreakable.h"
#include "../enums/HoverPoseFlags_t.h"

class CBasePlayerPawn;

class CPhysBox : public CBreakable
{
public:
    DECLARE_SCHEMA_CLASS(CPhysBox);

    SCHEMA_FIELD(int32_t, m_damageType);
    SCHEMA_FIELD(int32_t, m_damageToEnableMotion);
    SCHEMA_FIELD(float, m_flForceToEnableMotion);
    SCHEMA_FIELD(Vector, m_vHoverPosePosition);
    SCHEMA_FIELD(QAngle, m_angHoverPoseAngles);
    SCHEMA_FIELD(bool, m_bNotSolidToWorld);
    SCHEMA_FIELD(bool, m_bEnableUseOutput);
    SCHEMA_FIELD(HoverPoseFlags_t, m_nHoverPoseFlags);
    SCHEMA_FIELD(float, m_flTouchOutputPerEntityDelay);
    SCHEMA_FIELD(CEntityIOOutput, m_OnDamaged);
    SCHEMA_FIELD(CEntityIOOutput, m_OnAwakened);
    SCHEMA_FIELD(CEntityIOOutput, m_OnMotionEnabled);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPlayerUse);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStartTouch);
    SCHEMA_FIELD(CHandle<CBasePlayerPawn>, m_hCarryingPlayer);

public:
    static CPhysBox* New(const char* className)
    {
        return CBaseEntity::New<CPhysBox>(className);
    }

    static CPhysBox* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysBox>(iIndex);
    }

    static CPhysBox* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
