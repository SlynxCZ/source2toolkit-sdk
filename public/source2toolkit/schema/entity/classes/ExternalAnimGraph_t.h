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

#include "ExternalAnimGraphHandle_t.h"
#include "../enums/ExternalAnimGraphInactiveBehavior_t.h"
#include "InfoForResourceTypeCNmGraphDefinition.h"

class CBaseAnimGraph;

class ExternalAnimGraph_t
{
public:
    DECLARE_SCHEMA_CLASS(ExternalAnimGraph_t);

    SCHEMA_FIELD(ExternalAnimGraphHandle_t, m_hExtGraphHandle);
    SCHEMA_FIELD(CGlobalSymbol, m_sExternalGraphSlotID);
    SCHEMA_FIELD(CStrongHandleCopyable< InfoForResourceTypeCNmGraphDefinition >, m_hGraphDefinition);
    SCHEMA_FIELD(CHandle<CBaseAnimGraph>, m_hExternalGraphOwner);
    SCHEMA_FIELD(ExternalAnimGraphInactiveBehavior_t, m_nInactiveBehavior);
};
