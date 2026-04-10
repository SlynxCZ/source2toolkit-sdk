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
#include "CEconItemView.h"

class CCSGO_TeamPreviewCharacterPosition : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CCSGO_TeamPreviewCharacterPosition);

    SCHEMA_FIELD(int32_t, m_nVariant);
    SCHEMA_FIELD(int32_t, m_nRandom);
    SCHEMA_FIELD(int32_t, m_nOrdinal);
    SCHEMA_FIELD(CUtlString, m_sWeaponName);
    SCHEMA_FIELD(uint64_t, m_xuid);
    SCHEMA_FIELD(CEconItemView, m_agentItem);
    SCHEMA_FIELD(CEconItemView, m_glovesItem);
    SCHEMA_FIELD(CEconItemView, m_weaponItem);

public:
    static CCSGO_TeamPreviewCharacterPosition* New(const char* className)
    {
        return CBaseEntity::New<CCSGO_TeamPreviewCharacterPosition>(className);
    }

    static CCSGO_TeamPreviewCharacterPosition* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSGO_TeamPreviewCharacterPosition>(iIndex);
    }

    static CCSGO_TeamPreviewCharacterPosition* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
