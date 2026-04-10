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

class RotatorHistoryEntry_t
{
public:
    DECLARE_SCHEMA_CLASS(RotatorHistoryEntry_t);

    SCHEMA_FIELD(Quaternion, qInvChange);
    SCHEMA_FIELD(float, flTimeRotationStart);
};
