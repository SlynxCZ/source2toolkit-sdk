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

#ifndef _INCLUDE_CCSPLAYER_WEAPONSERVICES_H
#define _INCLUDE_CCSPLAYER_WEAPONSERVICES_H

#pragma once

#include "igameevents.h"
#include "ehandle.h"
#include "entityhandle.h"
#include "vector.h"
#include "utlbinaryblock.h"
#include "utlsymbol.h"
#include "utlsymbollarge.h"
#include "utlstring.h"
#include "utlstringtoken.h"
#include "source2toolkit/IToolkitPlugin.h"
#include "source2toolkit/schema/entityio.h"
#include "source2toolkit/schema/schema.h"
#include <cstdint>

#include "CPlayer_WeaponServices.h"

class CBasePlayerWeapon;
class CCSPlayer_ItemServices;

class CCSPlayer_WeaponServices : public CPlayer_WeaponServices
{
public:
    DECLARE_SCHEMA_CLASS_INLINE(CCSPlayer_WeaponServices);

    SCHEMA_FIELD(float, m_flNextAttack);
    SCHEMA_FIELD(CHandle<CBasePlayerWeapon>, m_hSavedWeapon);
    SCHEMA_FIELD(int32_t, m_nTimeToMelee);
    SCHEMA_FIELD(int32_t, m_nTimeToSecondary);
    SCHEMA_FIELD(int32_t, m_nTimeToPrimary);
    SCHEMA_FIELD(int32_t, m_nTimeToSniperRifle);
    SCHEMA_FIELD(bool, m_bIsBeingGivenItem);
    SCHEMA_FIELD(bool, m_bIsPickingUpItemWithUse);
    SCHEMA_FIELD(bool, m_bPickedUpWeapon);
    SCHEMA_FIELD(bool, m_bDisableAutoDeploy);
    SCHEMA_FIELD(bool, m_bIsPickingUpGroundWeapon);
    SCHEMA_FIELD(CUtlVector<uint8_t>, m_networkAnimTiming);
    SCHEMA_FIELD(bool, m_bBlockInspectUntilNextGraphUpdate);

public:
    /// <summary>Checks if player can use weapon (fire and maybe acquire).</summary>
    bool CanUse(CBasePlayerWeapon *pWeapon);
    /// <summary>Drop weapon.</summary>
    void DropWeapon(CBasePlayerWeapon *pWeapon, Vector *pVecTarget = nullptr, Vector *pVelocity = nullptr);
    /// <summary>Probably checks weapon validity after CCSPlayer_ItemServices::GiveNamedItem invoke, may return 2 if CSGameRules()->IsPlayingGunGameDeathmatch, meaning that pWeapon will be deleted.</summary>
    int BumpWeapon(CBasePlayerWeapon *pWeapon);
    /// <summary>Select weapon, If unk1 is equal to 3 some code will be executed.</summary>
    void SelectItem(CBasePlayerWeapon *pWeapon, int unk1 = 0);
    /// <summary>Remove and destroy weapon from player.</summary>
    void Destroy(CBasePlayerWeapon *pWeapon);
};

#endif // _INCLUDE_CCSPLAYER_WEAPONSERVICES_H
