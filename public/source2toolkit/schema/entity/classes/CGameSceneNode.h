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

#ifndef _INCLUDE_CGAMESCENENODE_H
#define _INCLUDE_CGAMESCENENODE_H

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

#include "CNetworkOriginCellCoordQuantizedVector.h"

class CGameSceneNode
{
public:
    DECLARE_SCHEMA_CLASS(CGameSceneNode);

    SCHEMA_FIELD(CTransform, m_nodeToWorld);
    SCHEMA_FIELD(CEntityInstance*, m_pOwner);
    SCHEMA_FIELD(CGameSceneNode*, m_pParent);
    SCHEMA_FIELD(CGameSceneNode*, m_pChild);
    SCHEMA_FIELD(CGameSceneNode*, m_pNextSibling);
    SCHEMA_FIELD(CNetworkOriginCellCoordQuantizedVector, m_vecOrigin);
    SCHEMA_FIELD(QAngle, m_angRotation);
    SCHEMA_FIELD(float, m_flScale);
    SCHEMA_FIELD(Vector, m_vecAbsOrigin);
    SCHEMA_FIELD(QAngle, m_angAbsRotation);
    SCHEMA_FIELD(float, m_flAbsScale);
    SCHEMA_FIELD(int16_t, m_nParentAttachmentOrBone);
    SCHEMA_FIELD(bool, m_bDebugAbsOriginChanges);
    SCHEMA_FIELD(bool, m_bDormant);
    SCHEMA_FIELD(bool, m_bForceParentToBeNetworked);
    SCHEMA_FIELD(uint8_t, m_nHierarchicalDepth);
    SCHEMA_FIELD(uint8_t, m_nHierarchyType);
    SCHEMA_FIELD(uint8_t, m_nDoNotSetAnimTimeInInvalidatePhysicsCount);
    SCHEMA_FIELD_POINTER(CUtlStringToken, m_name);
    SCHEMA_FIELD_POINTER(CUtlStringToken, m_hierarchyAttachName);
    SCHEMA_FIELD(float, m_flZOffset);
    SCHEMA_FIELD(float, m_flClientLocalScale);
    SCHEMA_FIELD(Vector, m_vRenderOrigin);
};

#endif // _INCLUDE_CGAMESCENENODE_H
