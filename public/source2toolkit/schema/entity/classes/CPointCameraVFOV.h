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

#include "CPointCamera.h"

class CPointCameraVFOV : public CPointCamera
{
public:
    DECLARE_SCHEMA_CLASS(CPointCameraVFOV);

    SCHEMA_FIELD(float, m_flVerticalFOV);

public:
    static CPointCameraVFOV* New(const char* className)
    {
        return CBaseEntity::New<CPointCameraVFOV>(className);
    }

    static CPointCameraVFOV* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointCameraVFOV>(iIndex);
    }

    static CPointCameraVFOV* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
