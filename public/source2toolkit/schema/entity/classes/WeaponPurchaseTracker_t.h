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

#include "WeaponPurchaseCount_t.h"

class WeaponPurchaseTracker_t
{
public:
    DECLARE_SCHEMA_CLASS(WeaponPurchaseTracker_t);

    SCHEMA_FIELD(CUtlVector<WeaponPurchaseCount_t>, m_weaponPurchases);
};
