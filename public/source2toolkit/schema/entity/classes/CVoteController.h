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

#include "CBaseEntity.h"
#include "CountdownTimer.h"

class CBaseIssue;

class CVoteController : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CVoteController);

    SCHEMA_FIELD(int32_t, m_iActiveIssueIndex);
    SCHEMA_FIELD(int32_t, m_iOnlyTeamToVote);
    SCHEMA_FIELD_POINTER(int32_t, m_nVoteOptionCount);
    SCHEMA_FIELD(int32_t, m_nPotentialVotes);
    SCHEMA_FIELD(bool, m_bIsYesNoVote);
    SCHEMA_FIELD(CountdownTimer, m_acceptingVotesTimer);
    SCHEMA_FIELD(CountdownTimer, m_executeCommandTimer);
    SCHEMA_FIELD(CountdownTimer, m_resetVoteTimer);
    SCHEMA_FIELD_POINTER(int32_t, m_nVotesCast);
    SCHEMA_FIELD(int32_t, m_playerHoldingVote);
    SCHEMA_FIELD(int32_t, m_playerOverrideForVote);
    SCHEMA_FIELD(int32_t, m_nHighestCountIndex);
    SCHEMA_FIELD(CUtlVector<CBaseIssue*>, m_potentialIssues);
    SCHEMA_FIELD(CUtlVector<char*>, m_VoteOptions);

public:
    static CVoteController* New(const char* className)
    {
        return CBaseEntity::New<CVoteController>(className);
    }

    static CVoteController* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CVoteController>(iIndex);
    }

    static CVoteController* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
