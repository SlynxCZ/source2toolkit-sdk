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

#include "CPlayerPawnComponent.h"
#include "../enums/ObserverMode_t.h"

class CBaseEntity;

class CPlayer_ObserverServices : public CPlayerPawnComponent
{
public:
    DECLARE_SCHEMA_CLASS(CPlayer_ObserverServices);

    SCHEMA_FIELD(uint8_t, m_iObserverMode);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hObserverTarget);
    SCHEMA_FIELD(ObserverMode_t, m_iObserverLastMode);
    SCHEMA_FIELD(bool, m_bForcedObserverMode);
};
