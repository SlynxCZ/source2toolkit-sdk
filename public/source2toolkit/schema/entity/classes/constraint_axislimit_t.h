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

class constraint_axislimit_t
{
public:
    DECLARE_SCHEMA_CLASS(constraint_axislimit_t);

    SCHEMA_FIELD(float, flMinRotation);
    SCHEMA_FIELD(float, flMaxRotation);
    SCHEMA_FIELD(float, flMotorTargetAngSpeed);
    SCHEMA_FIELD(float, flMotorMaxTorque);
};
