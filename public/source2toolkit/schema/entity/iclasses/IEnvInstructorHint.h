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

#ifndef _INCLUDE_IENVINSTRUCTORHINT_H
#define _INCLUDE_IENVINSTRUCTORHINT_H

#pragma once

#include <cstdint>

#include "IPointEntity.h"

class IEnvInstructorHint : public virtual IPointEntity
{
public:
    virtual ~IEnvInstructorHint() = default;

    virtual CUtlSymbolLarge& Name() = 0;
    virtual void NameUpdated() = 0;
    virtual CUtlSymbolLarge& Replace_Key() = 0;
    virtual void Replace_KeyUpdated() = 0;
    virtual CUtlSymbolLarge& HintTargetEntity() = 0;
    virtual void HintTargetEntityUpdated() = 0;
    virtual int32_t& Timeout() = 0;
    virtual void TimeoutUpdated() = 0;
    virtual int32_t& DisplayLimit() = 0;
    virtual void DisplayLimitUpdated() = 0;
    virtual CUtlSymbolLarge& Icon_Onscreen() = 0;
    virtual void Icon_OnscreenUpdated() = 0;
    virtual CUtlSymbolLarge& Icon_Offscreen() = 0;
    virtual void Icon_OffscreenUpdated() = 0;
    virtual CUtlSymbolLarge& Caption() = 0;
    virtual void CaptionUpdated() = 0;
    virtual CUtlSymbolLarge& ActivatorCaption() = 0;
    virtual void ActivatorCaptionUpdated() = 0;
    virtual Color& Color() = 0;
    virtual void ColorUpdated() = 0;
    virtual float& IconOffset() = 0;
    virtual void IconOffsetUpdated() = 0;
    virtual float& Range() = 0;
    virtual void RangeUpdated() = 0;
    virtual uint8_t& PulseOption() = 0;
    virtual void PulseOptionUpdated() = 0;
    virtual uint8_t& AlphaOption() = 0;
    virtual void AlphaOptionUpdated() = 0;
    virtual uint8_t& ShakeOption() = 0;
    virtual void ShakeOptionUpdated() = 0;
    virtual bool& Static() = 0;
    virtual void StaticUpdated() = 0;
    virtual bool& NoOffscreen() = 0;
    virtual void NoOffscreenUpdated() = 0;
    virtual bool& ForceCaption() = 0;
    virtual void ForceCaptionUpdated() = 0;
    virtual int32_t& InstanceType() = 0;
    virtual void InstanceTypeUpdated() = 0;
    virtual bool& SuppressRest() = 0;
    virtual void SuppressRestUpdated() = 0;
    virtual CUtlSymbolLarge& Binding() = 0;
    virtual void BindingUpdated() = 0;
    virtual bool& AllowNoDrawTarget() = 0;
    virtual void AllowNoDrawTargetUpdated() = 0;
    virtual bool& AutoStart() = 0;
    virtual void AutoStartUpdated() = 0;
    virtual bool& LocalPlayerOnly() = 0;
    virtual void LocalPlayerOnlyUpdated() = 0;
};

#endif // _INCLUDE_IENVINSTRUCTORHINT_H
