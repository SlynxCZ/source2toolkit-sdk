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

class constraint_breakableparams_t
{
public:
    DECLARE_SCHEMA_CLASS(constraint_breakableparams_t);

    SCHEMA_FIELD(float, strength);
    SCHEMA_FIELD(float, forceLimit);
    SCHEMA_FIELD(float, torqueLimit);
    SCHEMA_FIELD_POINTER(float, bodyMassScale);
    SCHEMA_FIELD(bool, isActive);
};
