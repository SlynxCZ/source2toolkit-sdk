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

class CTakeDamageInfo;

class CTakeDamageResult
{
public:
    DECLARE_SCHEMA_CLASS(CTakeDamageResult);

    SCHEMA_FIELD(CTakeDamageInfo*, m_pOriginatingInfo);
    SCHEMA_FIELD(int32_t, m_nHealthLost);
    SCHEMA_FIELD(int32_t, m_nHealthBefore);
    SCHEMA_FIELD(int32_t, m_nDamageDealt);
    SCHEMA_FIELD(float, m_flPreModifiedDamage);
    SCHEMA_FIELD(int32_t, m_nTotalledHealthLost);
    SCHEMA_FIELD(int32_t, m_nTotalledDamageDealt);
    SCHEMA_FIELD(float, m_flTotalledPreModifiedDamage);
    SCHEMA_FIELD(bool, m_bWasDamageSuppressed);
    SCHEMA_FIELD(bool, m_bSuppressFlinch);
    SCHEMA_FIELD(HitGroup_t, m_nOverrideFlinchHitGroup);
};
