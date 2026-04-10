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
#include "../enums/ItemFlagTypes_t.h"
#include "../enums/RumbleEffect_t.h"

class CBasePlayerWeaponVData : public CEntitySubclassVDataBase
{
public:
    DECLARE_SCHEMA_CLASS(CBasePlayerWeaponVData);

    SCHEMA_FIELD(bool, m_bBuiltRightHanded);
    SCHEMA_FIELD(bool, m_bAllowFlipping);
    SCHEMA_FIELD(CUtlString, m_szMuzzleFlashParticleConfig);
    SCHEMA_FIELD(uint8_t, m_nMuzzleSmokeShotThreshold);
    SCHEMA_FIELD(float, m_flMuzzleSmokeTimeout);
    SCHEMA_FIELD(float, m_flMuzzleSmokeDecrementRate);
    SCHEMA_FIELD(bool, m_bGenerateMuzzleLight);
    SCHEMA_FIELD(bool, m_bLinkedCooldowns);
    SCHEMA_FIELD(ItemFlagTypes_t, m_iFlags);
    SCHEMA_FIELD(int32_t, m_iWeight);
    SCHEMA_FIELD(bool, m_bAutoSwitchTo);
    SCHEMA_FIELD(bool, m_bAutoSwitchFrom);
    SCHEMA_FIELD(uint8_t, m_nPrimaryAmmoType);
    SCHEMA_FIELD(uint8_t, m_nSecondaryAmmoType);
    SCHEMA_FIELD(int32_t, m_iMaxClip1);
    SCHEMA_FIELD(int32_t, m_iMaxClip2);
    SCHEMA_FIELD(int32_t, m_iDefaultClip1);
    SCHEMA_FIELD(int32_t, m_iDefaultClip2);
    SCHEMA_FIELD(bool, m_bReserveAmmoAsClips);
    SCHEMA_FIELD(bool, m_bTreatAsSingleClip);
    SCHEMA_FIELD(bool, m_bKeepLoadedAmmo);
    SCHEMA_FIELD(RumbleEffect_t, m_iRumbleEffect);
    SCHEMA_FIELD(float, m_flDropSpeed);
    SCHEMA_FIELD(int32_t, m_iSlot);
    SCHEMA_FIELD(int32_t, m_iPosition);
};
