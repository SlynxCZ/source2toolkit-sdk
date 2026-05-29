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

#ifndef _INCLUDE_IBASEANIMGRAPH_H
#define _INCLUDE_IBASEANIMGRAPH_H

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

#include "IBaseModelEntity.h"

class CAnimGraphControllerBase;
class CAnimGraphControllerManager;
class CBaseAnimGraph;
class IChoreoServices;
class IPhysicsRagdollControl;
class PhysicsRagdollPose_t;

class IBaseAnimGraph : public virtual IBaseModelEntity
{
public:
    virtual ~IBaseAnimGraph() = default;

    virtual ::CAnimGraphControllerManager& GraphControllerManager() = 0;
    virtual void GraphControllerManagerUpdated() = 0;
    virtual CAnimGraphControllerBase*& MainGraphController() = 0;
    virtual void MainGraphControllerUpdated() = 0;
    virtual bool& InitiallyPopulateInterpHistory() = 0;
    virtual void InitiallyPopulateInterpHistoryUpdated() = 0;
    virtual IChoreoServices*& ChoreoServices() = 0;
    virtual void ChoreoServicesUpdated() = 0;
    virtual bool& AnimGraphUpdateEnabled() = 0;
    virtual void AnimGraphUpdateEnabledUpdated() = 0;
    virtual bool& AnimationUpdateScheduled() = 0;
    virtual void AnimationUpdateScheduledUpdated() = 0;
    virtual Vector& Force() = 0;
    virtual void ForceUpdated() = 0;
    virtual int32_t& ForceBone() = 0;
    virtual void ForceBoneUpdated() = 0;
    virtual IPhysicsRagdollControl*& RagdollControl() = 0;
    virtual void RagdollControlUpdated() = 0;
    virtual ::PhysicsRagdollPose_t& RagdollPose() = 0;
    virtual void RagdollPoseUpdated() = 0;
    virtual bool& RagdollEnabled() = 0;
    virtual void RagdollEnabledUpdated() = 0;
    virtual bool& RagdollClientSide() = 0;
    virtual void RagdollClientSideUpdated() = 0;
    virtual CTransform& XParentedRagdollRootInEntitySpace() = 0;
    virtual void XParentedRagdollRootInEntitySpaceUpdated() = 0;
    static IBaseAnimGraph* FromOriginal(CBaseAnimGraph* p);
    static IBaseAnimGraph* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IBASEANIMGRAPH_H
