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

#include "CBaseEntity.h"
#include "sky3dparams_t.h"

class CSkyCamera : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSkyCamera);

    SCHEMA_FIELD(sky3dparams_t, m_skyboxData);
    SCHEMA_FIELD_POINTER(CUtlStringToken, m_skyboxSlotToken);
    SCHEMA_FIELD(bool, m_bUseAngles);
    SCHEMA_FIELD(CSkyCamera*, m_pNext);

public:
    static CSkyCamera* New(const char* className)
    {
        return CBaseEntity::New<CSkyCamera>(className);
    }

    static CSkyCamera* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSkyCamera>(iIndex);
    }

    static CSkyCamera* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
