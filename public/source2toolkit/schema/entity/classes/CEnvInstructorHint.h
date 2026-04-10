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

class CEnvInstructorHint : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvInstructorHint);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszReplace_Key);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszHintTargetEntity);
    SCHEMA_FIELD(int32_t, m_iTimeout);
    SCHEMA_FIELD(int32_t, m_iDisplayLimit);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszIcon_Onscreen);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszIcon_Offscreen);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszCaption);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszActivatorCaption);
    SCHEMA_FIELD(Color, m_Color);
    SCHEMA_FIELD(float, m_fIconOffset);
    SCHEMA_FIELD(float, m_fRange);
    SCHEMA_FIELD(uint8_t, m_iPulseOption);
    SCHEMA_FIELD(uint8_t, m_iAlphaOption);
    SCHEMA_FIELD(uint8_t, m_iShakeOption);
    SCHEMA_FIELD(bool, m_bStatic);
    SCHEMA_FIELD(bool, m_bNoOffscreen);
    SCHEMA_FIELD(bool, m_bForceCaption);
    SCHEMA_FIELD(int32_t, m_iInstanceType);
    SCHEMA_FIELD(bool, m_bSuppressRest);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszBinding);
    SCHEMA_FIELD(bool, m_bAllowNoDrawTarget);
    SCHEMA_FIELD(bool, m_bAutoStart);
    SCHEMA_FIELD(bool, m_bLocalPlayerOnly);

public:
    static CEnvInstructorHint* New(const char* className)
    {
        return CBaseEntity::New<CEnvInstructorHint>(className);
    }

    static CEnvInstructorHint* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvInstructorHint>(iIndex);
    }

    static CEnvInstructorHint* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
