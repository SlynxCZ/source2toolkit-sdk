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

#ifndef _INCLUDE_IFUNCLADDER_H
#define _INCLUDE_IFUNCLADDER_H

#pragma once

#include <cstdint>

#include "IBaseModelEntity.h"

class CInfoLadderDismount;

class IFuncLadder : public virtual IBaseModelEntity
{
public:
    virtual ~IFuncLadder() = default;

    virtual Vector& LadderDir() = 0;
    virtual void LadderDirUpdated() = 0;
    virtual CUtlVector<CHandle<CInfoLadderDismount>>& Dismounts() = 0;
    virtual void DismountsUpdated() = 0;
    virtual Vector& LocalTop() = 0;
    virtual void LocalTopUpdated() = 0;
    virtual Vector& PlayerMountPositionTop() = 0;
    virtual void PlayerMountPositionTopUpdated() = 0;
    virtual Vector& PlayerMountPositionBottom() = 0;
    virtual void PlayerMountPositionBottomUpdated() = 0;
    virtual float& AutoRideSpeed() = 0;
    virtual void AutoRideSpeedUpdated() = 0;
    virtual bool& Disabled() = 0;
    virtual void DisabledUpdated() = 0;
    virtual bool& FakeLadder() = 0;
    virtual void FakeLadderUpdated() = 0;
    virtual bool& HasSlack() = 0;
    virtual void HasSlackUpdated() = 0;
    virtual CUtlSymbolLarge& SurfacePropName() = 0;
    virtual void SurfacePropNameUpdated() = 0;
    virtual CEntityIOOutput& OnPlayerGotOnLadder() = 0;
    virtual void OnPlayerGotOnLadderUpdated() = 0;
    virtual CEntityIOOutput& OnPlayerGotOffLadder() = 0;
    virtual void OnPlayerGotOffLadderUpdated() = 0;
};

#endif // _INCLUDE_IFUNCLADDER_H
