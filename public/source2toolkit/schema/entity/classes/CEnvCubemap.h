#pragma once
#include "CBaseEntity.h"
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

#include "CBaseEntity.h"
#include "InfoForResourceTypeCTextureBase.h"

class CEnvCubemap : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvCubemap);

    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeCTextureBase >, m_Entity_hCubemapTexture);
    SCHEMA_FIELD(bool, m_Entity_bCustomCubemapTexture);
    SCHEMA_FIELD(float, m_Entity_flInfluenceRadius);
    SCHEMA_FIELD(Vector, m_Entity_vBoxProjectMins);
    SCHEMA_FIELD(Vector, m_Entity_vBoxProjectMaxs);
    SCHEMA_FIELD(bool, m_Entity_bMoveable);
    SCHEMA_FIELD(int32_t, m_Entity_nHandshake);
    SCHEMA_FIELD(int32_t, m_Entity_nEnvCubeMapArrayIndex);
    SCHEMA_FIELD(int32_t, m_Entity_nPriority);
    SCHEMA_FIELD(float, m_Entity_flEdgeFadeDist);
    SCHEMA_FIELD(Vector, m_Entity_vEdgeFadeDists);
    SCHEMA_FIELD(float, m_Entity_flDiffuseScale);
    SCHEMA_FIELD(bool, m_Entity_bStartDisabled);
    SCHEMA_FIELD(bool, m_Entity_bDefaultEnvMap);
    SCHEMA_FIELD(bool, m_Entity_bDefaultSpecEnvMap);
    SCHEMA_FIELD(bool, m_Entity_bIndoorCubeMap);
    SCHEMA_FIELD(bool, m_Entity_bCopyDiffuseFromDefaultCubemap);
    SCHEMA_FIELD(bool, m_Entity_bEnabled);

public:
    static CEnvCubemap* New(const char* className)
    {
        return CBaseEntity::New<CEnvCubemap>(className);
    }

    static CEnvCubemap* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvCubemap>(iIndex);
    }

    static CEnvCubemap* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
