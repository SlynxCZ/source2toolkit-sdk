#pragma once
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

#include "CEntitySubclassVDataBase.h"
#include "CSkillFloat.h"

class CBasePlayerVData : public CEntitySubclassVDataBase
{
public:
    DECLARE_SCHEMA_CLASS(CBasePlayerVData);

    SCHEMA_FIELD(CSkillFloat, m_flHeadDamageMultiplier);
    SCHEMA_FIELD(CSkillFloat, m_flChestDamageMultiplier);
    SCHEMA_FIELD(CSkillFloat, m_flStomachDamageMultiplier);
    SCHEMA_FIELD(CSkillFloat, m_flArmDamageMultiplier);
    SCHEMA_FIELD(CSkillFloat, m_flLegDamageMultiplier);
    SCHEMA_FIELD(float, m_flHoldBreathTime);
    SCHEMA_FIELD(float, m_flDrowningDamageInterval);
    SCHEMA_FIELD(int32_t, m_nDrowningDamageInitial);
    SCHEMA_FIELD(int32_t, m_nDrowningDamageMax);
    SCHEMA_FIELD(int32_t, m_nWaterSpeed);
    SCHEMA_FIELD(float, m_flUseRange);
    SCHEMA_FIELD(float, m_flUseAngleTolerance);
    SCHEMA_FIELD(float, m_flCrouchTime);
};
