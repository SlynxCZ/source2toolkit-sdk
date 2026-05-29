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

#ifndef _INCLUDE_IAI_EXPRESSER_H
#define _INCLUDE_IAI_EXPRESSER_H

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

#include "IEntityInstance.h"

class CAI_Expresser;
class CBaseModelEntity;

class IAI_Expresser
{
public:
    virtual ~IAI_Expresser() = default;
    virtual CAI_Expresser* GetOriginal() const = 0;

    virtual float& StopTalkTime() = 0;
    virtual void StopTalkTimeUpdated() = 0;
    virtual float& StopTalkTimeWithoutDelay() = 0;
    virtual void StopTalkTimeWithoutDelayUpdated() = 0;
    virtual float& QueuedSpeechTime() = 0;
    virtual void QueuedSpeechTimeUpdated() = 0;
    virtual float& BlockedTalkTime() = 0;
    virtual void BlockedTalkTimeUpdated() = 0;
    virtual int32_t& VoicePitch() = 0;
    virtual void VoicePitchUpdated() = 0;
    virtual float& LastTimeAcceptedSpeak() = 0;
    virtual void LastTimeAcceptedSpeakUpdated() = 0;
    virtual bool& AllowSpeakingInterrupts() = 0;
    virtual void AllowSpeakingInterruptsUpdated() = 0;
    virtual bool& ConsiderSceneInvolvementAsSpeech() = 0;
    virtual void ConsiderSceneInvolvementAsSpeechUpdated() = 0;
    virtual bool& SceneEntityDisabled() = 0;
    virtual void SceneEntityDisabledUpdated() = 0;
    virtual int32_t& LastSpokenPriority() = 0;
    virtual void LastSpokenPriorityUpdated() = 0;
    virtual CBaseModelEntity*& Outer() = 0;
    virtual void OuterUpdated() = 0;
    static IAI_Expresser* FromOriginal(CAI_Expresser* p);
    static IAI_Expresser* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IAI_EXPRESSER_H
