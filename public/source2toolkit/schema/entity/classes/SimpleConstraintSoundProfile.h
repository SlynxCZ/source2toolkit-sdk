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

class SimpleConstraintSoundProfile
{
public:
    DECLARE_SCHEMA_CLASS(SimpleConstraintSoundProfile);

    SCHEMA_FIELD(float, m_flKeyPointMinSoundThreshold);
    SCHEMA_FIELD(float, m_flKeyPointMaxSoundThreshold);
    SCHEMA_FIELD(float, m_reversalSoundThresholdSmall);
    SCHEMA_FIELD(float, m_reversalSoundThresholdMedium);
    SCHEMA_FIELD(float, m_reversalSoundThresholdLarge);
};
