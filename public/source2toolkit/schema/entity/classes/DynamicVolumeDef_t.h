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

class CBaseEntity;

class DynamicVolumeDef_t
{
public:
    DECLARE_SCHEMA_CLASS(DynamicVolumeDef_t);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_source);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_target);
    SCHEMA_FIELD(int32_t, m_nHullIdx);
    SCHEMA_FIELD(Vector, m_vSourceAnchorPos);
    SCHEMA_FIELD(Vector, m_vTargetAnchorPos);
    SCHEMA_FIELD(uint32_t, m_nAreaSrc);
    SCHEMA_FIELD(uint32_t, m_nAreaDst);
    SCHEMA_FIELD(bool, m_bAttached);
};
