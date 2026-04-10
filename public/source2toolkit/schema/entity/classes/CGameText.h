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

#include "CRulePointEntity.h"
#include "hudtextparms_t.h"

class CGameText : public CRulePointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CGameText);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszMessage);
    SCHEMA_FIELD(hudtextparms_t, m_textParms);

public:
    static CGameText* New(const char* className)
    {
        return CBaseEntity::New<CGameText>(className);
    }

    static CGameText* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CGameText>(iIndex);
    }

    static CGameText* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
