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

#include "CAttributeContainer.h"
#include "CBaseFlex.h"

class CBaseEntity;

class CEconEntity : public CBaseFlex
{
public:
    DECLARE_SCHEMA_CLASS(CEconEntity);

    SCHEMA_FIELD(CAttributeContainer, m_AttributeManager);
    SCHEMA_FIELD(uint32_t, m_OriginalOwnerXuidLow);
    SCHEMA_FIELD(uint32_t, m_OriginalOwnerXuidHigh);
    SCHEMA_FIELD(int32_t, m_nFallbackPaintKit);
    SCHEMA_FIELD(int32_t, m_nFallbackSeed);
    SCHEMA_FIELD(float, m_flFallbackWear);
    SCHEMA_FIELD(int32_t, m_nFallbackStatTrak);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hOldProvidee);
    SCHEMA_FIELD(int32_t, m_iOldOwnerClass);

public:
    static CEconEntity* New(const char* className)
    {
        return CBaseEntity::New<CEconEntity>(className);
    }

    static CEconEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEconEntity>(iIndex);
    }

    static CEconEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
