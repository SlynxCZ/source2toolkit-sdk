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

#include "CBaseAnimGraph.h"
#include "SceneEventId_t.h"

class CBaseFlex : public CBaseAnimGraph
{
public:
    DECLARE_SCHEMA_CLASS(CBaseFlex);

    SCHEMA_FIELD(CUtlVector<float>, m_flexWeight);
    SCHEMA_FIELD(Vector, m_vLookTargetPosition);
    SCHEMA_FIELD(float, m_flAllowResponsesEndTime);
    SCHEMA_FIELD(float, m_flLastFlexAnimationTime);
    SCHEMA_FIELD(SceneEventId_t, m_nNextSceneEventId);
    SCHEMA_FIELD(bool, m_bUpdateLayerPriorities);

public:
    static CBaseFlex* New(const char* className)
    {
        return CBaseEntity::New<CBaseFlex>(className);
    }

    static CBaseFlex* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseFlex>(iIndex);
    }

    static CBaseFlex* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
