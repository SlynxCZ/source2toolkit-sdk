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

#ifndef _INCLUDE_IVOTECONTROLLER_H
#define _INCLUDE_IVOTECONTROLLER_H

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

#include "IBaseEntity.h"

class CBaseIssue;
class CVoteController;
class CountdownTimer;

class IVoteController : public virtual IBaseEntity
{
public:
    virtual ~IVoteController() = default;
    CVoteController* GetOriginal() { return reinterpret_cast<CVoteController*>(IEntityInstance::GetOriginal()); }

    virtual int32_t& ActiveIssueIndex() = 0;
    virtual void ActiveIssueIndexUpdated() = 0;
    virtual int32_t& OnlyTeamToVote() = 0;
    virtual void OnlyTeamToVoteUpdated() = 0;
    virtual int32_t* VoteOptionCount() = 0;
    virtual int32_t& PotentialVotes() = 0;
    virtual void PotentialVotesUpdated() = 0;
    virtual bool& IsYesNoVote() = 0;
    virtual void IsYesNoVoteUpdated() = 0;
    virtual ::CountdownTimer& AcceptingVotesTimer() = 0;
    virtual void AcceptingVotesTimerUpdated() = 0;
    virtual ::CountdownTimer& ExecuteCommandTimer() = 0;
    virtual void ExecuteCommandTimerUpdated() = 0;
    virtual ::CountdownTimer& ResetVoteTimer() = 0;
    virtual void ResetVoteTimerUpdated() = 0;
    virtual int32_t* VotesCast() = 0;
    virtual int32_t& PlayerHoldingVote() = 0;
    virtual void PlayerHoldingVoteUpdated() = 0;
    virtual int32_t& PlayerOverrideForVote() = 0;
    virtual void PlayerOverrideForVoteUpdated() = 0;
    virtual int32_t& HighestCountIndex() = 0;
    virtual void HighestCountIndexUpdated() = 0;
    virtual CUtlVector<CBaseIssue*>& PotentialIssues() = 0;
    virtual void PotentialIssuesUpdated() = 0;
    virtual CUtlVector<char*>& VoteOptions() = 0;
    virtual void VoteOptionsUpdated() = 0;
    static IVoteController* FromOriginal(CVoteController* p);
};

#endif // _INCLUDE_IVOTECONTROLLER_H
