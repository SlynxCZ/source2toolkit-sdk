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

#include "CPlayer_UseServices.h"

class CBaseEntity;

class CCSPlayer_UseServices : public CPlayer_UseServices
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayer_UseServices);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hLastKnownUseEntity);
    SCHEMA_FIELD(float, m_flLastUseTimeStamp);
    SCHEMA_FIELD(float, m_flTimeLastUsedWindow);
};
