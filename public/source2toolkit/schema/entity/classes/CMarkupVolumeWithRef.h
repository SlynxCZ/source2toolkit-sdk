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

#include "CMarkupVolumeTagged.h"

class CMarkupVolumeWithRef : public CMarkupVolumeTagged
{
public:
    DECLARE_SCHEMA_CLASS(CMarkupVolumeWithRef);

    SCHEMA_FIELD(bool, m_bUseRef);
    SCHEMA_FIELD(Vector, m_vRefPosEntitySpace);
    SCHEMA_FIELD(Vector, m_vRefPosWorldSpace);
    SCHEMA_FIELD(float, m_flRefDot);

public:
    static CMarkupVolumeWithRef* New(const char* className)
    {
        return CBaseEntity::New<CMarkupVolumeWithRef>(className);
    }

    static CMarkupVolumeWithRef* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CMarkupVolumeWithRef>(iIndex);
    }

    static CMarkupVolumeWithRef* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
