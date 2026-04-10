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

class hudtextparms_t
{
public:
    DECLARE_SCHEMA_CLASS(hudtextparms_t);

    SCHEMA_FIELD(Color, color1);
    SCHEMA_FIELD(Color, color2);
    SCHEMA_FIELD(uint8_t, effect);
    SCHEMA_FIELD(uint8_t, channel);
    SCHEMA_FIELD(float, x);
    SCHEMA_FIELD(float, y);
};
