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

#ifndef _INCLUDE_IGAMESCENENODE_H
#define _INCLUDE_IGAMESCENENODE_H

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

class CGameSceneNode;
class CNetworkOriginCellCoordQuantizedVector;

class IGameSceneNode
{
public:
    virtual ~IGameSceneNode() = default;
    virtual CGameSceneNode* GetOriginal() const = 0;

    virtual CTransform& NodeToWorld() = 0;
    virtual void NodeToWorldUpdated() = 0;
    virtual CEntityInstance*& Owner() = 0;
    virtual void OwnerUpdated() = 0;
    virtual CGameSceneNode*& Parent() = 0;
    virtual void ParentUpdated() = 0;
    virtual CGameSceneNode*& Child() = 0;
    virtual void ChildUpdated() = 0;
    virtual CGameSceneNode*& NextSibling() = 0;
    virtual void NextSiblingUpdated() = 0;
    virtual ::CNetworkOriginCellCoordQuantizedVector& Origin() = 0;
    virtual void OriginUpdated() = 0;
    virtual QAngle& Rotation() = 0;
    virtual void RotationUpdated() = 0;
    virtual float& Scale() = 0;
    virtual void ScaleUpdated() = 0;
    virtual Vector& AbsOrigin() = 0;
    virtual void AbsOriginUpdated() = 0;
    virtual QAngle& AbsRotation() = 0;
    virtual void AbsRotationUpdated() = 0;
    virtual float& AbsScale() = 0;
    virtual void AbsScaleUpdated() = 0;
    virtual int16_t& ParentAttachmentOrBone() = 0;
    virtual void ParentAttachmentOrBoneUpdated() = 0;
    virtual bool& DebugAbsOriginChanges() = 0;
    virtual void DebugAbsOriginChangesUpdated() = 0;
    virtual bool& Dormant() = 0;
    virtual void DormantUpdated() = 0;
    virtual bool& ForceParentToBeNetworked() = 0;
    virtual void ForceParentToBeNetworkedUpdated() = 0;
    virtual uint8_t& HierarchicalDepth() = 0;
    virtual void HierarchicalDepthUpdated() = 0;
    virtual uint8_t& HierarchyType() = 0;
    virtual void HierarchyTypeUpdated() = 0;
    virtual uint8_t& DoNotSetAnimTimeInInvalidatePhysicsCount() = 0;
    virtual void DoNotSetAnimTimeInInvalidatePhysicsCountUpdated() = 0;
    virtual CUtlStringToken* Name() = 0;
    virtual CUtlStringToken* HierarchyAttachName() = 0;
    virtual float& ClientLocalScale() = 0;
    virtual void ClientLocalScaleUpdated() = 0;
    virtual Vector& RenderOrigin() = 0;
    virtual void RenderOriginUpdated() = 0;
    static IGameSceneNode* FromOriginal(CGameSceneNode* p);
};

#endif // _INCLUDE_IGAMESCENENODE_H
