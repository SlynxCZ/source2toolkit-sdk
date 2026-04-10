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

#include "../enums/RotatorTargetSpace_t.h"

class RotatorQueueEntry_t
{
public:
    DECLARE_SCHEMA_CLASS(RotatorQueueEntry_t);

    SCHEMA_FIELD(Quaternion, qTarget);
    SCHEMA_FIELD(RotatorTargetSpace_t, eSpace);
};
