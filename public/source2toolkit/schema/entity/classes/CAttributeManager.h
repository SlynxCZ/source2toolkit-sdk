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

#include "../enums/attributeprovidertypes_t.h"

class CBaseEntity;

class CAttributeManager
{
public:
    DECLARE_SCHEMA_CLASS(CAttributeManager);

    SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_Providers);
    SCHEMA_FIELD(int32_t, m_iReapplyProvisionParity);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hOuter);
    SCHEMA_FIELD(bool, m_bPreventLoopback);
    SCHEMA_FIELD(attributeprovidertypes_t, m_ProviderType);
};
