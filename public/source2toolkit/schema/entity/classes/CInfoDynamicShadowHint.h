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

#include "CPointEntity.h"

class CBaseEntity;

class CInfoDynamicShadowHint : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoDynamicShadowHint);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(float, m_flRange);
    SCHEMA_FIELD(int32_t, m_nImportance);
    SCHEMA_FIELD(int32_t, m_nLightChoice);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hLight);

public:
    static CInfoDynamicShadowHint* New(const char* className)
    {
        return CBaseEntity::New<CInfoDynamicShadowHint>(className);
    }

    static CInfoDynamicShadowHint* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoDynamicShadowHint>(iIndex);
    }

    static CInfoDynamicShadowHint* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
