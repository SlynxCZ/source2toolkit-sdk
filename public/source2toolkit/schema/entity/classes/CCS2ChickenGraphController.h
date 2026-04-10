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

#include "CAnimGraphControllerBase.h"

class CCS2ChickenGraphController : public CAnimGraphControllerBase
{
public:
    DECLARE_SCHEMA_CLASS(CCS2ChickenGraphController);

    SCHEMA_FIELD(bool, m_bHasActionCompletedEvent);
    SCHEMA_FIELD(bool, m_bWaitingForCompletedEvent);
};
