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

#ifndef _INCLUDE_IPLAYERSPRAYDECAL_H
#define _INCLUDE_IPLAYERSPRAYDECAL_H

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

#include "IModelPointEntity.h"

class CPlayerSprayDecal;

class IPlayerSprayDecal : public virtual IModelPointEntity
{
public:
    virtual ~IPlayerSprayDecal() = default;
    CPlayerSprayDecal* GetOriginal() { return reinterpret_cast<CPlayerSprayDecal*>(IEntityInstance::GetOriginal()); }

    virtual int32_t& UniqueID() = 0;
    virtual void UniqueIDUpdated() = 0;
    virtual uint32_t& AccountID() = 0;
    virtual void AccountIDUpdated() = 0;
    virtual uint32_t& TraceID() = 0;
    virtual void TraceIDUpdated() = 0;
    virtual uint32_t& RtGcTime() = 0;
    virtual void RtGcTimeUpdated() = 0;
    virtual Vector& EndPos() = 0;
    virtual void EndPosUpdated() = 0;
    virtual Vector& Start() = 0;
    virtual void StartUpdated() = 0;
    virtual Vector& Left() = 0;
    virtual void LeftUpdated() = 0;
    virtual Vector& Normal() = 0;
    virtual void NormalUpdated() = 0;
    virtual int32_t& Player() = 0;
    virtual void PlayerUpdated() = 0;
    virtual int32_t& Entity() = 0;
    virtual void EntityUpdated() = 0;
    virtual int32_t& Hitbox() = 0;
    virtual void HitboxUpdated() = 0;
    virtual float& CreationTime() = 0;
    virtual void CreationTimeUpdated() = 0;
    virtual int32_t& TintID() = 0;
    virtual void TintIDUpdated() = 0;
    virtual uint8_t& Version() = 0;
    virtual void VersionUpdated() = 0;
    virtual uint8_t* Signature() = 0;
    static IPlayerSprayDecal* FromOriginal(CPlayerSprayDecal* p);
};

#endif // _INCLUDE_IPLAYERSPRAYDECAL_H
