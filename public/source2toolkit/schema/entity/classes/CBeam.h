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

#include "../enums/BeamClipStyle_t.h"
#include "../enums/BeamType_t.h"
#include "CBaseModelEntity.h"
#include "InfoForResourceTypeIMaterial2.h"

class CBaseEntity;

class CBeam : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CBeam);

    SCHEMA_FIELD(float, m_flFrameRate);
    SCHEMA_FIELD(float, m_flHDRColorScale);
    SCHEMA_FIELD(float, m_flFireTime);
    SCHEMA_FIELD(float, m_flDamage);
    SCHEMA_FIELD(uint8_t, m_nNumBeamEnts);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIMaterial2 >, m_hBaseMaterial);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIMaterial2 >, m_nHaloIndex);
    SCHEMA_FIELD(BeamType_t, m_nBeamType);
    SCHEMA_FIELD(uint32_t, m_nBeamFlags);
    SCHEMA_FIELD_POINTER(CHandle<CBaseEntity>, m_hAttachEntity);
    SCHEMA_FIELD(float, m_fWidth);
    SCHEMA_FIELD(float, m_fEndWidth);
    SCHEMA_FIELD(float, m_fFadeLength);
    SCHEMA_FIELD(float, m_fHaloScale);
    SCHEMA_FIELD(float, m_fAmplitude);
    SCHEMA_FIELD(float, m_fStartFrame);
    SCHEMA_FIELD(float, m_fSpeed);
    SCHEMA_FIELD(float, m_flFrame);
    SCHEMA_FIELD(BeamClipStyle_t, m_nClipStyle);
    SCHEMA_FIELD(bool, m_bTurnedOff);
    SCHEMA_FIELD(Vector, m_vecEndPos);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hEndEntity);
    SCHEMA_FIELD(int32_t, m_nDissolveType);

public:
    static CBeam* New(const char* className)
    {
        return CBaseEntity::New<CBeam>(className);
    }

    static CBeam* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBeam>(iIndex);
    }

    static CBeam* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
