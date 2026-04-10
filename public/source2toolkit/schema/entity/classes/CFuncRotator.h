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
#include "../enums/CFuncRotatorRotate_t.h"
#include "RotatorHistoryEntry_t.h"
#include "RotatorQueueEntry_t.h"
#include "../enums/RotatorTargetSpace_t.h"

class CBaseEntity;
class CFuncMover;

class CFuncRotator : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncRotator);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hRotatorTarget);
    SCHEMA_FIELD(bool, m_bIsRotating);
    SCHEMA_FIELD(bool, m_bIsReversing);
    SCHEMA_FIELD(float, m_flTimeToReachMaxSpeed);
    SCHEMA_FIELD(float, m_flTimeToReachZeroSpeed);
    SCHEMA_FIELD(float, m_flDistanceAlongArcTraveled);
    SCHEMA_FIELD(float, m_flTimeToWaitOscillate);
    SCHEMA_FIELD(float, m_flTimeRotationStart);
    SCHEMA_FIELD(Quaternion, m_qLSPrevChange);
    SCHEMA_FIELD(Quaternion, m_qWSPrev);
    SCHEMA_FIELD(Quaternion, m_qWSInit);
    SCHEMA_FIELD(Quaternion, m_qLSInit);
    SCHEMA_FIELD(Quaternion, m_qLSOrientation);
    SCHEMA_FIELD(CEntityIOOutput, m_OnRotationStarted);
    SCHEMA_FIELD(CEntityIOOutput, m_OnRotationCompleted);
    SCHEMA_FIELD(CEntityIOOutput, m_OnOscillate);
    SCHEMA_FIELD(CEntityIOOutput, m_OnOscillateStartArrive);
    SCHEMA_FIELD(CEntityIOOutput, m_OnOscillateStartDepart);
    SCHEMA_FIELD(CEntityIOOutput, m_OnOscillateEndArrive);
    SCHEMA_FIELD(CEntityIOOutput, m_OnOscillateEndDepart);
    SCHEMA_FIELD(bool, m_bOscillateDepart);
    SCHEMA_FIELD(int32_t, m_nOscillateCount);
    SCHEMA_FIELD(CFuncRotator::Rotate_t, m_eRotateType);
    SCHEMA_FIELD(CFuncRotator::Rotate_t, m_ePrevRotateType);
    SCHEMA_FIELD(bool, m_bHasTargetOverride);
    SCHEMA_FIELD(Quaternion, m_qOrientationOverride);
    SCHEMA_FIELD(RotatorTargetSpace_t, m_eSpaceOverride);
    SCHEMA_FIELD(QAngle, m_qAngularVelocity);
    SCHEMA_FIELD(Vector, m_vLookAtForcedUp);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strRotatorTarget);
    SCHEMA_FIELD(bool, m_bRecordHistory);
    SCHEMA_FIELD(CUtlVector<RotatorHistoryEntry_t>, m_vecRotatorHistory);
    SCHEMA_FIELD(bool, m_bReturningToPreviousOrientation);
    SCHEMA_FIELD(CUtlVector<RotatorQueueEntry_t>, m_vecRotatorQueue);
    SCHEMA_FIELD(CUtlVector<RotatorHistoryEntry_t>, m_vecRotatorQueueHistory);
    SCHEMA_FIELD(SolidType_t, m_eSolidType);
    SCHEMA_FIELD(CHandle<CFuncMover>, m_hSpeedFromMover);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSpeedFromMover);
    SCHEMA_FIELD(float, m_flSpeedScale);
    SCHEMA_FIELD(float, m_flMinYawRotation);
    SCHEMA_FIELD(float, m_flMaxYawRotation);

public:
    static CFuncRotator* New(const char* className)
    {
        return CBaseEntity::New<CFuncRotator>(className);
    }

    static CFuncRotator* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncRotator>(iIndex);
    }

    static CFuncRotator* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
