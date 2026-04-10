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

#include "CCSWeaponBase.h"

class CKnife : public CCSWeaponBase
{
public:
    DECLARE_SCHEMA_CLASS(CKnife);

    SCHEMA_FIELD(bool, m_bFirstAttack);

public:
    static CKnife* New(const char* className)
    {
        return CBaseEntity::New<CKnife>(className);
    }

    static CKnife* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CKnife>(iIndex);
    }

    static CKnife* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
