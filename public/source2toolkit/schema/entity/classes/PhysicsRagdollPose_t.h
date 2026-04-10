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

class CBaseEntity;

class PhysicsRagdollPose_t
{
public:
    DECLARE_SCHEMA_CLASS(PhysicsRagdollPose_t);

    SCHEMA_FIELD(CUtlVector<CTransform>, m_Transforms);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hOwner);
    SCHEMA_FIELD(bool, m_bSetFromDebugHistory);
};
