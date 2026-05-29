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

#ifndef _INCLUDE_IPOINTCOMMENTARYNODE_H
#define _INCLUDE_IPOINTCOMMENTARYNODE_H

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

#include "IBaseAnimGraph.h"

class CBaseEntity;
class CPointCommentaryNode;

class IPointCommentaryNode : public virtual IBaseAnimGraph
{
public:
    virtual ~IPointCommentaryNode() = default;
    CPointCommentaryNode* GetOriginal() { return reinterpret_cast<CPointCommentaryNode*>(IEntityInstance::GetOriginal()); }

    virtual CUtlSymbolLarge& PreCommands() = 0;
    virtual void PreCommandsUpdated() = 0;
    virtual CUtlSymbolLarge& PostCommands() = 0;
    virtual void PostCommandsUpdated() = 0;
    virtual CUtlSymbolLarge& CommentaryFile() = 0;
    virtual void CommentaryFileUpdated() = 0;
    virtual CUtlSymbolLarge& ViewTarget() = 0;
    virtual void ViewTargetUpdated() = 0;
    virtual CHandle<CBaseEntity>& ViewTarget() = 0;
    virtual void ViewTargetUpdated() = 0;
    virtual CHandle<CBaseEntity>& ViewTargetAngles() = 0;
    virtual void ViewTargetAnglesUpdated() = 0;
    virtual CUtlSymbolLarge& ViewPosition() = 0;
    virtual void ViewPositionUpdated() = 0;
    virtual CHandle<CBaseEntity>& ViewPosition() = 0;
    virtual void ViewPositionUpdated() = 0;
    virtual CHandle<CBaseEntity>& ViewPositionMover() = 0;
    virtual void ViewPositionMoverUpdated() = 0;
    virtual bool& PreventMovement() = 0;
    virtual void PreventMovementUpdated() = 0;
    virtual bool& UnderCrosshair() = 0;
    virtual void UnderCrosshairUpdated() = 0;
    virtual bool& Unstoppable() = 0;
    virtual void UnstoppableUpdated() = 0;
    virtual float& FinishedTime() = 0;
    virtual void FinishedTimeUpdated() = 0;
    virtual Vector& FinishOrigin() = 0;
    virtual void FinishOriginUpdated() = 0;
    virtual QAngle& OriginalAngles() = 0;
    virtual void OriginalAnglesUpdated() = 0;
    virtual QAngle& FinishAngles() = 0;
    virtual void FinishAnglesUpdated() = 0;
    virtual bool& PreventChangesWhileMoving() = 0;
    virtual void PreventChangesWhileMovingUpdated() = 0;
    virtual bool& Disabled() = 0;
    virtual void DisabledUpdated() = 0;
    virtual Vector& TeleportOrigin() = 0;
    virtual void TeleportOriginUpdated() = 0;
    virtual float& AbortedPlaybackAt() = 0;
    virtual void AbortedPlaybackAtUpdated() = 0;
    virtual ::CEntityIOOutput& OnCommentaryStarted() = 0;
    virtual void OnCommentaryStartedUpdated() = 0;
    virtual ::CEntityIOOutput& OnCommentaryStopped() = 0;
    virtual void OnCommentaryStoppedUpdated() = 0;
    virtual bool& Active() = 0;
    virtual void ActiveUpdated() = 0;
    virtual float& StartTime() = 0;
    virtual void StartTimeUpdated() = 0;
    virtual float& StartTimeInCommentary() = 0;
    virtual void StartTimeInCommentaryUpdated() = 0;
    virtual CUtlSymbolLarge& Title() = 0;
    virtual void TitleUpdated() = 0;
    virtual CUtlSymbolLarge& Speakers() = 0;
    virtual void SpeakersUpdated() = 0;
    virtual int32_t& NodeNumber() = 0;
    virtual void NodeNumberUpdated() = 0;
    virtual int32_t& NodeNumberMax() = 0;
    virtual void NodeNumberMaxUpdated() = 0;
    virtual bool& ListenedTo() = 0;
    virtual void ListenedToUpdated() = 0;
    static IPointCommentaryNode* FromOriginal(CPointCommentaryNode* p);
};

#endif // _INCLUDE_IPOINTCOMMENTARYNODE_H
