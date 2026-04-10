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

class CRagdollManager : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CRagdollManager);

    SCHEMA_FIELD(int8_t, m_iCurrentMaxRagdollCount);
    SCHEMA_FIELD(int32_t, m_iMaxRagdollCount);
    SCHEMA_FIELD(bool, m_bSaveImportant);
    SCHEMA_FIELD(bool, m_bCanTakeDamage);

public:
    static CRagdollManager* New(const char* className)
    {
        return CBaseEntity::New<CRagdollManager>(className);
    }

    static CRagdollManager* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRagdollManager>(iIndex);
    }

    static CRagdollManager* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
