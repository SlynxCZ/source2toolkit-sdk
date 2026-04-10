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

#include "CBaseModelEntity.h"

class CFuncRotating : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncRotating);

    SCHEMA_FIELD(CEntityIOOutput, m_OnStopped);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStarted);
    SCHEMA_FIELD(CEntityIOOutput, m_OnReachedStart);
    SCHEMA_FIELD(RotationVector, m_localRotationVector);
    SCHEMA_FIELD(float, m_flFanFriction);
    SCHEMA_FIELD(float, m_flAttenuation);
    SCHEMA_FIELD(float, m_flVolume);
    SCHEMA_FIELD(float, m_flTargetSpeed);
    SCHEMA_FIELD(float, m_flMaxSpeed);
    SCHEMA_FIELD(float, m_flBlockDamage);
    SCHEMA_FIELD(CUtlSymbolLarge, m_NoiseRunning);
    SCHEMA_FIELD(bool, m_bReversed);
    SCHEMA_FIELD(bool, m_bAccelDecel);
    SCHEMA_FIELD(QAngle, m_prevLocalAngles);
    SCHEMA_FIELD(QAngle, m_angStart);
    SCHEMA_FIELD(bool, m_bStopAtStartPos);
    SCHEMA_FIELD(Vector, m_vecClientOrigin);
    SCHEMA_FIELD(QAngle, m_vecClientAngles);

public:
    static CFuncRotating* New(const char* className)
    {
        return CBaseEntity::New<CFuncRotating>(className);
    }

    static CFuncRotating* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncRotating>(iIndex);
    }

    static CFuncRotating* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
