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

class CNetworkOriginCellCoordQuantizedVector
{
public:
    DECLARE_SCHEMA_CLASS(CNetworkOriginCellCoordQuantizedVector);

    SCHEMA_FIELD(uint16_t, m_cellX);
    SCHEMA_FIELD(uint16_t, m_cellY);
    SCHEMA_FIELD(uint16_t, m_cellZ);
    SCHEMA_FIELD(uint16_t, m_nOutsideWorld);
    SCHEMA_FIELD(float, m_vecX);
    SCHEMA_FIELD(float, m_vecY);
    SCHEMA_FIELD(float, m_vecZ);
};
