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
