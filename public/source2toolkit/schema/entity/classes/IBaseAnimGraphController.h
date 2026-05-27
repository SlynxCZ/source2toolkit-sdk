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

#ifndef _INCLUDE_IBASEANIMGRAPHCONTROLLER_H
#define _INCLUDE_IBASEANIMGRAPHCONTROLLER_H

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
#include <cstdint>

#include "ISkeletonAnimationController.h"

#include "../enums/AnimLoopMode_t.h"
#include "../enums/AnimationAlgorithm_t.h"
#include "../enums/SequenceFinishNotifyState_t.h"

class AnimGraph2SerializedPoseRecipeSlot_t;
class CBaseAnimGraph;
class CNmGraphInstance;
class ExternalAnimGraphHandle_t;
class ExternalAnimGraph_t;
class InfoForResourceTypeCNmGraphDefinition;
class ResourceId_t;

class IBaseAnimGraphController : public virtual ISkeletonAnimationController
{
public:
    virtual ~IBaseAnimGraphController() = default;

    virtual AnimationAlgorithm_t& AnimationAlgorithm() = 0;
    virtual void AnimationAlgorithmUpdated() = 0;
    virtual ExternalAnimGraphHandle_t& NextExternalGraphHandle() = 0;
    virtual void NextExternalGraphHandleUpdated() = 0;
    virtual CUtlVector<CGlobalSymbol>& SecondarySkeletonSlotIDs() = 0;
    virtual void SecondarySkeletonSlotIDsUpdated() = 0;
    virtual CUtlVector<CHandle<CBaseAnimGraph>>& SecondarySkeletons() = 0;
    virtual void SecondarySkeletonsUpdated() = 0;
    virtual int32_t& SecondarySkeletonMasterCount() = 0;
    virtual void SecondarySkeletonMasterCountUpdated() = 0;
    virtual float& SoundSyncTime() = 0;
    virtual void SoundSyncTimeUpdated() = 0;
    virtual uint32_t& ActiveIKChainMask() = 0;
    virtual void ActiveIKChainMaskUpdated() = 0;
    virtual int32_t& Sequence() = 0;
    virtual void SequenceUpdated() = 0;
    virtual float& SeqStartTime() = 0;
    virtual void SeqStartTimeUpdated() = 0;
    virtual float& SeqFixedCycle() = 0;
    virtual void SeqFixedCycleUpdated() = 0;
    virtual AnimLoopMode_t& AnimLoopMode() = 0;
    virtual void AnimLoopModeUpdated() = 0;
    virtual float& PlaybackRate() = 0;
    virtual void PlaybackRateUpdated() = 0;
    virtual SequenceFinishNotifyState_t& NotifyState() = 0;
    virtual void NotifyStateUpdated() = 0;
    virtual bool& NetworkedAnimationInputsChanged() = 0;
    virtual void NetworkedAnimationInputsChangedUpdated() = 0;
    virtual bool& NetworkedSequenceChanged() = 0;
    virtual void NetworkedSequenceChangedUpdated() = 0;
    virtual bool& LastUpdateSkipped() = 0;
    virtual void LastUpdateSkippedUpdated() = 0;
    virtual bool& SequenceFinished() = 0;
    virtual void SequenceFinishedUpdated() = 0;
    virtual int32_t& PrevAnimUpdateTick() = 0;
    virtual void PrevAnimUpdateTickUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCNmGraphDefinition>& GraphDefinitionAG2() = 0;
    virtual void GraphDefinitionAG2Updated() = 0;
    virtual CUtlVector<AnimGraph2SerializedPoseRecipeSlot_t>& SerializePoseRecipeAG2Slots() = 0;
    virtual void SerializePoseRecipeAG2SlotsUpdated() = 0;
    virtual CUtlVector<uint8_t>& SerializePoseRecipeAG2Dynamic() = 0;
    virtual void SerializePoseRecipeAG2DynamicUpdated() = 0;
    virtual uint32_t& SerializePoseRecipeAG2ActiveSlot() = 0;
    virtual void SerializePoseRecipeAG2ActiveSlotUpdated() = 0;
    virtual int32_t& SerializePoseRecipeVersionAG2() = 0;
    virtual void SerializePoseRecipeVersionAG2Updated() = 0;
    virtual int32_t& ServerGraphInstanceIteration() = 0;
    virtual void ServerGraphInstanceIterationUpdated() = 0;
    virtual int32_t& ServerSerializationContextIteration() = 0;
    virtual void ServerSerializationContextIterationUpdated() = 0;
    virtual ResourceId_t& PrimaryGraphId() = 0;
    virtual void PrimaryGraphIdUpdated() = 0;
    virtual CUtlVector<ResourceId_t>& ExternalGraphIds() = 0;
    virtual void ExternalGraphIdsUpdated() = 0;
    virtual CUtlVector<ResourceId_t>& ExternalClipIds() = 0;
    virtual void ExternalClipIdsUpdated() = 0;
    virtual CGlobalSymbol& AnimGraph2Identifier() = 0;
    virtual void AnimGraph2IdentifierUpdated() = 0;
    virtual CNmGraphInstance*& GraphInstanceAG2() = 0;
    virtual void GraphInstanceAG2Updated() = 0;
    virtual CUtlVector<ExternalAnimGraph_t>& ExternalGraphs() = 0;
    virtual void ExternalGraphsUpdated() = 0;
};

#endif // _INCLUDE_IBASEANIMGRAPHCONTROLLER_H
