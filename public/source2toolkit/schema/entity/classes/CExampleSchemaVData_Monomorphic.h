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

class CExampleSchemaVData_Monomorphic
{
public:
    DECLARE_SCHEMA_CLASS(CExampleSchemaVData_Monomorphic);

    SCHEMA_FIELD(int32_t, m_nExample1);
    SCHEMA_FIELD(int32_t, m_nExample2);
};
