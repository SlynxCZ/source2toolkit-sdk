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

#include "ragdollelement_t.h"
#include "ragdollhierarchyjoint_t.h"

class ragdoll_t
{
public:
    DECLARE_SCHEMA_CLASS(ragdoll_t);

    SCHEMA_FIELD(CUtlVector<ragdollelement_t>, list);
    SCHEMA_FIELD(CUtlVector<ragdollhierarchyjoint_t>, hierarchyJoints);
    SCHEMA_FIELD(CUtlVector<int32_t>, boneIndex);
    SCHEMA_FIELD(bool, allowStretch);
    SCHEMA_FIELD(bool, unused);
};
