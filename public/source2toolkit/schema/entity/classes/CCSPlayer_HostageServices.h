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

class CBaseEntity;

class CCSPlayer_HostageServices : public CPlayerPawnComponent
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayer_HostageServices);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hCarriedHostage);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hCarriedHostageProp);
};
