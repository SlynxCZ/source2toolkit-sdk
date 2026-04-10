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

#include "CAttributeList.h"
#include "IEconItemInterface.h"

class CEconItemView : public IEconItemInterface
{
public:
    DECLARE_SCHEMA_CLASS(CEconItemView);

    SCHEMA_FIELD(uint16_t, m_iItemDefinitionIndex);
    SCHEMA_FIELD(int32_t, m_iEntityQuality);
    SCHEMA_FIELD(uint32_t, m_iEntityLevel);
    SCHEMA_FIELD(uint64_t, m_iItemID);
    SCHEMA_FIELD(uint32_t, m_iItemIDHigh);
    SCHEMA_FIELD(uint32_t, m_iItemIDLow);
    SCHEMA_FIELD(uint32_t, m_iAccountID);
    SCHEMA_FIELD(uint32_t, m_iInventoryPosition);
    SCHEMA_FIELD(bool, m_bInitialized);
    SCHEMA_FIELD(CAttributeList, m_AttributeList);
    SCHEMA_FIELD(CAttributeList, m_NetworkedDynamicAttributes);
    SCHEMA_FIELD_POINTER(char, m_szCustomName);
    SCHEMA_FIELD_POINTER(char, m_szCustomNameOverride);
};
