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

#include "CBaseEntity.h"
#include "InfoForResourceTypeIParticleSystemDefinition.h"

class CPathParticleRope : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPathParticleRope);

    SCHEMA_FIELD(bool, m_bStartActive);
    SCHEMA_FIELD(float, m_flMaxSimulationTime);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszEffectName);
    SCHEMA_FIELD(CUtlVector<CUtlSymbolLarge>, m_PathNodes_Name);
    SCHEMA_FIELD(float, m_flParticleSpacing);
    SCHEMA_FIELD(float, m_flSlack);
    SCHEMA_FIELD(float, m_flRadius);
    SCHEMA_FIELD(Color, m_ColorTint);
    SCHEMA_FIELD(int32_t, m_nEffectState);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIParticleSystemDefinition >, m_iEffectIndex);
    SCHEMA_FIELD(CUtlVector<Vector>, m_PathNodes_Position);
    SCHEMA_FIELD(CUtlVector<Vector>, m_PathNodes_TangentIn);
    SCHEMA_FIELD(CUtlVector<Vector>, m_PathNodes_TangentOut);
    SCHEMA_FIELD(CUtlVector<Vector>, m_PathNodes_Color);
    SCHEMA_FIELD(CUtlVector<bool>, m_PathNodes_PinEnabled);
    SCHEMA_FIELD(CUtlVector<float>, m_PathNodes_RadiusScale);

public:
    static CPathParticleRope* New(const char* className)
    {
        return CBaseEntity::New<CPathParticleRope>(className);
    }

    static CPathParticleRope* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPathParticleRope>(iIndex);
    }

    static CPathParticleRope* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
