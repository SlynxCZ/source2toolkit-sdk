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

#include "CGameSceneNode.h"
#include "CModelState.h"

class CSkeletonInstance : public CGameSceneNode
{
public:
    DECLARE_SCHEMA_CLASS(CSkeletonInstance);

    SCHEMA_FIELD(CModelState, m_modelState);
    SCHEMA_FIELD(bool, m_bIsAnimationEnabled);
    SCHEMA_FIELD(bool, m_bUseParentRenderBounds);
    SCHEMA_FIELD(bool, m_bDisableSolidCollisionsForHierarchy);
    SCHEMA_FIELD_POINTER(CUtlStringToken, m_materialGroup);
    SCHEMA_FIELD(uint8_t, m_nHitboxSet);
    SCHEMA_FIELD(bool, m_bForceServerConstraintsEnabled);
};
