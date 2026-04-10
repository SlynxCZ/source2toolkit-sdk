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

class CBaseEntity;

class CKeepUpright : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CKeepUpright);

    SCHEMA_FIELD(Vector, m_worldGoalAxis);
    SCHEMA_FIELD(Vector, m_localTestAxis);
    SCHEMA_FIELD(CUtlSymbolLarge, m_nameAttach);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_attachedObject);
    SCHEMA_FIELD(float, m_angularLimit);
    SCHEMA_FIELD(bool, m_bActive);
    SCHEMA_FIELD(bool, m_bDampAllRotation);

public:
    static CKeepUpright* New(const char* className)
    {
        return CBaseEntity::New<CKeepUpright>(className);
    }

    static CKeepUpright* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CKeepUpright>(iIndex);
    }

    static CKeepUpright* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
