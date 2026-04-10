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

class CIronSightController
{
public:
    DECLARE_SCHEMA_CLASS(CIronSightController);

    SCHEMA_FIELD(bool, m_bIronSightAvailable);
    SCHEMA_FIELD(float, m_flIronSightAmount);
    SCHEMA_FIELD(float, m_flIronSightAmountGained);
    SCHEMA_FIELD(float, m_flIronSightAmountBiased);
};
