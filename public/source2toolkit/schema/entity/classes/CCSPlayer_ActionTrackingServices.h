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

#include "CPlayerPawnComponent.h"
#include "WeaponPurchaseTracker_t.h"

class CBasePlayerWeapon;

class CCSPlayer_ActionTrackingServices : public CPlayerPawnComponent
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayer_ActionTrackingServices);

    SCHEMA_FIELD(CHandle<CBasePlayerWeapon>, m_hLastWeaponBeforeC4AutoSwitch);
    SCHEMA_FIELD(bool, m_bIsRescuing);
    SCHEMA_FIELD(WeaponPurchaseTracker_t, m_weaponPurchasesThisMatch);
    SCHEMA_FIELD(WeaponPurchaseTracker_t, m_weaponPurchasesThisRound);
};
