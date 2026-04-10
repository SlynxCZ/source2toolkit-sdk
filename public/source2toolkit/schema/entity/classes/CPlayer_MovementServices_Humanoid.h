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

#include "CPlayer_MovementServices.h"

class CPlayer_MovementServices_Humanoid : public CPlayer_MovementServices
{
public:
    DECLARE_SCHEMA_CLASS(CPlayer_MovementServices_Humanoid);

    SCHEMA_FIELD(float, m_flStepSoundTime);
    SCHEMA_FIELD(float, m_flFallVelocity);
    SCHEMA_FIELD(Vector, m_groundNormal);
    SCHEMA_FIELD(float, m_flSurfaceFriction);
    SCHEMA_FIELD_POINTER(CUtlStringToken, m_surfaceProps);
    SCHEMA_FIELD(int32_t, m_nStepside);
    SCHEMA_FIELD(Vector, m_vecSmoothedVelocity);
};
