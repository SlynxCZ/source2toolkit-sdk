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

class PredictedDamageTag_t
{
public:
    DECLARE_SCHEMA_CLASS(PredictedDamageTag_t);

    SCHEMA_FIELD(int32_t, nTagTick);
    SCHEMA_FIELD(float, flFlinchModSmall);
    SCHEMA_FIELD(float, flFlinchModLarge);
    SCHEMA_FIELD(float, flFriendlyFireDamageReductionRatio);
};
