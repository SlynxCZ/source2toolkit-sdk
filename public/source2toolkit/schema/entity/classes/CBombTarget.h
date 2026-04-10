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

#include "CBaseTrigger.h"

class CBaseEntity;

class CBombTarget : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CBombTarget);

    SCHEMA_FIELD(CEntityIOOutput, m_OnBombExplode);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBombPlanted);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBombDefused);
    SCHEMA_FIELD(bool, m_bIsBombSiteB);
    SCHEMA_FIELD(bool, m_bIsHeistBombTarget);
    SCHEMA_FIELD(bool, m_bBombPlantedHere);
    SCHEMA_FIELD(CUtlSymbolLarge, m_szMountTarget);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hInstructorHint);
    SCHEMA_FIELD(int32_t, m_nBombSiteDesignation);

public:
    static CBombTarget* New(const char* className)
    {
        return CBaseEntity::New<CBombTarget>(className);
    }

    static CBombTarget* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBombTarget>(iIndex);
    }

    static CBombTarget* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
