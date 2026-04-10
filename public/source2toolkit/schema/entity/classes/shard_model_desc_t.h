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

#include "InfoForResourceTypeIMaterial2.h"
#include "../enums/ShardSolid_t.h"

class shard_model_desc_t
{
public:
    DECLARE_SCHEMA_CLASS(shard_model_desc_t);

    SCHEMA_FIELD(int32_t, m_nModelID);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIMaterial2 >, m_hMaterialBase);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIMaterial2 >, m_hMaterialDamageOverlay);
    SCHEMA_FIELD(ShardSolid_t, m_solid);
    SCHEMA_FIELD(Vector2D, m_vecPanelSize);
    SCHEMA_FIELD(Vector2D, m_vecStressPositionA);
    SCHEMA_FIELD(Vector2D, m_vecStressPositionB);
    SCHEMA_FIELD(CUtlVector<Vector2D>, m_vecPanelVertices);
    SCHEMA_FIELD(CUtlVector<Vector4D>, m_vInitialPanelVertices);
    SCHEMA_FIELD(float, m_flGlassHalfThickness);
    SCHEMA_FIELD(bool, m_bHasParent);
    SCHEMA_FIELD(bool, m_bParentFrozen);
    SCHEMA_FIELD_POINTER(CUtlStringToken, m_SurfacePropStringToken);
};
