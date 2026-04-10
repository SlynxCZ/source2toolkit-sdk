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

#include "CCSPlayerPawnBase.h"
#include "CEconItemView.h"
#include "../enums/CSPlayerBlockingUseAction_t.h"
#include "EntitySpottedState_t.h"
#include "../enums/loadout_slot_t.h"
#include "PredictedDamageTag_t.h"

class CBaseEntity;
class CCSBot;
class CCSPlayer_ActionTrackingServices;
class CCSPlayer_BulletServices;
class CCSPlayer_BuyServices;
class CCSPlayer_DamageReactServices;
class CCSPlayer_HostageServices;
class CCSPlayer_RadioServices;
class CCSPlayerController;

class CCSPlayerPawn : public CCSPlayerPawnBase
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayerPawn);

    SCHEMA_FIELD(CCSPlayer_BulletServices*, m_pBulletServices);
    SCHEMA_FIELD(CCSPlayer_HostageServices*, m_pHostageServices);
    SCHEMA_FIELD(CCSPlayer_BuyServices*, m_pBuyServices);
    SCHEMA_FIELD(CCSPlayer_ActionTrackingServices*, m_pActionTrackingServices);
    SCHEMA_FIELD(CCSPlayer_RadioServices*, m_pRadioServices);
    SCHEMA_FIELD(CCSPlayer_DamageReactServices*, m_pDamageReactServices);
    SCHEMA_FIELD(uint16_t, m_nCharacterDefIndex);
    SCHEMA_FIELD(bool, m_bHasFemaleVoice);
    SCHEMA_FIELD(CUtlString, m_strVOPrefix);
    SCHEMA_FIELD_POINTER(char, m_szLastPlaceName);
    SCHEMA_FIELD(bool, m_bInHostageResetZone);
    SCHEMA_FIELD(bool, m_bInBuyZone);
    SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_TouchingBuyZones);
    SCHEMA_FIELD(bool, m_bWasInBuyZone);
    SCHEMA_FIELD(bool, m_bInHostageRescueZone);
    SCHEMA_FIELD(bool, m_bInBombZone);
    SCHEMA_FIELD(bool, m_bWasInHostageRescueZone);
    SCHEMA_FIELD(int32_t, m_iRetakesOffering);
    SCHEMA_FIELD(int32_t, m_iRetakesOfferingCard);
    SCHEMA_FIELD(bool, m_bRetakesHasDefuseKit);
    SCHEMA_FIELD(bool, m_bRetakesMVPLastRound);
    SCHEMA_FIELD(int32_t, m_iRetakesMVPBoostItem);
    SCHEMA_FIELD(loadout_slot_t, m_RetakesMVPBoostExtraUtility);
    SCHEMA_FIELD(float, m_flHealthShotBoostExpirationTime);
    SCHEMA_FIELD(float, m_flLandingTimeSeconds);
    SCHEMA_FIELD(QAngle, m_aimPunchAngle);
    SCHEMA_FIELD(QAngle, m_aimPunchAngleVel);
    SCHEMA_FIELD(int32_t, m_aimPunchTickBase);
    SCHEMA_FIELD(float, m_aimPunchTickFraction);
    SCHEMA_FIELD(CUtlVector<QAngle>, m_aimPunchCache);
    SCHEMA_FIELD(bool, m_bIsBuyMenuOpen);
    SCHEMA_FIELD(float, m_lastLandTime);
    SCHEMA_FIELD(bool, m_bOnGroundLastTick);
    SCHEMA_FIELD(int32_t, m_iPlayerLocked);
    SCHEMA_FIELD(float, m_flTimeOfLastInjury);
    SCHEMA_FIELD(float, m_flNextSprayDecalTime);
    SCHEMA_FIELD(bool, m_bNextSprayDecalTimeExpedited);
    SCHEMA_FIELD(int32_t, m_nRagdollDamageBone);
    SCHEMA_FIELD(Vector, m_vRagdollDamageForce);
    SCHEMA_FIELD(Vector, m_vRagdollDamagePosition);
    SCHEMA_FIELD_POINTER(char, m_szRagdollDamageWeaponName);
    SCHEMA_FIELD(bool, m_bRagdollDamageHeadshot);
    SCHEMA_FIELD(Vector, m_vRagdollServerOrigin);
    SCHEMA_FIELD(CEconItemView, m_EconGloves);
    SCHEMA_FIELD(uint8_t, m_nEconGlovesChanged);
    SCHEMA_FIELD(QAngle, m_qDeathEyeAngles);
    SCHEMA_FIELD(bool, m_bSkipOneHeadConstraintUpdate);
    SCHEMA_FIELD(bool, m_bLeftHanded);
    SCHEMA_FIELD(float, m_fSwitchedHandednessTime);
    SCHEMA_FIELD(float, m_flViewmodelOffsetX);
    SCHEMA_FIELD(float, m_flViewmodelOffsetY);
    SCHEMA_FIELD(float, m_flViewmodelOffsetZ);
    SCHEMA_FIELD(float, m_flViewmodelFOV);
    SCHEMA_FIELD(bool, m_bIsWalking);
    SCHEMA_FIELD(float, m_fLastGivenDefuserTime);
    SCHEMA_FIELD(float, m_fLastGivenBombTime);
    SCHEMA_FIELD(float, m_flDealtDamageToEnemyMostRecentTimestamp);
    SCHEMA_FIELD(uint32_t, m_iDisplayHistoryBits);
    SCHEMA_FIELD(float, m_flLastAttackedTeammate);
    SCHEMA_FIELD(float, m_allowAutoFollowTime);
    SCHEMA_FIELD(bool, m_bResetArmorNextSpawn);
    SCHEMA_FIELD(CEntityIndex, m_nLastKillerIndex);
    SCHEMA_FIELD(EntitySpottedState_t, m_entitySpottedState);
    SCHEMA_FIELD(int32_t, m_nSpotRules);
    SCHEMA_FIELD(bool, m_bIsScoped);
    SCHEMA_FIELD(bool, m_bResumeZoom);
    SCHEMA_FIELD(bool, m_bIsDefusing);
    SCHEMA_FIELD(bool, m_bIsGrabbingHostage);
    SCHEMA_FIELD(CSPlayerBlockingUseAction_t, m_iBlockingUseActionInProgress);
    SCHEMA_FIELD(float, m_flEmitSoundTime);
    SCHEMA_FIELD(bool, m_bInNoDefuseArea);
    SCHEMA_FIELD(CEntityIndex, m_iBombSiteIndex);
    SCHEMA_FIELD(int32_t, m_nWhichBombZone);
    SCHEMA_FIELD(bool, m_bInBombZoneTrigger);
    SCHEMA_FIELD(bool, m_bWasInBombZoneTrigger);
    SCHEMA_FIELD(int32_t, m_iShotsFired);
    SCHEMA_FIELD(float, m_flFlinchStack);
    SCHEMA_FIELD(float, m_flVelocityModifier);
    SCHEMA_FIELD(float, m_flHitHeading);
    SCHEMA_FIELD(int32_t, m_nHitBodyPart);
    SCHEMA_FIELD(Vector, m_vecTotalBulletForce);
    SCHEMA_FIELD(bool, m_bWaitForNoAttack);
    SCHEMA_FIELD(float, m_ignoreLadderJumpTime);
    SCHEMA_FIELD(bool, m_bKilledByHeadshot);
    SCHEMA_FIELD(int32_t, m_LastHitBox);
    SCHEMA_FIELD(CCSBot*, m_pBot);
    SCHEMA_FIELD(bool, m_bBotAllowActive);
    SCHEMA_FIELD(QAngle, m_thirdPersonHeading);
    SCHEMA_FIELD(float, m_flSlopeDropOffset);
    SCHEMA_FIELD(float, m_flSlopeDropHeight);
    SCHEMA_FIELD(Vector, m_vHeadConstraintOffset);
    SCHEMA_FIELD(int32_t, m_nLastPickupPriority);
    SCHEMA_FIELD(float, m_flLastPickupPriorityTime);
    SCHEMA_FIELD(int32_t, m_ArmorValue);
    SCHEMA_FIELD(uint16_t, m_unCurrentEquipmentValue);
    SCHEMA_FIELD(uint16_t, m_unRoundStartEquipmentValue);
    SCHEMA_FIELD(uint16_t, m_unFreezetimeEndEquipmentValue);
    SCHEMA_FIELD(int32_t, m_iLastWeaponFireUsercmd);
    SCHEMA_FIELD(bool, m_bIsSpawning);
    SCHEMA_FIELD(int32_t, m_iDeathFlags);
    SCHEMA_FIELD(bool, m_bHasDeathInfo);
    SCHEMA_FIELD(float, m_flDeathInfoTime);
    SCHEMA_FIELD(Vector, m_vecDeathInfoOrigin);
    SCHEMA_FIELD_POINTER(uint32_t, m_vecPlayerPatchEconIndices);
    SCHEMA_FIELD(Color, m_GunGameImmunityColor);
    SCHEMA_FIELD(float, m_grenadeParameterStashTime);
    SCHEMA_FIELD(bool, m_bGrenadeParametersStashed);
    SCHEMA_FIELD(QAngle, m_angStashedShootAngles);
    SCHEMA_FIELD(Vector, m_vecStashedGrenadeThrowPosition);
    SCHEMA_FIELD(Vector, m_vecStashedVelocity);
    SCHEMA_FIELD_POINTER(QAngle, m_angShootAngleHistory);
    SCHEMA_FIELD_POINTER(Vector, m_vecThrowPositionHistory);
    SCHEMA_FIELD_POINTER(Vector, m_vecVelocityHistory);
    SCHEMA_FIELD(CUtlVector<PredictedDamageTag_t>, m_PredictedDamageTags);
    SCHEMA_FIELD(int32_t, m_nHighestAppliedDamageTagTick);
    SCHEMA_FIELD(bool, m_bCommittingSuicideOnTeamChange);
    SCHEMA_FIELD(bool, m_wasNotKilledNaturally);
    SCHEMA_FIELD(float, m_fImmuneToGunGameDamageTime);
    SCHEMA_FIELD(bool, m_bGunGameImmunity);
    SCHEMA_FIELD(float, m_fMolotovDamageTime);
    SCHEMA_FIELD(QAngle, m_angEyeAngles);

public:
    /// <summary>Get controller.</summary>
    CCSPlayerController* GetController();
    /// <summary>Get default controller.</summary>
    CCSPlayerController* GetDefaultController();
    /// <summary>Get original controller.</summary>
    CCSPlayerController* GetOriginalController();

public:
    static CCSPlayerPawn* New(const char* className)
    {
        return CBaseEntity::New<CCSPlayerPawn>(className);
    }

    static CCSPlayerPawn* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSPlayerPawn>(iIndex);
    }

    static CCSPlayerPawn* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
