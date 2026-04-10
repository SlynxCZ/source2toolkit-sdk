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

class COmniLight : public CBarnLight
{
public:
    DECLARE_SCHEMA_CLASS(COmniLight);

    SCHEMA_FIELD(float, m_flInnerAngle);
    SCHEMA_FIELD(float, m_flOuterAngle);
    SCHEMA_FIELD(bool, m_bShowLight);

public:
    static COmniLight* New(const char* className)
    {
        return CBaseEntity::New<COmniLight>(className);
    }

    static COmniLight* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<COmniLight>(iIndex);
    }

    static COmniLight* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
