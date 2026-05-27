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

#ifndef _INCLUDE_IPHYSCONSTRAINT_H
#define _INCLUDE_IPHYSCONSTRAINT_H

#pragma once

#include <cstdint>

#include "ILogicalEntity.h"

class CBaseEntity;
class IPhysicsJoint;

class IPhysConstraint : public virtual ILogicalEntity
{
public:
    virtual ~IPhysConstraint() = default;

    virtual IPhysicsJoint*& Joint() = 0;
    virtual void JointUpdated() = 0;
    virtual CUtlSymbolLarge& NameAttach1() = 0;
    virtual void NameAttach1Updated() = 0;
    virtual CUtlSymbolLarge& NameAttach2() = 0;
    virtual void NameAttach2Updated() = 0;
    virtual CHandle<CBaseEntity>& Attach1() = 0;
    virtual void Attach1Updated() = 0;
    virtual CHandle<CBaseEntity>& Attach2() = 0;
    virtual void Attach2Updated() = 0;
    virtual CUtlSymbolLarge& NameAttachment1() = 0;
    virtual void NameAttachment1Updated() = 0;
    virtual CUtlSymbolLarge& NameAttachment2() = 0;
    virtual void NameAttachment2Updated() = 0;
    virtual CUtlSymbolLarge& BreakSound() = 0;
    virtual void BreakSoundUpdated() = 0;
    virtual float& ForceLimit() = 0;
    virtual void ForceLimitUpdated() = 0;
    virtual float& TorqueLimit() = 0;
    virtual void TorqueLimitUpdated() = 0;
    virtual float& MinTeleportDistance() = 0;
    virtual void MinTeleportDistanceUpdated() = 0;
    virtual bool& SnapObjectPositions() = 0;
    virtual void SnapObjectPositionsUpdated() = 0;
    virtual bool& TreatEntity1AsInfiniteMass() = 0;
    virtual void TreatEntity1AsInfiniteMassUpdated() = 0;
    virtual CEntityIOOutput& OnBreak() = 0;
    virtual void OnBreakUpdated() = 0;
};

#endif // _INCLUDE_IPHYSCONSTRAINT_H
