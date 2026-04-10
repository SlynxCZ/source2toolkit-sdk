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

class VPhysicsCollisionAttribute_t
{
public:
    DECLARE_SCHEMA_CLASS(VPhysicsCollisionAttribute_t);

    SCHEMA_FIELD(uint64_t, m_nInteractsAs);
    SCHEMA_FIELD(uint64_t, m_nInteractsWith);
    SCHEMA_FIELD(uint64_t, m_nInteractsExclude);
    SCHEMA_FIELD(uint32_t, m_nEntityId);
    SCHEMA_FIELD(uint32_t, m_nOwnerId);
    SCHEMA_FIELD(uint16_t, m_nHierarchyId);
    SCHEMA_FIELD(uint16_t, m_nDetailLayerMask);
    SCHEMA_FIELD(uint8_t, m_nDetailLayerMaskType);
    SCHEMA_FIELD(uint8_t, m_nTargetDetailLayer);
    SCHEMA_FIELD(uint8_t, m_nCollisionGroup);
    SCHEMA_FIELD(uint8_t, m_nCollisionFunctionMask);
};
