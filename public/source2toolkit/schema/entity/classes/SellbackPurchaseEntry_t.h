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

class SellbackPurchaseEntry_t
{
public:
    DECLARE_SCHEMA_CLASS(SellbackPurchaseEntry_t);

    SCHEMA_FIELD(uint16_t, m_unDefIdx);
    SCHEMA_FIELD(int32_t, m_nCost);
    SCHEMA_FIELD(int32_t, m_nPrevArmor);
    SCHEMA_FIELD(bool, m_bPrevHelmet);
    SCHEMA_FIELD(CEntityHandle, m_hItem);
};
