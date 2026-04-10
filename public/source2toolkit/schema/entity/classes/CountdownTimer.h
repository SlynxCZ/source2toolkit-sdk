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

class CountdownTimer
{
public:
    DECLARE_SCHEMA_CLASS(CountdownTimer);

    SCHEMA_FIELD(float, m_duration);
    SCHEMA_FIELD(float, m_timestamp);
    SCHEMA_FIELD(float, m_timescale);
    SCHEMA_FIELD(WorldGroupId_t, m_nWorldGroupId);
};
