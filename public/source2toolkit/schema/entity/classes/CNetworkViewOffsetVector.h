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

class CNetworkViewOffsetVector
{
public:
    DECLARE_SCHEMA_CLASS(CNetworkViewOffsetVector);

    SCHEMA_FIELD(float, m_vecX);
    SCHEMA_FIELD(float, m_vecY);
    SCHEMA_FIELD(float, m_vecZ);
};
