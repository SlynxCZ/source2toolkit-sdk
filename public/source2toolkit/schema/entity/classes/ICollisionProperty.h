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

#ifndef _INCLUDE_ICOLLISIONPROPERTY_H
#define _INCLUDE_ICOLLISIONPROPERTY_H

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

#include "../enums/SurroundingBoundsType_t.h"

class CCollisionProperty;
class VPhysicsCollisionAttribute_t;

class ICollisionProperty
{
public:
    virtual ~ICollisionProperty() = default;
    virtual CCollisionProperty* GetOriginal() const = 0;

    virtual ::VPhysicsCollisionAttribute_t& CollisionAttribute() = 0;
    virtual void CollisionAttributeUpdated() = 0;
    virtual Vector& Mins() = 0;
    virtual void MinsUpdated() = 0;
    virtual Vector& Maxs() = 0;
    virtual void MaxsUpdated() = 0;
    virtual uint8_t& SolidFlags() = 0;
    virtual void SolidFlagsUpdated() = 0;
    virtual ::SolidType_t& SolidType() = 0;
    virtual void SolidTypeUpdated() = 0;
    virtual uint8_t& TriggerBloat() = 0;
    virtual void TriggerBloatUpdated() = 0;
    virtual ::SurroundingBoundsType_t& SurroundType() = 0;
    virtual void SurroundTypeUpdated() = 0;
    virtual uint8_t& CollisionGroup() = 0;
    virtual void CollisionGroupUpdated() = 0;
    virtual uint8_t& EnablePhysics() = 0;
    virtual void EnablePhysicsUpdated() = 0;
    virtual float& BoundingRadius() = 0;
    virtual void BoundingRadiusUpdated() = 0;
    virtual Vector& SpecifiedSurroundingMins() = 0;
    virtual void SpecifiedSurroundingMinsUpdated() = 0;
    virtual Vector& SpecifiedSurroundingMaxs() = 0;
    virtual void SpecifiedSurroundingMaxsUpdated() = 0;
    virtual Vector& SurroundingMaxs() = 0;
    virtual void SurroundingMaxsUpdated() = 0;
    virtual Vector& SurroundingMins() = 0;
    virtual void SurroundingMinsUpdated() = 0;
    virtual Vector& CapsuleCenter1() = 0;
    virtual void CapsuleCenter1Updated() = 0;
    virtual Vector& CapsuleCenter2() = 0;
    virtual void CapsuleCenter2Updated() = 0;
    virtual float& CapsuleRadius() = 0;
    virtual void CapsuleRadiusUpdated() = 0;
    static ICollisionProperty* FromOriginal(CCollisionProperty* p);
};

#endif // _INCLUDE_ICOLLISIONPROPERTY_H
