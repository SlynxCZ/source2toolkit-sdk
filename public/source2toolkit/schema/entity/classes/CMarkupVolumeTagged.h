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

#include "CMarkupVolume.h"

class CMarkupVolumeTagged : public CMarkupVolume
{
public:
    DECLARE_SCHEMA_CLASS(CMarkupVolumeTagged);

    SCHEMA_FIELD(CUtlVector<CGlobalSymbol>, m_GroupNames);
    SCHEMA_FIELD(CUtlVector<CGlobalSymbol>, m_Tags);
    SCHEMA_FIELD(bool, m_bIsGroup);
    SCHEMA_FIELD(bool, m_bGroupByPrefab);
    SCHEMA_FIELD(bool, m_bGroupByVolume);
    SCHEMA_FIELD(bool, m_bGroupOtherGroups);
    SCHEMA_FIELD(bool, m_bIsInGroup);

public:
    static CMarkupVolumeTagged* New(const char* className)
    {
        return CBaseEntity::New<CMarkupVolumeTagged>(className);
    }

    static CMarkupVolumeTagged* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CMarkupVolumeTagged>(iIndex);
    }

    static CMarkupVolumeTagged* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
