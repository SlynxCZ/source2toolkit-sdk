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

#ifndef _INCLUDE_ICSGO_TEAMPREVIEWCHARACTERPOSITION_H
#define _INCLUDE_ICSGO_TEAMPREVIEWCHARACTERPOSITION_H

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
#include <cstdint>

#include "IBaseEntity.h"

class CEconItemView;

class ICSGO_TeamPreviewCharacterPosition : public virtual IBaseEntity
{
public:
    virtual ~ICSGO_TeamPreviewCharacterPosition() = default;

    virtual int32_t& Variant() = 0;
    virtual void VariantUpdated() = 0;
    virtual int32_t& Random() = 0;
    virtual void RandomUpdated() = 0;
    virtual int32_t& Ordinal() = 0;
    virtual void OrdinalUpdated() = 0;
    virtual CUtlString& WeaponName() = 0;
    virtual void WeaponNameUpdated() = 0;
    virtual uint64_t& Xuid() = 0;
    virtual void XuidUpdated() = 0;
    virtual CEconItemView& AgentItem() = 0;
    virtual void AgentItemUpdated() = 0;
    virtual CEconItemView& GlovesItem() = 0;
    virtual void GlovesItemUpdated() = 0;
    virtual CEconItemView& WeaponItem() = 0;
    virtual void WeaponItemUpdated() = 0;
};

#endif // _INCLUDE_ICSGO_TEAMPREVIEWCHARACTERPOSITION_H
