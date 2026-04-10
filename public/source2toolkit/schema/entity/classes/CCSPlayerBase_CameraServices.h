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

#include "CPlayer_CameraServices.h"

class CBaseEntity;

class CCSPlayerBase_CameraServices : public CPlayer_CameraServices
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayerBase_CameraServices);

    SCHEMA_FIELD(uint32_t, m_iFOV);
    SCHEMA_FIELD(uint32_t, m_iFOVStart);
    SCHEMA_FIELD(float, m_flFOVTime);
    SCHEMA_FIELD(float, m_flFOVRate);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hZoomOwner);
    SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_hTriggerFogList);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hLastFogTrigger);
};
