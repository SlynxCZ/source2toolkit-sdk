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

#include "CBaseToggle.h"
#include "../enums/MoveLinearAuthoredPos_t.h"

class CFuncMoveLinear : public CBaseToggle
{
public:
    DECLARE_SCHEMA_CLASS(CFuncMoveLinear);

    SCHEMA_FIELD(MoveLinearAuthoredPos_t, m_authoredPosition);
    SCHEMA_FIELD(QAngle, m_angMoveEntitySpace);
    SCHEMA_FIELD(Vector, m_vecMoveDirParentSpace);
    SCHEMA_FIELD(CUtlSymbolLarge, m_soundStart);
    SCHEMA_FIELD(CUtlSymbolLarge, m_soundStop);
    SCHEMA_FIELD(CUtlSymbolLarge, m_currentSound);
    SCHEMA_FIELD(float, m_flBlockDamage);
    SCHEMA_FIELD(float, m_flStartPosition);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFullyOpen);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFullyClosed);
    SCHEMA_FIELD(bool, m_bCreateMovableNavMesh);
    SCHEMA_FIELD(bool, m_bAllowMovableNavMeshDockingOnEntireEntity);
    SCHEMA_FIELD(bool, m_bCreateNavObstacle);

public:
    static CFuncMoveLinear* New(const char* className)
    {
        return CBaseEntity::New<CFuncMoveLinear>(className);
    }

    static CFuncMoveLinear* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncMoveLinear>(iIndex);
    }

    static CFuncMoveLinear* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
