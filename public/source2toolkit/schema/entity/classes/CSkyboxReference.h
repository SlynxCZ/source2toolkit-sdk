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

class CSkyCamera;

class CSkyboxReference : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSkyboxReference);

    SCHEMA_FIELD(WorldGroupId_t, m_worldGroupId);
    SCHEMA_FIELD(CHandle<CSkyCamera>, m_hSkyCamera);

public:
    static CSkyboxReference* New(const char* className)
    {
        return CBaseEntity::New<CSkyboxReference>(className);
    }

    static CSkyboxReference* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSkyboxReference>(iIndex);
    }

    static CSkyboxReference* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
