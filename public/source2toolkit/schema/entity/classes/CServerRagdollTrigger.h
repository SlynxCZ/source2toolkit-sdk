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

#include "CBaseTrigger.h"

class CServerRagdollTrigger : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CServerRagdollTrigger);


public:
    static CServerRagdollTrigger* New(const char* className)
    {
        return CBaseEntity::New<CServerRagdollTrigger>(className);
    }

    static CServerRagdollTrigger* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CServerRagdollTrigger>(iIndex);
    }

    static CServerRagdollTrigger* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
