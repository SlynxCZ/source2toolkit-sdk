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

#include "../enums/FixAngleSet_t.h"

class ViewAngleServerChange_t
{
public:
    DECLARE_SCHEMA_CLASS(ViewAngleServerChange_t);

    SCHEMA_FIELD(FixAngleSet_t, nType);
    SCHEMA_FIELD(QAngle, qAngle);
    SCHEMA_FIELD(uint32_t, nIndex);
};
