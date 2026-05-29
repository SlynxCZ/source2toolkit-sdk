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

#ifndef _INCLUDE_IMOMENTARYROTBUTTON_H
#define _INCLUDE_IMOMENTARYROTBUTTON_H

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

#include "IRotButton.h"

class CMomentaryRotButton;

class IMomentaryRotButton : public virtual IRotButton
{
public:
    virtual ~IMomentaryRotButton() = default;

    virtual ::CEntityIOOutput& OnUnpressed() = 0;
    virtual void OnUnpressedUpdated() = 0;
    virtual ::CEntityIOOutput& OnFullyOpen() = 0;
    virtual void OnFullyOpenUpdated() = 0;
    virtual ::CEntityIOOutput& OnFullyClosed() = 0;
    virtual void OnFullyClosedUpdated() = 0;
    virtual ::CEntityIOOutput& OnReachedPosition() = 0;
    virtual void OnReachedPositionUpdated() = 0;
    virtual int32_t& LastUsed() = 0;
    virtual void LastUsedUpdated() = 0;
    virtual QAngle& Start() = 0;
    virtual void StartUpdated() = 0;
    virtual QAngle& End() = 0;
    virtual void EndUpdated() = 0;
    virtual float& IdealYaw() = 0;
    virtual void IdealYawUpdated() = 0;
    virtual CUtlSymbolLarge& Noise() = 0;
    virtual void NoiseUpdated() = 0;
    virtual bool& UpdateTarget() = 0;
    virtual void UpdateTargetUpdated() = 0;
    virtual int32_t& Direction() = 0;
    virtual void DirectionUpdated() = 0;
    virtual float& ReturnSpeed() = 0;
    virtual void ReturnSpeedUpdated() = 0;
    virtual float& StartPosition() = 0;
    virtual void StartPositionUpdated() = 0;
    static IMomentaryRotButton* FromOriginal(CMomentaryRotButton* p);
    static IMomentaryRotButton* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IMOMENTARYROTBUTTON_H
