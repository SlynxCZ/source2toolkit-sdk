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

class CColorCorrection : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CColorCorrection);

    SCHEMA_FIELD(float, m_flFadeInDuration);
    SCHEMA_FIELD(float, m_flFadeOutDuration);
    SCHEMA_FIELD(float, m_flStartFadeInWeight);
    SCHEMA_FIELD(float, m_flStartFadeOutWeight);
    SCHEMA_FIELD(float, m_flTimeStartFadeIn);
    SCHEMA_FIELD(float, m_flTimeStartFadeOut);
    SCHEMA_FIELD(float, m_flMaxWeight);
    SCHEMA_FIELD(bool, m_bStartDisabled);
    SCHEMA_FIELD(bool, m_bEnabled);
    SCHEMA_FIELD(bool, m_bMaster);
    SCHEMA_FIELD(bool, m_bClientSide);
    SCHEMA_FIELD(bool, m_bExclusive);
    SCHEMA_FIELD(float, m_MinFalloff);
    SCHEMA_FIELD(float, m_MaxFalloff);
    SCHEMA_FIELD(float, m_flCurWeight);
    SCHEMA_FIELD_POINTER(char, m_netlookupFilename);
    SCHEMA_FIELD(CUtlSymbolLarge, m_lookupFilename);

public:
    static CColorCorrection* New(const char* className)
    {
        return CBaseEntity::New<CColorCorrection>(className);
    }

    static CColorCorrection* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CColorCorrection>(iIndex);
    }

    static CColorCorrection* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
