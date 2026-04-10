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

#include "CBaseModelEntity.h"
#include "../enums/TrainOrientationType_t.h"
#include "../enums/TrainVelocityType_t.h"

class CPathTrack;

class CFuncTrackTrain : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncTrackTrain);

    SCHEMA_FIELD(CHandle<CPathTrack>, m_ppath);
    SCHEMA_FIELD(float, m_length);
    SCHEMA_FIELD(Vector, m_vPosPrev);
    SCHEMA_FIELD(QAngle, m_angPrev);
    SCHEMA_FIELD(Vector, m_controlMins);
    SCHEMA_FIELD(Vector, m_controlMaxs);
    SCHEMA_FIELD(Vector, m_lastBlockPos);
    SCHEMA_FIELD(int32_t, m_lastBlockTick);
    SCHEMA_FIELD(float, m_flVolume);
    SCHEMA_FIELD(float, m_flBank);
    SCHEMA_FIELD(float, m_oldSpeed);
    SCHEMA_FIELD(float, m_flBlockDamage);
    SCHEMA_FIELD(float, m_height);
    SCHEMA_FIELD(float, m_maxSpeed);
    SCHEMA_FIELD(float, m_dir);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSoundMove);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSoundMovePing);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSoundStart);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSoundStop);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strPathTarget);
    SCHEMA_FIELD(float, m_flMoveSoundMinDuration);
    SCHEMA_FIELD(float, m_flMoveSoundMaxDuration);
    SCHEMA_FIELD(float, m_flNextMoveSoundTime);
    SCHEMA_FIELD(float, m_flMoveSoundMinPitch);
    SCHEMA_FIELD(float, m_flMoveSoundMaxPitch);
    SCHEMA_FIELD(TrainOrientationType_t, m_eOrientationType);
    SCHEMA_FIELD(TrainVelocityType_t, m_eVelocityType);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStart);
    SCHEMA_FIELD(CEntityIOOutput, m_OnNext);
    SCHEMA_FIELD(CEntityIOOutput, m_OnArrivedAtDestinationNode);
    SCHEMA_FIELD(bool, m_bManualSpeedChanges);
    SCHEMA_FIELD(float, m_flDesiredSpeed);
    SCHEMA_FIELD(float, m_flSpeedChangeTime);
    SCHEMA_FIELD(float, m_flAccelSpeed);
    SCHEMA_FIELD(float, m_flDecelSpeed);
    SCHEMA_FIELD(bool, m_bAccelToSpeed);
    SCHEMA_FIELD(float, m_flNextMPSoundTime);

public:
    static CFuncTrackTrain* New(const char* className)
    {
        return CBaseEntity::New<CFuncTrackTrain>(className);
    }

    static CFuncTrackTrain* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncTrackTrain>(iIndex);
    }

    static CFuncTrackTrain* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
