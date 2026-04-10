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

#include "ParticleIndex_t.h"

class CBaseEntity;

class lerpdata_t
{
public:
    DECLARE_SCHEMA_CLASS(lerpdata_t);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hEnt);
    SCHEMA_FIELD(MoveType_t, m_MoveType);
    SCHEMA_FIELD(float, m_flStartTime);
    SCHEMA_FIELD(Vector, m_vecStartOrigin);
    SCHEMA_FIELD(Quaternion, m_qStartRot);
    SCHEMA_FIELD(ParticleIndex_t, m_nFXIndex);
};
