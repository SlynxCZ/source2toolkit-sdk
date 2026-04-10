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

class locksound_t
{
public:
    DECLARE_SCHEMA_CLASS(locksound_t);

    SCHEMA_FIELD(CUtlSymbolLarge, sLockedSound);
    SCHEMA_FIELD(CUtlSymbolLarge, sUnlockedSound);
    SCHEMA_FIELD(float, flwaitSound);
};
