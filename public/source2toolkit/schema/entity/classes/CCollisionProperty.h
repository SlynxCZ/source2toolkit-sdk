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

#include "../enums/SurroundingBoundsType_t.h"
#include "VPhysicsCollisionAttribute_t.h"

class CCollisionProperty
{
public:
    DECLARE_SCHEMA_CLASS(CCollisionProperty);

    SCHEMA_FIELD(VPhysicsCollisionAttribute_t, m_collisionAttribute);
    SCHEMA_FIELD(Vector, m_vecMins);
    SCHEMA_FIELD(Vector, m_vecMaxs);
    SCHEMA_FIELD(uint8_t, m_usSolidFlags);
    SCHEMA_FIELD(SolidType_t, m_nSolidType);
    SCHEMA_FIELD(uint8_t, m_triggerBloat);
    SCHEMA_FIELD(SurroundingBoundsType_t, m_nSurroundType);
    SCHEMA_FIELD(uint8_t, m_CollisionGroup);
    SCHEMA_FIELD(uint8_t, m_nEnablePhysics);
    SCHEMA_FIELD(float, m_flBoundingRadius);
    SCHEMA_FIELD(Vector, m_vecSpecifiedSurroundingMins);
    SCHEMA_FIELD(Vector, m_vecSpecifiedSurroundingMaxs);
    SCHEMA_FIELD(Vector, m_vecSurroundingMaxs);
    SCHEMA_FIELD(Vector, m_vecSurroundingMins);
    SCHEMA_FIELD(Vector, m_vCapsuleCenter1);
    SCHEMA_FIELD(Vector, m_vCapsuleCenter2);
    SCHEMA_FIELD(float, m_flCapsuleRadius);
};
