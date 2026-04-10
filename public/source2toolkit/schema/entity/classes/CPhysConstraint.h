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

#include "CLogicalEntity.h"

class CBaseEntity;

class CPhysConstraint : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPhysConstraint);

    SCHEMA_FIELD(CUtlSymbolLarge, m_nameAttach1);
    SCHEMA_FIELD(CUtlSymbolLarge, m_nameAttach2);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hAttach1);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hAttach2);
    SCHEMA_FIELD(CUtlSymbolLarge, m_nameAttachment1);
    SCHEMA_FIELD(CUtlSymbolLarge, m_nameAttachment2);
    SCHEMA_FIELD(CUtlSymbolLarge, m_breakSound);
    SCHEMA_FIELD(float, m_forceLimit);
    SCHEMA_FIELD(float, m_torqueLimit);
    SCHEMA_FIELD(float, m_minTeleportDistance);
    SCHEMA_FIELD(bool, m_bSnapObjectPositions);
    SCHEMA_FIELD(bool, m_bTreatEntity1AsInfiniteMass);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBreak);

public:
    static CPhysConstraint* New(const char* className)
    {
        return CBaseEntity::New<CPhysConstraint>(className);
    }

    static CPhysConstraint* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysConstraint>(iIndex);
    }

    static CPhysConstraint* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
