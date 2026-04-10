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

class CFuncWall : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncWall);

    SCHEMA_FIELD(int32_t, m_nState);

public:
    static CFuncWall* New(const char* className)
    {
        return CBaseEntity::New<CFuncWall>(className);
    }

    static CFuncWall* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncWall>(iIndex);
    }

    static CFuncWall* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
