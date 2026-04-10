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

class CVoteController;

class CBaseIssue
{
public:
    DECLARE_SCHEMA_CLASS(CBaseIssue);

    SCHEMA_FIELD_POINTER(char, m_szTypeString);
    SCHEMA_FIELD_POINTER(char, m_szDetailsString);
    SCHEMA_FIELD(int32_t, m_iNumYesVotes);
    SCHEMA_FIELD(int32_t, m_iNumNoVotes);
    SCHEMA_FIELD(int32_t, m_iNumPotentialVotes);
    SCHEMA_FIELD(CVoteController*, m_pVoteController);
};
