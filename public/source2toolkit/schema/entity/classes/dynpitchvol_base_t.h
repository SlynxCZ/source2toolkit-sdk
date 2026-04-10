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

class dynpitchvol_base_t
{
public:
    DECLARE_SCHEMA_CLASS(dynpitchvol_base_t);

    SCHEMA_FIELD(int32_t, preset);
    SCHEMA_FIELD(int32_t, pitchrun);
    SCHEMA_FIELD(int32_t, pitchstart);
    SCHEMA_FIELD(int32_t, spinup);
    SCHEMA_FIELD(int32_t, spindown);
    SCHEMA_FIELD(int32_t, volrun);
    SCHEMA_FIELD(int32_t, volstart);
    SCHEMA_FIELD(int32_t, fadein);
    SCHEMA_FIELD(int32_t, fadeout);
    SCHEMA_FIELD(int32_t, lfotype);
    SCHEMA_FIELD(int32_t, lforate);
    SCHEMA_FIELD(int32_t, lfomodpitch);
    SCHEMA_FIELD(int32_t, lfomodvol);
    SCHEMA_FIELD(int32_t, cspinup);
    SCHEMA_FIELD(int32_t, cspincount);
    SCHEMA_FIELD(int32_t, pitch);
    SCHEMA_FIELD(int32_t, spinupsav);
    SCHEMA_FIELD(int32_t, spindownsav);
    SCHEMA_FIELD(int32_t, pitchfrac);
    SCHEMA_FIELD(int32_t, vol);
    SCHEMA_FIELD(int32_t, fadeinsav);
    SCHEMA_FIELD(int32_t, fadeoutsav);
    SCHEMA_FIELD(int32_t, volfrac);
    SCHEMA_FIELD(int32_t, lfofrac);
    SCHEMA_FIELD(int32_t, lfomult);
};
