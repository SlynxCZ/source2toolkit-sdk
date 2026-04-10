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
#include "EntitySpottedState_t.h"

class CC4 : public CCSWeaponBase
{
public:
    DECLARE_SCHEMA_CLASS(CC4);

    SCHEMA_FIELD(Vector, m_vecLastValidPlayerHeldPosition);
    SCHEMA_FIELD(Vector, m_vecLastValidDroppedPosition);
    SCHEMA_FIELD(bool, m_bDoValidDroppedPositionCheck);
    SCHEMA_FIELD(bool, m_bStartedArming);
    SCHEMA_FIELD(float, m_fArmedTime);
    SCHEMA_FIELD(bool, m_bBombPlacedAnimation);
    SCHEMA_FIELD(bool, m_bIsPlantingViaUse);
    SCHEMA_FIELD(EntitySpottedState_t, m_entitySpottedState);
    SCHEMA_FIELD(int32_t, m_nSpotRules);
    SCHEMA_FIELD_POINTER(bool, m_bPlayedArmingBeeps);
    SCHEMA_FIELD(bool, m_bBombPlanted);

public:
    static CC4* New(const char* className)
    {
        return CBaseEntity::New<CC4>(className);
    }

    static CC4* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CC4>(iIndex);
    }

    static CC4* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
