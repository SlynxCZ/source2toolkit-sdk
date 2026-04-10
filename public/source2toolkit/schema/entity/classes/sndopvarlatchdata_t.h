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

class sndopvarlatchdata_t
{
public:
    DECLARE_SCHEMA_CLASS(sndopvarlatchdata_t);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszStack);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszOperator);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszOpvar);
    SCHEMA_FIELD(float, m_flVal);
    SCHEMA_FIELD(Vector, m_vPos);
};
