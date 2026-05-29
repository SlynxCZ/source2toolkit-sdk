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

#ifndef _INCLUDE_IDAMAGERECORD_H
#define _INCLUDE_IDAMAGERECORD_H

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

#include "../enums/EKillTypes_t.h"

class CCSPlayerController;
class CCSPlayerPawn;
class CDamageRecord;

class IDamageRecord
{
public:
    virtual ~IDamageRecord() = default;
    CDamageRecord* GetOriginal() { return reinterpret_cast<CDamageRecord*>(IEntityInstance::GetOriginal()); }

    virtual CHandle<CCSPlayerPawn>& PlayerDamager() = 0;
    virtual void PlayerDamagerUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& PlayerRecipient() = 0;
    virtual void PlayerRecipientUpdated() = 0;
    virtual CHandle<CCSPlayerController>& PlayerControllerDamager() = 0;
    virtual void PlayerControllerDamagerUpdated() = 0;
    virtual CHandle<CCSPlayerController>& PlayerControllerRecipient() = 0;
    virtual void PlayerControllerRecipientUpdated() = 0;
    virtual CUtlString& PlayerDamagerName() = 0;
    virtual void PlayerDamagerNameUpdated() = 0;
    virtual CUtlString& PlayerRecipientName() = 0;
    virtual void PlayerRecipientNameUpdated() = 0;
    virtual uint64_t& DamagerXuid() = 0;
    virtual void DamagerXuidUpdated() = 0;
    virtual uint64_t& RecipientXuid() = 0;
    virtual void RecipientXuidUpdated() = 0;
    virtual float& BulletsDamage() = 0;
    virtual void BulletsDamageUpdated() = 0;
    virtual float& Damage() = 0;
    virtual void DamageUpdated() = 0;
    virtual float& ActualHealthRemoved() = 0;
    virtual void ActualHealthRemovedUpdated() = 0;
    virtual int32_t& NumHits() = 0;
    virtual void NumHitsUpdated() = 0;
    virtual int32_t& LastBulletUpdate() = 0;
    virtual void LastBulletUpdateUpdated() = 0;
    virtual bool& IsOtherEnemy() = 0;
    virtual void IsOtherEnemyUpdated() = 0;
    virtual ::EKillTypes_t& KillType() = 0;
    virtual void KillTypeUpdated() = 0;
    static IDamageRecord* FromOriginal(CDamageRecord* p);
};

#endif // _INCLUDE_IDAMAGERECORD_H
