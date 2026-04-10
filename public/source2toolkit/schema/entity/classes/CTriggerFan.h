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

#include "CBaseTrigger.h"
#include "CountdownTimer.h"

class CInfoFan;

class CTriggerFan : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerFan);

    SCHEMA_FIELD(Vector, m_vFanOriginOffset);
    SCHEMA_FIELD(Vector, m_vDirection);
    SCHEMA_FIELD(bool, m_bPushTowardsInfoTarget);
    SCHEMA_FIELD(bool, m_bPushAwayFromInfoTarget);
    SCHEMA_FIELD(Quaternion, m_qNoiseDelta);
    SCHEMA_FIELD(CHandle<CInfoFan>, m_hInfoFan);
    SCHEMA_FIELD(float, m_flForce);
    SCHEMA_FIELD(bool, m_bFalloff);
    SCHEMA_FIELD(CountdownTimer, m_RampTimer);
    SCHEMA_FIELD(Vector, m_vFanOriginWS);
    SCHEMA_FIELD(Vector, m_vFanOriginLS);
    SCHEMA_FIELD(Vector, m_vFanEndLS);
    SCHEMA_FIELD(Vector, m_vNoiseDirectionTarget);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszInfoFan);
    SCHEMA_FIELD(float, m_flRopeForceScale);
    SCHEMA_FIELD(float, m_flParticleForceScale);
    SCHEMA_FIELD(float, m_flPlayerForce);
    SCHEMA_FIELD(bool, m_bPlayerWindblock);
    SCHEMA_FIELD(float, m_flNPCForce);
    SCHEMA_FIELD(float, m_flRampTime);
    SCHEMA_FIELD(float, m_fNoiseDegrees);
    SCHEMA_FIELD(float, m_fNoiseSpeed);
    SCHEMA_FIELD(bool, m_bPushPlayer);
    SCHEMA_FIELD(bool, m_bRampDown);
    SCHEMA_FIELD(int32_t, m_nManagerFanIdx);

public:
    static CTriggerFan* New(const char* className)
    {
        return CBaseEntity::New<CTriggerFan>(className);
    }

    static CTriggerFan* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerFan>(iIndex);
    }

    static CTriggerFan* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
