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

class audioparams_t
{
public:
    DECLARE_SCHEMA_CLASS(audioparams_t);

    SCHEMA_FIELD_POINTER(Vector, localSound);
    SCHEMA_FIELD(int32_t, soundscapeIndex);
    SCHEMA_FIELD(uint8_t, localBits);
    SCHEMA_FIELD(int32_t, soundscapeEntityListIndex);
    SCHEMA_FIELD(uint32_t, soundEventHash);
};
