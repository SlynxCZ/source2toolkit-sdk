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
#include "../enums/EntityDisolveType_t.h"

class CEntityDissolve : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEntityDissolve);

    SCHEMA_FIELD(float, m_flFadeInStart);
    SCHEMA_FIELD(float, m_flFadeInLength);
    SCHEMA_FIELD(float, m_flFadeOutModelStart);
    SCHEMA_FIELD(float, m_flFadeOutModelLength);
    SCHEMA_FIELD(float, m_flFadeOutStart);
    SCHEMA_FIELD(float, m_flFadeOutLength);
    SCHEMA_FIELD(float, m_flStartTime);
    SCHEMA_FIELD(EntityDisolveType_t, m_nDissolveType);
    SCHEMA_FIELD(Vector, m_vDissolverOrigin);
    SCHEMA_FIELD(uint32_t, m_nMagnitude);

public:
    static CEntityDissolve* New(const char* className)
    {
        return CBaseEntity::New<CEntityDissolve>(className);
    }

    static CEntityDissolve* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEntityDissolve>(iIndex);
    }

    static CEntityDissolve* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
