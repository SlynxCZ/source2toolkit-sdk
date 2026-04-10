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

#include "CBaseCombatCharacter.h"
#include "sky3dparams_t.h"
#include "sndopvarlatchdata_t.h"
#include "ViewAngleServerChange_t.h"

class CAI_Expresser;
class CBasePlayerController;
class CBasePlayerWeapon;
class CPlayer_AutoaimServices;
class CPlayer_CameraServices;
class CPlayer_FlashlightServices;
class CPlayer_ItemServices;
class CPlayer_MovementServices;
class CPlayer_ObserverServices;
class CPlayer_UseServices;
class CPlayer_WaterServices;
class CPlayer_WeaponServices;

class CBasePlayerPawn : public CBaseCombatCharacter
{
public:
    DECLARE_SCHEMA_CLASS(CBasePlayerPawn);

    SCHEMA_FIELD(CPlayer_WeaponServices*, m_pWeaponServices);
    SCHEMA_FIELD(CPlayer_ItemServices*, m_pItemServices);
    SCHEMA_FIELD(CPlayer_AutoaimServices*, m_pAutoaimServices);
    SCHEMA_FIELD(CPlayer_ObserverServices*, m_pObserverServices);
    SCHEMA_FIELD(CPlayer_WaterServices*, m_pWaterServices);
    SCHEMA_FIELD(CPlayer_UseServices*, m_pUseServices);
    SCHEMA_FIELD(CPlayer_FlashlightServices*, m_pFlashlightServices);
    SCHEMA_FIELD(CPlayer_CameraServices*, m_pCameraServices);
    SCHEMA_FIELD(CPlayer_MovementServices*, m_pMovementServices);
    SCHEMA_FIELD(CUtlVector<ViewAngleServerChange_t>, m_ServerViewAngleChanges);
    SCHEMA_FIELD(QAngle, v_angle);
    SCHEMA_FIELD(QAngle, v_anglePrevious);
    SCHEMA_FIELD(uint32_t, m_iHideHUD);
    SCHEMA_FIELD(sky3dparams_t, m_skybox3d);
    SCHEMA_FIELD(float, m_fTimeLastHurt);
    SCHEMA_FIELD(float, m_flDeathTime);
    SCHEMA_FIELD(float, m_fNextSuicideTime);
    SCHEMA_FIELD(bool, m_fInitHUD);
    SCHEMA_FIELD(CAI_Expresser*, m_pExpresser);
    SCHEMA_FIELD(CHandle<CBasePlayerController>, m_hController);
    SCHEMA_FIELD(CHandle<CBasePlayerController>, m_hDefaultController);
    SCHEMA_FIELD(float, m_fHltvReplayDelay);
    SCHEMA_FIELD(float, m_fHltvReplayEnd);
    SCHEMA_FIELD(CEntityIndex, m_iHltvReplayEntity);
    SCHEMA_FIELD(CUtlVector<sndopvarlatchdata_t>, m_sndOpvarLatchData);

public:
    /// <summary>Force suicide.</summary>
    void CommitSuicide(bool bExplode, bool bForce);
    /// <summary>Remove weapon from player.</summary>
    void RemovePlayerItem(CBasePlayerWeapon* pWeapon);

public:
    static CBasePlayerPawn* New(const char* className)
    {
        return CBaseEntity::New<CBasePlayerPawn>(className);
    }

    static CBasePlayerPawn* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBasePlayerPawn>(iIndex);
    }

    static CBasePlayerPawn* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
