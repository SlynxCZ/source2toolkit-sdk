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

#include "CPointEntity.h"

class CPathCorner : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPathCorner);

    SCHEMA_FIELD(float, m_flWait);
    SCHEMA_FIELD(float, m_flRadius);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPass);

public:
    static CPathCorner* New(const char* className)
    {
        return CBaseEntity::New<CPathCorner>(className);
    }

    static CPathCorner* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPathCorner>(iIndex);
    }

    static CPathCorner* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
