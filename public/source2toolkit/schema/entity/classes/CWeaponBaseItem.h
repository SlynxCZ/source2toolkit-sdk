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

class CWeaponBaseItem : public CCSWeaponBase
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponBaseItem);

    SCHEMA_FIELD(bool, m_bSequenceInProgress);
    SCHEMA_FIELD(bool, m_bRedraw);

public:
    static CWeaponBaseItem* New(const char* className)
    {
        return CBaseEntity::New<CWeaponBaseItem>(className);
    }

    static CWeaponBaseItem* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponBaseItem>(iIndex);
    }

    static CWeaponBaseItem* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
