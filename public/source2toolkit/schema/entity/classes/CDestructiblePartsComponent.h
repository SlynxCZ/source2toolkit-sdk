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


class CBaseModelEntity;

class CDestructiblePartsComponent
{
public:
    DECLARE_SCHEMA_CLASS(CDestructiblePartsComponent);

    SCHEMA_FIELD(CEntityInstance*, __m_pChainEntity);
    SCHEMA_FIELD(CUtlVector<uint16_t>, m_vecDamageTakenByHitGroup);
    SCHEMA_FIELD(CHandle<CBaseModelEntity>, m_hOwner);
};
