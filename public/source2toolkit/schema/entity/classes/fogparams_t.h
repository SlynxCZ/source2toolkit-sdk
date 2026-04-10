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

class fogparams_t
{
public:
    DECLARE_SCHEMA_CLASS(fogparams_t);

    SCHEMA_FIELD(Vector, dirPrimary);
    SCHEMA_FIELD(Color, colorPrimary);
    SCHEMA_FIELD(Color, colorSecondary);
    SCHEMA_FIELD(Color, colorPrimaryLerpTo);
    SCHEMA_FIELD(Color, colorSecondaryLerpTo);
    SCHEMA_FIELD(float, start);
    SCHEMA_FIELD(float, end);
    SCHEMA_FIELD(float, farz);
    SCHEMA_FIELD(float, maxdensity);
    SCHEMA_FIELD(float, exponent);
    SCHEMA_FIELD(float, HDRColorScale);
    SCHEMA_FIELD(float, skyboxFogFactor);
    SCHEMA_FIELD(float, skyboxFogFactorLerpTo);
    SCHEMA_FIELD(float, startLerpTo);
    SCHEMA_FIELD(float, endLerpTo);
    SCHEMA_FIELD(float, maxdensityLerpTo);
    SCHEMA_FIELD(float, lerptime);
    SCHEMA_FIELD(float, duration);
    SCHEMA_FIELD(float, blendtobackground);
    SCHEMA_FIELD(float, scattering);
    SCHEMA_FIELD(float, locallightscale);
    SCHEMA_FIELD(bool, enable);
    SCHEMA_FIELD(bool, blend);
    SCHEMA_FIELD(bool, m_bPadding2);
    SCHEMA_FIELD(bool, m_bPadding);
};
