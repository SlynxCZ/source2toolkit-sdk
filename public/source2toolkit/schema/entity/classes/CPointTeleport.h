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

#include "CServerOnlyPointEntity.h"

class CPointTeleport : public CServerOnlyPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointTeleport);

    SCHEMA_FIELD(Vector, m_vSaveOrigin);
    SCHEMA_FIELD(QAngle, m_vSaveAngles);
    SCHEMA_FIELD(bool, m_bTeleportParentedEntities);
    SCHEMA_FIELD(bool, m_bTeleportUseCurrentAngle);

public:
    static CPointTeleport* New(const char* className)
    {
        return CBaseEntity::New<CPointTeleport>(className);
    }

    static CPointTeleport* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointTeleport>(iIndex);
    }

    static CPointTeleport* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
