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

#ifndef _INCLUDE_ICOLORCORRECTION_H
#define _INCLUDE_ICOLORCORRECTION_H

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

class CColorCorrection;

class IColorCorrection : public virtual IBaseEntity
{
public:
    virtual ~IColorCorrection() = default;

    virtual float& FadeInDuration() = 0;
    virtual void FadeInDurationUpdated() = 0;
    virtual float& FadeOutDuration() = 0;
    virtual void FadeOutDurationUpdated() = 0;
    virtual float& StartFadeInWeight() = 0;
    virtual void StartFadeInWeightUpdated() = 0;
    virtual float& StartFadeOutWeight() = 0;
    virtual void StartFadeOutWeightUpdated() = 0;
    virtual float& TimeStartFadeIn() = 0;
    virtual void TimeStartFadeInUpdated() = 0;
    virtual float& TimeStartFadeOut() = 0;
    virtual void TimeStartFadeOutUpdated() = 0;
    virtual float& MaxWeight() = 0;
    virtual void MaxWeightUpdated() = 0;
    virtual bool& StartDisabled() = 0;
    virtual void StartDisabledUpdated() = 0;
    virtual bool& Enabled() = 0;
    virtual void EnabledUpdated() = 0;
    virtual bool& Master() = 0;
    virtual void MasterUpdated() = 0;
    virtual bool& ClientSide() = 0;
    virtual void ClientSideUpdated() = 0;
    virtual bool& Exclusive() = 0;
    virtual void ExclusiveUpdated() = 0;
    virtual float& MinFalloff() = 0;
    virtual void MinFalloffUpdated() = 0;
    virtual float& MaxFalloff() = 0;
    virtual void MaxFalloffUpdated() = 0;
    virtual float& CurWeight() = 0;
    virtual void CurWeightUpdated() = 0;
    virtual char* NetlookupFilename() = 0;
    virtual CUtlSymbolLarge& LookupFilename() = 0;
    virtual void LookupFilenameUpdated() = 0;
    static IColorCorrection* FromOriginal(CColorCorrection* p);
    static IColorCorrection* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_ICOLORCORRECTION_H
