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

#include "CPointEntity.h"

class CEnvInstructorVRHint : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvInstructorVRHint);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszHintTargetEntity);
    SCHEMA_FIELD(int32_t, m_iTimeout);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszCaption);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszStartSound);
    SCHEMA_FIELD(int32_t, m_iLayoutFileType);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszCustomLayoutFile);
    SCHEMA_FIELD(int32_t, m_iAttachType);
    SCHEMA_FIELD(float, m_flHeightOffset);

public:
    static CEnvInstructorVRHint* New(const char* className)
    {
        return CBaseEntity::New<CEnvInstructorVRHint>(className);
    }

    static CEnvInstructorVRHint* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvInstructorVRHint>(iIndex);
    }

    static CEnvInstructorVRHint* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
