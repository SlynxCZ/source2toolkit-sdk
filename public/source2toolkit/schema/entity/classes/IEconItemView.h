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

#ifndef _INCLUDE_IECONITEMVIEW_H
#define _INCLUDE_IECONITEMVIEW_H

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

class CAttributeList;
class CEconItemView;

class IEconItemView
{
public:
    virtual ~IEconItemView() = default;
    CEconItemView* GetOriginal() { return reinterpret_cast<CEconItemView*>(IEntityInstance::GetOriginal()); }

    virtual uint16_t& ItemDefinitionIndex() = 0;
    virtual void ItemDefinitionIndexUpdated() = 0;
    virtual int32_t& EntityQuality() = 0;
    virtual void EntityQualityUpdated() = 0;
    virtual uint32_t& EntityLevel() = 0;
    virtual void EntityLevelUpdated() = 0;
    virtual uint64_t& ItemID() = 0;
    virtual void ItemIDUpdated() = 0;
    virtual uint32_t& ItemIDHigh() = 0;
    virtual void ItemIDHighUpdated() = 0;
    virtual uint32_t& ItemIDLow() = 0;
    virtual void ItemIDLowUpdated() = 0;
    virtual uint32_t& AccountID() = 0;
    virtual void AccountIDUpdated() = 0;
    virtual uint32_t& InventoryPosition() = 0;
    virtual void InventoryPositionUpdated() = 0;
    virtual bool& Initialized() = 0;
    virtual void InitializedUpdated() = 0;
    virtual ::CAttributeList& AttributeList() = 0;
    virtual void AttributeListUpdated() = 0;
    virtual ::CAttributeList& NetworkedDynamicAttributes() = 0;
    virtual void NetworkedDynamicAttributesUpdated() = 0;
    virtual char* CustomName() = 0;
    virtual char* CustomNameOverride() = 0;
    static IEconItemView* FromOriginal(CEconItemView* p);
};

#endif // _INCLUDE_IECONITEMVIEW_H
