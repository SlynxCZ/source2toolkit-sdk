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

class CBasePlayerPawn;

class CInstructorEventEntity : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInstructorEventEntity);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszHintTargetEntity);
    SCHEMA_FIELD(CHandle<CBasePlayerPawn>, m_hTargetPlayer);

public:
    static CInstructorEventEntity* New(const char* className)
    {
        return CBaseEntity::New<CInstructorEventEntity>(className);
    }

    static CInstructorEventEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInstructorEventEntity>(iIndex);
    }

    static CInstructorEventEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
