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

#include "CItem.h"
#include "InfoForResourceTypeIParticleSystemDefinition.h"

class CBaseFilter;
class CItemGenericTriggerHelper;

class CItemGeneric : public CItem
{
public:
    DECLARE_SCHEMA_CLASS(CItemGeneric);

    SCHEMA_FIELD(bool, m_bHasTriggerRadius);
    SCHEMA_FIELD(bool, m_bHasPickupRadius);
    SCHEMA_FIELD(float, m_flPickupRadiusSqr);
    SCHEMA_FIELD(float, m_flTriggerRadiusSqr);
    SCHEMA_FIELD(float, m_flLastPickupCheck);
    SCHEMA_FIELD(bool, m_bPlayerCounterListenerAdded);
    SCHEMA_FIELD(bool, m_bPlayerInTriggerRadius);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIParticleSystemDefinition >, m_hSpawnParticleEffect);
    SCHEMA_FIELD(CUtlSymbolLarge, m_pAmbientSoundEffect);
    SCHEMA_FIELD(bool, m_bAutoStartAmbientSound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_pSpawnScriptFunction);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIParticleSystemDefinition >, m_hPickupParticleEffect);
    SCHEMA_FIELD(CUtlSymbolLarge, m_pPickupSoundEffect);
    SCHEMA_FIELD(CUtlSymbolLarge, m_pPickupScriptFunction);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIParticleSystemDefinition >, m_hTimeoutParticleEffect);
    SCHEMA_FIELD(CUtlSymbolLarge, m_pTimeoutSoundEffect);
    SCHEMA_FIELD(CUtlSymbolLarge, m_pTimeoutScriptFunction);
    SCHEMA_FIELD(CUtlSymbolLarge, m_pPickupFilterName);
    SCHEMA_FIELD(CHandle<CBaseFilter>, m_hPickupFilter);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPickup);
    SCHEMA_FIELD(CEntityIOOutput, m_OnTimeout);
    SCHEMA_FIELD(CEntityIOOutput, m_OnTriggerStartTouch);
    SCHEMA_FIELD(CEntityIOOutput, m_OnTriggerTouch);
    SCHEMA_FIELD(CEntityIOOutput, m_OnTriggerEndTouch);
    SCHEMA_FIELD(CUtlSymbolLarge, m_pAllowPickupScriptFunction);
    SCHEMA_FIELD(float, m_flPickupRadius);
    SCHEMA_FIELD(float, m_flTriggerRadius);
    SCHEMA_FIELD(CUtlSymbolLarge, m_pTriggerSoundEffect);
    SCHEMA_FIELD(bool, m_bGlowWhenInTrigger);
    SCHEMA_FIELD(Color, m_glowColor);
    SCHEMA_FIELD(bool, m_bUseable);
    SCHEMA_FIELD(CHandle<CItemGenericTriggerHelper>, m_hTriggerHelper);

public:
    static CItemGeneric* New(const char* className)
    {
        return CBaseEntity::New<CItemGeneric>(className);
    }

    static CItemGeneric* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CItemGeneric>(iIndex);
    }

    static CItemGeneric* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
