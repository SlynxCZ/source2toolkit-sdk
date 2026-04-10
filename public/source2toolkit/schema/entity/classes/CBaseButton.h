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
#include "locksound_t.h"

class CBaseModelEntity;

class CBaseButton : public CBaseToggle
{
public:
    DECLARE_SCHEMA_CLASS(CBaseButton);

    SCHEMA_FIELD(QAngle, m_angMoveEntitySpace);
    SCHEMA_FIELD(bool, m_fStayPushed);
    SCHEMA_FIELD(bool, m_fRotating);
    SCHEMA_FIELD(locksound_t, m_ls);
    SCHEMA_FIELD(CUtlSymbolLarge, m_sUseSound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_sLockedSound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_sUnlockedSound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_sOverrideAnticipationName);
    SCHEMA_FIELD(bool, m_bLocked);
    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(float, m_flUseLockedTime);
    SCHEMA_FIELD(bool, m_bSolidBsp);
    SCHEMA_FIELD(CEntityIOOutput, m_OnDamaged);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPressed);
    SCHEMA_FIELD(CEntityIOOutput, m_OnUseLocked);
    SCHEMA_FIELD(CEntityIOOutput, m_OnIn);
    SCHEMA_FIELD(CEntityIOOutput, m_OnOut);
    SCHEMA_FIELD(int32_t, m_nState);
    SCHEMA_FIELD(CEntityHandle, m_hConstraint);
    SCHEMA_FIELD(CEntityHandle, m_hConstraintParent);
    SCHEMA_FIELD(bool, m_bForceNpcExclude);
    SCHEMA_FIELD(CUtlSymbolLarge, m_sGlowEntity);
    SCHEMA_FIELD(CHandle<CBaseModelEntity>, m_glowEntity);
    SCHEMA_FIELD(bool, m_usable);
    SCHEMA_FIELD(CUtlSymbolLarge, m_szDisplayText);

public:
    static CBaseButton* New(const char* className)
    {
        return CBaseEntity::New<CBaseButton>(className);
    }

    static CBaseButton* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseButton>(iIndex);
    }

    static CBaseButton* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
