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

#include "CBreakableProp.h"
#include "../enums/CPhysicsPropCrateType_t.h"
#include "../enums/DynamicContinuousContactBehavior_t.h"

class CPhysicsProp : public CBreakableProp
{
public:
    DECLARE_SCHEMA_CLASS(CPhysicsProp);

    SCHEMA_FIELD(CEntityIOOutput, m_MotionEnabled);
    SCHEMA_FIELD(CEntityIOOutput, m_OnAwakened);
    SCHEMA_FIELD(CEntityIOOutput, m_OnAwake);
    SCHEMA_FIELD(CEntityIOOutput, m_OnAsleep);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPlayerUse);
    SCHEMA_FIELD(CEntityIOOutput, m_OnOutOfWorld);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPlayerPickup);
    SCHEMA_FIELD(bool, m_bForceNavIgnore);
    SCHEMA_FIELD(bool, m_bNoNavmeshBlocker);
    SCHEMA_FIELD(bool, m_bForceNpcExclude);
    SCHEMA_FIELD(float, m_massScale);
    SCHEMA_FIELD(float, m_buoyancyScale);
    SCHEMA_FIELD(int32_t, m_damageType);
    SCHEMA_FIELD(int32_t, m_damageToEnableMotion);
    SCHEMA_FIELD(float, m_flForceToEnableMotion);
    SCHEMA_FIELD(bool, m_bThrownByPlayer);
    SCHEMA_FIELD(bool, m_bDroppedByPlayer);
    SCHEMA_FIELD(bool, m_bTouchedByPlayer);
    SCHEMA_FIELD(bool, m_bFirstCollisionAfterLaunch);
    SCHEMA_FIELD(bool, m_bHasBeenAwakened);
    SCHEMA_FIELD(bool, m_bIsOverrideProp);
    SCHEMA_FIELD(float, m_flLastBurn);
    SCHEMA_FIELD(DynamicContinuousContactBehavior_t, m_nDynamicContinuousContactBehavior);
    SCHEMA_FIELD(float, m_fNextCheckDisableMotionContactsTime);
    SCHEMA_FIELD(int32_t, m_iInitialGlowState);
    SCHEMA_FIELD(int32_t, m_nGlowRange);
    SCHEMA_FIELD(int32_t, m_nGlowRangeMin);
    SCHEMA_FIELD(Color, m_glowColor);
    SCHEMA_FIELD(bool, m_bShouldAutoConvertBackFromDebris);
    SCHEMA_FIELD(bool, m_bMuteImpactEffects);
    SCHEMA_FIELD(bool, m_bUpdateNavWhenMoving);
    SCHEMA_FIELD(bool, m_bForceNavObstacleCut);
    SCHEMA_FIELD(bool, m_bAllowObstacleConvexHullMerging);
    SCHEMA_FIELD(bool, m_bAcceptDamageFromHeldObjects);
    SCHEMA_FIELD(bool, m_bEnableUseOutput);
    SCHEMA_FIELD(CPhysicsProp::CrateType_t, m_CrateType);
    SCHEMA_FIELD_POINTER(CUtlSymbolLarge, m_strItemClass);
    SCHEMA_FIELD_POINTER(int32_t, m_nItemCount);
    SCHEMA_FIELD(bool, m_bRemovableForAmmoBalancing);
    SCHEMA_FIELD(bool, m_bAwake);
    SCHEMA_FIELD(bool, m_bAttachedToReferenceFrame);

public:
    static CPhysicsProp* New(const char* className)
    {
        return CBaseEntity::New<CPhysicsProp>(className);
    }

    static CPhysicsProp* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysicsProp>(iIndex);
    }

    static CPhysicsProp* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
