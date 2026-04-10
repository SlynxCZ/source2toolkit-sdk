#pragma once
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

#include "CPlayer_WeaponServices.h"

class CBasePlayerWeapon;

class CCSPlayer_WeaponServices : public CPlayer_WeaponServices
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayer_WeaponServices);

    SCHEMA_FIELD(float, m_flNextAttack);
    SCHEMA_FIELD(bool, m_bIsLookingAtWeapon);
    SCHEMA_FIELD(bool, m_bIsHoldingLookAtWeapon);
    SCHEMA_FIELD(CHandle<CBasePlayerWeapon>, m_hSavedWeapon);
    SCHEMA_FIELD(int32_t, m_nTimeToMelee);
    SCHEMA_FIELD(int32_t, m_nTimeToSecondary);
    SCHEMA_FIELD(int32_t, m_nTimeToPrimary);
    SCHEMA_FIELD(int32_t, m_nTimeToSniperRifle);
    SCHEMA_FIELD(bool, m_bIsBeingGivenItem);
    SCHEMA_FIELD(bool, m_bIsPickingUpItemWithUse);
    SCHEMA_FIELD(bool, m_bPickedUpWeapon);
    SCHEMA_FIELD(bool, m_bDisableAutoDeploy);
    SCHEMA_FIELD(bool, m_bIsPickingUpGroundWeapon);
    SCHEMA_FIELD(CUtlVector<uint8_t>, m_networkAnimTiming);
    SCHEMA_FIELD(bool, m_bBlockInspectUntilNextGraphUpdate);
};
