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

#include "CInfoDynamicShadowHint.h"

class CInfoDynamicShadowHintBox : public CInfoDynamicShadowHint
{
public:
    DECLARE_SCHEMA_CLASS(CInfoDynamicShadowHintBox);

    SCHEMA_FIELD(Vector, m_vBoxMins);
    SCHEMA_FIELD(Vector, m_vBoxMaxs);

public:
    static CInfoDynamicShadowHintBox* New(const char* className)
    {
        return CBaseEntity::New<CInfoDynamicShadowHintBox>(className);
    }

    static CInfoDynamicShadowHintBox* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoDynamicShadowHintBox>(iIndex);
    }

    static CInfoDynamicShadowHintBox* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
