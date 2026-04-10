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

#include "CDamageRecord.h"
#include "CPlayerControllerComponent.h"

class CCSPlayerController_DamageServices : public CPlayerControllerComponent
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayerController_DamageServices);

    SCHEMA_FIELD(int32_t, m_nSendUpdate);
    SCHEMA_FIELD(CUtlVector<CDamageRecord>, m_DamageList);
};
