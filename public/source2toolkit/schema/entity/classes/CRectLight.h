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

#include "CBarnLight.h"

class CRectLight : public CBarnLight
{
public:
    DECLARE_SCHEMA_CLASS(CRectLight);

    SCHEMA_FIELD(bool, m_bShowLight);

public:
    static CRectLight* New(const char* className)
    {
        return CBaseEntity::New<CRectLight>(className);
    }

    static CRectLight* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRectLight>(iIndex);
    }

    static CRectLight* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
