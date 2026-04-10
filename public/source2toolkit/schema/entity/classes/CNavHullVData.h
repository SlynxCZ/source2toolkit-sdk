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

class CNavHullVData
{
public:
    DECLARE_SCHEMA_CLASS(CNavHullVData);

    SCHEMA_FIELD(bool, m_bAgentEnabled);
    SCHEMA_FIELD(float, m_agentRadius);
    SCHEMA_FIELD(float, m_agentHeight);
    SCHEMA_FIELD(bool, m_agentShortHeightEnabled);
    SCHEMA_FIELD(float, m_agentShortHeight);
    SCHEMA_FIELD(bool, m_agentCrawlEnabled);
    SCHEMA_FIELD(float, m_agentCrawlHeight);
    SCHEMA_FIELD(float, m_agentMaxClimb);
    SCHEMA_FIELD(int32_t, m_agentMaxSlope);
    SCHEMA_FIELD(float, m_agentMaxJumpDownDist);
    SCHEMA_FIELD(float, m_agentMaxJumpHorizDistBase);
    SCHEMA_FIELD(float, m_agentMaxJumpUpDist);
    SCHEMA_FIELD(int32_t, m_agentBorderErosion);
    SCHEMA_FIELD(bool, m_flowMapGenerationEnabled);
    SCHEMA_FIELD(float, m_flowMapNodeMaxRadius);
};
