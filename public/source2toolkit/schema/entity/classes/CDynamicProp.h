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

#include "../enums/AnimLoopMode_t.h"
#include "CBreakableProp.h"

class CDynamicProp : public CBreakableProp
{
public:
    DECLARE_SCHEMA_CLASS(CDynamicProp);

    SCHEMA_FIELD(bool, m_bCreateNavObstacle);
    SCHEMA_FIELD(bool, m_bNavObstacleUpdatesOverridden);
    SCHEMA_FIELD(bool, m_bUseHitboxesForRenderBox);
    SCHEMA_FIELD(bool, m_bUseAnimGraph);
    SCHEMA_FIELD(CEntityIOOutput, m_pOutputAnimBegun);
    SCHEMA_FIELD(CEntityIOOutput, m_pOutputAnimOver);
    SCHEMA_FIELD(CEntityIOOutput, m_pOutputAnimLoopCycleOver);
    SCHEMA_FIELD(CEntityIOOutput, m_OnAnimReachedStart);
    SCHEMA_FIELD(CEntityIOOutput, m_OnAnimReachedEnd);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszIdleAnim);
    SCHEMA_FIELD(AnimLoopMode_t, m_nIdleAnimLoopMode);
    SCHEMA_FIELD(bool, m_bRandomizeCycle);
    SCHEMA_FIELD(bool, m_bStartDisabled);
    SCHEMA_FIELD(bool, m_bFiredStartEndOutput);
    SCHEMA_FIELD(bool, m_bForceNpcExclude);
    SCHEMA_FIELD(bool, m_bCreateNonSolid);
    SCHEMA_FIELD(bool, m_bIsOverrideProp);
    SCHEMA_FIELD(int32_t, m_iInitialGlowState);
    SCHEMA_FIELD(int32_t, m_nGlowRange);
    SCHEMA_FIELD(int32_t, m_nGlowRangeMin);
    SCHEMA_FIELD(Color, m_glowColor);
    SCHEMA_FIELD(int32_t, m_nGlowTeam);

public:
    static CDynamicProp* New(const char* className)
    {
        return CBaseEntity::New<CDynamicProp>(className);
    }

    static CDynamicProp* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CDynamicProp>(iIndex);
    }

    static CDynamicProp* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
