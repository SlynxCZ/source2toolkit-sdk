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

#ifndef _INCLUDE_ICSPLAYER_RADIOSERVICES_H
#define _INCLUDE_ICSPLAYER_RADIOSERVICES_H

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

#include "IPlayerPawnComponent.h"

class CCSPlayer_RadioServices;

class ICSPlayer_RadioServices : public virtual IPlayerPawnComponent
{
public:
    virtual ~ICSPlayer_RadioServices() = default;
    CCSPlayer_RadioServices* GetOriginal() { return reinterpret_cast<CCSPlayer_RadioServices*>(IEntityInstance::GetOriginal()); }

    virtual float& GotHostageTalkTimer() = 0;
    virtual void GotHostageTalkTimerUpdated() = 0;
    virtual float& DefusingTalkTimer() = 0;
    virtual void DefusingTalkTimerUpdated() = 0;
    virtual float& C4PlantTalkTimer() = 0;
    virtual void C4PlantTalkTimerUpdated() = 0;
    virtual float* RadioTokenSlots() = 0;
    virtual bool& IgnoreRadio() = 0;
    virtual void IgnoreRadioUpdated() = 0;
    static ICSPlayer_RadioServices* FromOriginal(CCSPlayer_RadioServices* p);
};

#endif // _INCLUDE_ICSPLAYER_RADIOSERVICES_H
