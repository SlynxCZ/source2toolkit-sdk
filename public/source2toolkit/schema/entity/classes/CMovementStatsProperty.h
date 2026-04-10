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

#include "CVectorExponentialMovingAverage.h"

class CMovementStatsProperty
{
public:
    DECLARE_SCHEMA_CLASS(CMovementStatsProperty);

    SCHEMA_FIELD(int32_t, m_nUseCounter);
    SCHEMA_FIELD(CVectorExponentialMovingAverage, m_emaMovementDirection);
};
