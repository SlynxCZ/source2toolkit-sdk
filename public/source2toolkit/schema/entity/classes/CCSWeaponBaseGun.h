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

class CCSWeaponBaseGun : public CCSWeaponBase
{
public:
    DECLARE_SCHEMA_CLASS(CCSWeaponBaseGun);

    SCHEMA_FIELD(int32_t, m_zoomLevel);
    SCHEMA_FIELD(int32_t, m_iBurstShotsRemaining);
    SCHEMA_FIELD(int32_t, m_silencedModelIndex);
    SCHEMA_FIELD(bool, m_inPrecache);
    SCHEMA_FIELD(bool, m_bNeedsBoltAction);
    SCHEMA_FIELD(int32_t, m_nRevolverCylinderIdx);
    SCHEMA_FIELD(bool, m_bSkillReloadAvailable);
    SCHEMA_FIELD(bool, m_bSkillReloadLiftedReloadKey);
    SCHEMA_FIELD(bool, m_bSkillBoltInterruptAvailable);
    SCHEMA_FIELD(bool, m_bSkillBoltLiftedFireKey);

public:
    static CCSWeaponBaseGun* New(const char* className)
    {
        return CBaseEntity::New<CCSWeaponBaseGun>(className);
    }

    static CCSWeaponBaseGun* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSWeaponBaseGun>(iIndex);
    }

    static CCSWeaponBaseGun* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
