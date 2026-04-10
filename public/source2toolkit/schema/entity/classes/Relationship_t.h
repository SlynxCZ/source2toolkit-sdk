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

#include "../enums/Disposition_t.h"

class Relationship_t
{
public:
    DECLARE_SCHEMA_CLASS(Relationship_t);

    SCHEMA_FIELD(Disposition_t, disposition);
    SCHEMA_FIELD(int32_t, priority);
};
