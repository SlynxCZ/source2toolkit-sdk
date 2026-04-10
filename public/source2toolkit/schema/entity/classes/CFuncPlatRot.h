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

#include "CFuncPlat.h"

class CFuncPlatRot : public CFuncPlat
{
public:
    DECLARE_SCHEMA_CLASS(CFuncPlatRot);

    SCHEMA_FIELD(QAngle, m_end);
    SCHEMA_FIELD(QAngle, m_start);

public:
    static CFuncPlatRot* New(const char* className)
    {
        return CBaseEntity::New<CFuncPlatRot>(className);
    }

    static CFuncPlatRot* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncPlatRot>(iIndex);
    }

    static CFuncPlatRot* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
