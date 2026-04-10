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

class DestructibleHitGroupToDestroy_t
{
public:
    DECLARE_SCHEMA_CLASS(DestructibleHitGroupToDestroy_t);

    SCHEMA_FIELD(HitGroup_t, m_nHitGroup);
    SCHEMA_FIELD(int32_t, m_nMaxDamageLevel);
};
