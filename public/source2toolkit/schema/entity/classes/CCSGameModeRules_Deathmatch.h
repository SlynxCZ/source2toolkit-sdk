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

#include "CCSGameModeRules.h"

class CCSGameModeRules_Deathmatch : public CCSGameModeRules
{
public:
    DECLARE_SCHEMA_CLASS(CCSGameModeRules_Deathmatch);

    SCHEMA_FIELD(float, m_flDMBonusStartTime);
    SCHEMA_FIELD(float, m_flDMBonusTimeLength);
    SCHEMA_FIELD(CUtlString, m_sDMBonusWeapon);
};
