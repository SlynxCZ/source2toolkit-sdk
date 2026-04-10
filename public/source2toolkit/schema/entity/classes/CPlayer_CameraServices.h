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

#include "audioparams_t.h"
#include "CPlayerPawnComponent.h"
#include "fogplayerparams_t.h"

class CBaseEntity;
class CColorCorrection;
class CEnvSoundscapeTriggerable;
class CPostProcessingVolume;
class CTonemapController2;

class CPlayer_CameraServices : public CPlayerPawnComponent
{
public:
    DECLARE_SCHEMA_CLASS(CPlayer_CameraServices);

    SCHEMA_FIELD(QAngle, m_vecCsViewPunchAngle);
    SCHEMA_FIELD(int32_t, m_nCsViewPunchAngleTick);
    SCHEMA_FIELD(float, m_flCsViewPunchAngleTickRatio);
    SCHEMA_FIELD(fogplayerparams_t, m_PlayerFog);
    SCHEMA_FIELD(CHandle<CColorCorrection>, m_hColorCorrectionCtrl);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hViewEntity);
    SCHEMA_FIELD(CHandle<CTonemapController2>, m_hTonemapController);
    SCHEMA_FIELD(audioparams_t, m_audio);
    SCHEMA_FIELD(CUtlVector<CHandle<CPostProcessingVolume>>, m_PostProcessingVolumes);
    SCHEMA_FIELD(float, m_flOldPlayerZ);
    SCHEMA_FIELD(float, m_flOldPlayerViewOffsetZ);
    SCHEMA_FIELD(CUtlVector<CHandle<CEnvSoundscapeTriggerable>>, m_hTriggerSoundscapeList);
};
