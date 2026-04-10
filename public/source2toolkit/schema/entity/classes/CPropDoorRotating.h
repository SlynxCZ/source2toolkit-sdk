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

#include "CBasePropDoor.h"
#include "../enums/doorCheck_e.h"
#include "../enums/PropDoorRotatingOpenDirection_e.h"
#include "../enums/PropDoorRotatingSpawnPos_t.h"

class CEntityBlocker;

class CPropDoorRotating : public CBasePropDoor
{
public:
    DECLARE_SCHEMA_CLASS(CPropDoorRotating);

    SCHEMA_FIELD(Vector, m_vecAxis);
    SCHEMA_FIELD(float, m_flDistance);
    SCHEMA_FIELD(PropDoorRotatingSpawnPos_t, m_eSpawnPosition);
    SCHEMA_FIELD(PropDoorRotatingOpenDirection_e, m_eOpenDirection);
    SCHEMA_FIELD(PropDoorRotatingOpenDirection_e, m_eCurrentOpenDirection);
    SCHEMA_FIELD(doorCheck_e, m_eDefaultCheckDirection);
    SCHEMA_FIELD(float, m_flAjarAngle);
    SCHEMA_FIELD(QAngle, m_angRotationAjarDeprecated);
    SCHEMA_FIELD(QAngle, m_angRotationClosed);
    SCHEMA_FIELD(QAngle, m_angRotationOpenForward);
    SCHEMA_FIELD(QAngle, m_angRotationOpenBack);
    SCHEMA_FIELD(QAngle, m_angGoal);
    SCHEMA_FIELD(Vector, m_vecForwardBoundsMin);
    SCHEMA_FIELD(Vector, m_vecForwardBoundsMax);
    SCHEMA_FIELD(Vector, m_vecBackBoundsMin);
    SCHEMA_FIELD(Vector, m_vecBackBoundsMax);
    SCHEMA_FIELD(bool, m_bAjarDoorShouldntAlwaysOpen);
    SCHEMA_FIELD(CHandle<CEntityBlocker>, m_hEntityBlocker);

public:
    static CPropDoorRotating* New(const char* className)
    {
        return CBaseEntity::New<CPropDoorRotating>(className);
    }

    static CPropDoorRotating* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPropDoorRotating>(iIndex);
    }

    static CPropDoorRotating* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
