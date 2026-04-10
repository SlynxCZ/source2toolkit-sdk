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

#include "IChoreoServices.h"

class CBaseAnimGraph;
class CScriptedSequence;

class CGameChoreoServices : public IChoreoServices
{
public:
    DECLARE_SCHEMA_CLASS(CGameChoreoServices);

    SCHEMA_FIELD(CHandle<CBaseAnimGraph>, m_hOwner);
    SCHEMA_FIELD(CHandle<CScriptedSequence>, m_hScriptedSequence);
    SCHEMA_FIELD(float, m_flTimeStartedState);
};
