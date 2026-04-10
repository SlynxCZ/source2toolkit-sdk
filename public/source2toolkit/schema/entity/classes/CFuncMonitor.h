#pragma once
#include "CBaseEntity.h"
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

#include "CFuncBrush.h"

class CBaseEntity;

class CFuncMonitor : public CFuncBrush
{
public:
    DECLARE_SCHEMA_CLASS(CFuncMonitor);

    SCHEMA_FIELD(CUtlString, m_targetCamera);
    SCHEMA_FIELD(int32_t, m_nResolutionEnum);
    SCHEMA_FIELD(bool, m_bRenderShadows);
    SCHEMA_FIELD(bool, m_bUseUniqueColorTarget);
    SCHEMA_FIELD(CUtlString, m_brushModelName);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hTargetCamera);
    SCHEMA_FIELD(bool, m_bEnabled);
    SCHEMA_FIELD(bool, m_bDraw3DSkybox);
    SCHEMA_FIELD(bool, m_bStartEnabled);

public:
    static CFuncMonitor* New(const char* className)
    {
        return CBaseEntity::New<CFuncMonitor>(className);
    }

    static CFuncMonitor* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncMonitor>(iIndex);
    }

    static CFuncMonitor* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
