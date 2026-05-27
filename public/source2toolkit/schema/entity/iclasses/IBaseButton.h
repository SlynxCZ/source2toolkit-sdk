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

#ifndef _INCLUDE_IBASEBUTTON_H
#define _INCLUDE_IBASEBUTTON_H

#pragma once

#include <cstdint>

#include "IBaseToggle.h"

#include "locksound_t.h"

class CBaseModelEntity;

class IBaseButton : public virtual IBaseToggle
{
public:
    virtual ~IBaseButton() = default;

    virtual QAngle& MoveEntitySpace() = 0;
    virtual void MoveEntitySpaceUpdated() = 0;
    virtual bool& StayPushed() = 0;
    virtual void StayPushedUpdated() = 0;
    virtual bool& Rotating() = 0;
    virtual void RotatingUpdated() = 0;
    virtual locksound_t& Ls() = 0;
    virtual void LsUpdated() = 0;
    virtual CUtlSymbolLarge& UseSound() = 0;
    virtual void UseSoundUpdated() = 0;
    virtual CUtlSymbolLarge& LockedSound() = 0;
    virtual void LockedSoundUpdated() = 0;
    virtual CUtlSymbolLarge& UnlockedSound() = 0;
    virtual void UnlockedSoundUpdated() = 0;
    virtual CUtlSymbolLarge& OverrideAnticipationName() = 0;
    virtual void OverrideAnticipationNameUpdated() = 0;
    virtual bool& Locked() = 0;
    virtual void LockedUpdated() = 0;
    virtual bool& Disabled() = 0;
    virtual void DisabledUpdated() = 0;
    virtual float& UseLockedTime() = 0;
    virtual void UseLockedTimeUpdated() = 0;
    virtual bool& SolidBsp() = 0;
    virtual void SolidBspUpdated() = 0;
    virtual CEntityIOOutput& OnDamaged() = 0;
    virtual void OnDamagedUpdated() = 0;
    virtual CEntityIOOutput& OnPressed() = 0;
    virtual void OnPressedUpdated() = 0;
    virtual CEntityIOOutput& OnUseLocked() = 0;
    virtual void OnUseLockedUpdated() = 0;
    virtual CEntityIOOutput& OnIn() = 0;
    virtual void OnInUpdated() = 0;
    virtual CEntityIOOutput& OnOut() = 0;
    virtual void OnOutUpdated() = 0;
    virtual int32_t& State() = 0;
    virtual void StateUpdated() = 0;
    virtual CEntityHandle& Constraint() = 0;
    virtual void ConstraintUpdated() = 0;
    virtual CEntityHandle& ConstraintParent() = 0;
    virtual void ConstraintParentUpdated() = 0;
    virtual bool& ForceNpcExclude() = 0;
    virtual void ForceNpcExcludeUpdated() = 0;
    virtual CUtlSymbolLarge& GlowEntity() = 0;
    virtual void GlowEntityUpdated() = 0;
    virtual CHandle<CBaseModelEntity>& GlowEntity() = 0;
    virtual void GlowEntityUpdated() = 0;
    virtual bool& Usable() = 0;
    virtual void UsableUpdated() = 0;
    virtual CUtlSymbolLarge& DisplayText() = 0;
    virtual void DisplayTextUpdated() = 0;
};

#endif // _INCLUDE_IBASEBUTTON_H
