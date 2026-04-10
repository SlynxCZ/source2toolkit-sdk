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

#include "CPlayer_WaterServices.h"

class CCSPlayer_WaterServices : public CPlayer_WaterServices
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayer_WaterServices);

    SCHEMA_FIELD(float, m_NextDrownDamageTime);
    SCHEMA_FIELD(int32_t, m_nDrownDmgRate);
    SCHEMA_FIELD(float, m_AirFinishedTime);
    SCHEMA_FIELD(float, m_flWaterJumpTime);
    SCHEMA_FIELD(Vector, m_vecWaterJumpVel);
    SCHEMA_FIELD(float, m_flSwimSoundTime);
};
