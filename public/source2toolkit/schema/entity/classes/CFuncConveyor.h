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

#include "CBaseModelEntity.h"

class CBaseEntity;

class CFuncConveyor : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncConveyor);

    SCHEMA_FIELD(CUtlSymbolLarge, m_szConveyorModels);
    SCHEMA_FIELD(float, m_flTransitionDurationSeconds);
    SCHEMA_FIELD(QAngle, m_angMoveEntitySpace);
    SCHEMA_FIELD(Vector, m_vecMoveDirEntitySpace);
    SCHEMA_FIELD(float, m_flTargetSpeed);
    SCHEMA_FIELD(int32_t, m_nTransitionStartTick);
    SCHEMA_FIELD(int32_t, m_nTransitionDurationTicks);
    SCHEMA_FIELD(float, m_flTransitionStartSpeed);
    SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_hConveyorModels);

public:
    static CFuncConveyor* New(const char* className)
    {
        return CBaseEntity::New<CFuncConveyor>(className);
    }

    static CFuncConveyor* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncConveyor>(iIndex);
    }

    static CFuncConveyor* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
