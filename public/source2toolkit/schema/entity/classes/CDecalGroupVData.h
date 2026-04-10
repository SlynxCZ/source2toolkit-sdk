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

#include "DecalGroupOption_t.h"

class CDecalGroupVData
{
public:
    DECLARE_SCHEMA_CLASS(CDecalGroupVData);

    SCHEMA_FIELD(CUtlVector<DecalGroupOption_t>, m_vecOptions);
    SCHEMA_FIELD(float, m_flTotalProbability);
};
