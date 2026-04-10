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

#include "CBaseModelEntity.h"
#include "InfoForResourceTypeCTextureBase.h"

class CTextureBasedAnimatable : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CTextureBasedAnimatable);

    SCHEMA_FIELD(bool, m_bLoop);
    SCHEMA_FIELD(float, m_flFPS);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeCTextureBase >, m_hPositionKeys);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeCTextureBase >, m_hRotationKeys);
    SCHEMA_FIELD(Vector, m_vAnimationBoundsMin);
    SCHEMA_FIELD(Vector, m_vAnimationBoundsMax);
    SCHEMA_FIELD(float, m_flStartTime);
    SCHEMA_FIELD(float, m_flStartFrame);

public:
    static CTextureBasedAnimatable* New(const char* className)
    {
        return CBaseEntity::New<CTextureBasedAnimatable>(className);
    }

    static CTextureBasedAnimatable* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTextureBasedAnimatable>(iIndex);
    }

    static CTextureBasedAnimatable* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
