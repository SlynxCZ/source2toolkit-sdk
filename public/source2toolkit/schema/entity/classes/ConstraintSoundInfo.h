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

#include "SimpleConstraintSoundProfile.h"
#include "VelocitySampler.h"

class ConstraintSoundInfo
{
public:
    DECLARE_SCHEMA_CLASS(ConstraintSoundInfo);

    SCHEMA_FIELD(VelocitySampler, m_vSampler);
    SCHEMA_FIELD(SimpleConstraintSoundProfile, m_soundProfile);
    SCHEMA_FIELD(Vector, m_forwardAxis);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszTravelSoundFwd);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszTravelSoundBack);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszReversalSoundSmall);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszReversalSoundMedium);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszReversalSoundLarge);
    SCHEMA_FIELD(bool, m_bPlayTravelSound);
    SCHEMA_FIELD(bool, m_bPlayReversalSound);
};
