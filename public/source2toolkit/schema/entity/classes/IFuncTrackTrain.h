/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
 * AlliedModders LLC. All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
 * AlliedModders LLC give you permission to link the code of this program
 * (as well as its derivative works) to "Counter-Strike 2," "Source 2,"
 * "Steam," and any Game MODs or server software running on software by
 * Valve Corporation. You must obey the GNU General Public License in all
 * respects for all other code used.
 *
 * Additionally, this exception applies to all derivative works unless
 * otherwise stated in LICENSE.txt.
 *
 * Authors:
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

#ifndef _INCLUDE_IFUNCTRACKTRAIN_H
#define _INCLUDE_IFUNCTRACKTRAIN_H

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

#include "IBaseModelEntity.h"

#include "../enums/TrainOrientationType_t.h"
#include "../enums/TrainVelocityType_t.h"

class CFuncTrackTrain;
class CPathTrack;

class IFuncTrackTrain : public virtual IBaseModelEntity
{
public:
    virtual ~IFuncTrackTrain() = default;
    CFuncTrackTrain* GetOriginal() { return reinterpret_cast<CFuncTrackTrain*>(IEntityInstance::GetOriginal()); }

    virtual CHandle<CPathTrack>& Ppath() = 0;
    virtual void PpathUpdated() = 0;
    virtual float& Length() = 0;
    virtual void LengthUpdated() = 0;
    virtual Vector& PosPrev() = 0;
    virtual void PosPrevUpdated() = 0;
    virtual QAngle& Prev() = 0;
    virtual void PrevUpdated() = 0;
    virtual Vector& ControlMins() = 0;
    virtual void ControlMinsUpdated() = 0;
    virtual Vector& ControlMaxs() = 0;
    virtual void ControlMaxsUpdated() = 0;
    virtual Vector& LastBlockPos() = 0;
    virtual void LastBlockPosUpdated() = 0;
    virtual int32_t& LastBlockTick() = 0;
    virtual void LastBlockTickUpdated() = 0;
    virtual float& Volume() = 0;
    virtual void VolumeUpdated() = 0;
    virtual float& Bank() = 0;
    virtual void BankUpdated() = 0;
    virtual float& OldSpeed() = 0;
    virtual void OldSpeedUpdated() = 0;
    virtual float& BlockDamage() = 0;
    virtual void BlockDamageUpdated() = 0;
    virtual float& Height() = 0;
    virtual void HeightUpdated() = 0;
    virtual float& MaxSpeed() = 0;
    virtual void MaxSpeedUpdated() = 0;
    virtual float& Dir() = 0;
    virtual void DirUpdated() = 0;
    virtual CUtlSymbolLarge& SoundMove() = 0;
    virtual void SoundMoveUpdated() = 0;
    virtual CUtlSymbolLarge& SoundMovePing() = 0;
    virtual void SoundMovePingUpdated() = 0;
    virtual CUtlSymbolLarge& SoundStart() = 0;
    virtual void SoundStartUpdated() = 0;
    virtual CUtlSymbolLarge& SoundStop() = 0;
    virtual void SoundStopUpdated() = 0;
    virtual CUtlSymbolLarge& StrPathTarget() = 0;
    virtual void StrPathTargetUpdated() = 0;
    virtual float& MoveSoundMinDuration() = 0;
    virtual void MoveSoundMinDurationUpdated() = 0;
    virtual float& MoveSoundMaxDuration() = 0;
    virtual void MoveSoundMaxDurationUpdated() = 0;
    virtual float& NextMoveSoundTime() = 0;
    virtual void NextMoveSoundTimeUpdated() = 0;
    virtual float& MoveSoundMinPitch() = 0;
    virtual void MoveSoundMinPitchUpdated() = 0;
    virtual float& MoveSoundMaxPitch() = 0;
    virtual void MoveSoundMaxPitchUpdated() = 0;
    virtual ::TrainOrientationType_t& OrientationType() = 0;
    virtual void OrientationTypeUpdated() = 0;
    virtual ::TrainVelocityType_t& VelocityType() = 0;
    virtual void VelocityTypeUpdated() = 0;
    virtual ::CEntityIOOutput& OnStart() = 0;
    virtual void OnStartUpdated() = 0;
    virtual ::CEntityIOOutput& OnNext() = 0;
    virtual void OnNextUpdated() = 0;
    virtual ::CEntityIOOutput& OnArrivedAtDestinationNode() = 0;
    virtual void OnArrivedAtDestinationNodeUpdated() = 0;
    virtual bool& ManualSpeedChanges() = 0;
    virtual void ManualSpeedChangesUpdated() = 0;
    virtual float& DesiredSpeed() = 0;
    virtual void DesiredSpeedUpdated() = 0;
    virtual float& SpeedChangeTime() = 0;
    virtual void SpeedChangeTimeUpdated() = 0;
    virtual float& AccelSpeed() = 0;
    virtual void AccelSpeedUpdated() = 0;
    virtual float& DecelSpeed() = 0;
    virtual void DecelSpeedUpdated() = 0;
    virtual bool& AccelToSpeed() = 0;
    virtual void AccelToSpeedUpdated() = 0;
    virtual float& NextMPSoundTime() = 0;
    virtual void NextMPSoundTimeUpdated() = 0;
    static IFuncTrackTrain* FromOriginal(CFuncTrackTrain* p);
};

#endif // _INCLUDE_IFUNCTRACKTRAIN_H
