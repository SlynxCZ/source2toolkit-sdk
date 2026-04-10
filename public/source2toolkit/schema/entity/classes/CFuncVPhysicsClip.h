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

#include "CBaseModelEntity.h"

class CFuncVPhysicsClip : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncVPhysicsClip);

    SCHEMA_FIELD(bool, m_bDisabled);

public:
    static CFuncVPhysicsClip* New(const char* className)
    {
        return CBaseEntity::New<CFuncVPhysicsClip>(className);
    }

    static CFuncVPhysicsClip* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncVPhysicsClip>(iIndex);
    }

    static CFuncVPhysicsClip* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
