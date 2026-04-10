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

class thinkfunc_t
{
public:
    DECLARE_SCHEMA_CLASS(thinkfunc_t);

    SCHEMA_FIELD_POINTER(CUtlStringToken, m_nContext);
    SCHEMA_FIELD(int32_t, m_nNextThinkTick);
    SCHEMA_FIELD(int32_t, m_nLastThinkTick);
};
