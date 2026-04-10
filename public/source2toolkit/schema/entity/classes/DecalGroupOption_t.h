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

#include "InfoForResourceTypeIMaterial2.h"

class DecalGroupOption_t
{
public:
    DECLARE_SCHEMA_CLASS(DecalGroupOption_t);

    SCHEMA_FIELD(CStrongHandleCopyable< InfoForResourceTypeIMaterial2 >, m_hMaterial);
    SCHEMA_FIELD(CGlobalSymbol, m_sSequenceName);
    SCHEMA_FIELD(float, m_flProbability);
    SCHEMA_FIELD(bool, m_bEnableAngleBetweenNormalAndGravityRange);
    SCHEMA_FIELD(float, m_flMinAngleBetweenNormalAndGravity);
    SCHEMA_FIELD(float, m_flMaxAngleBetweenNormalAndGravity);
};
