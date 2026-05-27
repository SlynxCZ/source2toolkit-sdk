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

#ifndef _INCLUDE_IMAPVETOPICKCONTROLLER_H
#define _INCLUDE_IMAPVETOPICKCONTROLLER_H

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

#include "IBaseEntity.h"

class IMapVetoPickController : public virtual IBaseEntity
{
public:
    virtual ~IMapVetoPickController() = default;

    virtual bool& PlayedIntroVcd() = 0;
    virtual void PlayedIntroVcdUpdated() = 0;
    virtual bool& NeedToPlayFiveSecondsRemaining() = 0;
    virtual void NeedToPlayFiveSecondsRemainingUpdated() = 0;
    virtual double& DblPreMatchDraftSequenceTime() = 0;
    virtual void DblPreMatchDraftSequenceTimeUpdated() = 0;
    virtual bool& PreMatchDraftStateChanged() = 0;
    virtual void PreMatchDraftStateChangedUpdated() = 0;
    virtual int32_t& DraftType() = 0;
    virtual void DraftTypeUpdated() = 0;
    virtual int32_t& TeamWinningCoinToss() = 0;
    virtual void TeamWinningCoinTossUpdated() = 0;
    virtual int32_t* TeamWithFirstChoice() = 0;
    virtual int32_t* VoteMapIdsList() = 0;
    virtual int32_t* AccountIDs() = 0;
    virtual int32_t* MapId0() = 0;
    virtual int32_t* MapId1() = 0;
    virtual int32_t* MapId2() = 0;
    virtual int32_t* MapId3() = 0;
    virtual int32_t* MapId4() = 0;
    virtual int32_t* MapId5() = 0;
    virtual int32_t* StartingSide0() = 0;
    virtual int32_t& CurrentPhase() = 0;
    virtual void CurrentPhaseUpdated() = 0;
    virtual int32_t& PhaseStartTick() = 0;
    virtual void PhaseStartTickUpdated() = 0;
    virtual int32_t& PhaseDurationTicks() = 0;
    virtual void PhaseDurationTicksUpdated() = 0;
};

#endif // _INCLUDE_IMAPVETOPICKCONTROLLER_H
