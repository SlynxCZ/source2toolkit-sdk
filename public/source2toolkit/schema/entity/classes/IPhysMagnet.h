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

#ifndef _INCLUDE_IPHYSMAGNET_H
#define _INCLUDE_IPHYSMAGNET_H

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

#include "IBaseAnimGraph.h"

class CPhysMagnet;
class magnetted_objects_t;

class IPhysMagnet : public virtual IBaseAnimGraph
{
public:
    virtual ~IPhysMagnet() = default;

    virtual ::CEntityIOOutput& OnMagnetAttach() = 0;
    virtual void OnMagnetAttachUpdated() = 0;
    virtual ::CEntityIOOutput& OnMagnetDetach() = 0;
    virtual void OnMagnetDetachUpdated() = 0;
    virtual float& MassScale() = 0;
    virtual void MassScaleUpdated() = 0;
    virtual float& ForceLimit() = 0;
    virtual void ForceLimitUpdated() = 0;
    virtual float& TorqueLimit() = 0;
    virtual void TorqueLimitUpdated() = 0;
    virtual CUtlVector<magnetted_objects_t>& MagnettedEntities() = 0;
    virtual void MagnettedEntitiesUpdated() = 0;
    virtual bool& Active() = 0;
    virtual void ActiveUpdated() = 0;
    virtual bool& HasHitSomething() = 0;
    virtual void HasHitSomethingUpdated() = 0;
    virtual float& TotalMass() = 0;
    virtual void TotalMassUpdated() = 0;
    virtual float& Radius() = 0;
    virtual void RadiusUpdated() = 0;
    virtual float& NextSuckTime() = 0;
    virtual void NextSuckTimeUpdated() = 0;
    virtual int32_t& MaxObjectsAttached() = 0;
    virtual void MaxObjectsAttachedUpdated() = 0;
    static IPhysMagnet* FromOriginal(CPhysMagnet* p);
    static IPhysMagnet* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IPHYSMAGNET_H
