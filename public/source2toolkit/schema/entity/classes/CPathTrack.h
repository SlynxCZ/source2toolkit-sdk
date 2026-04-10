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
#include "../enums/TrackOrientationType_t.h"

class CPathTrack : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPathTrack);

    SCHEMA_FIELD(CPathTrack*, m_pnext);
    SCHEMA_FIELD(CPathTrack*, m_pprevious);
    SCHEMA_FIELD(CPathTrack*, m_paltpath);
    SCHEMA_FIELD(float, m_flRadius);
    SCHEMA_FIELD(float, m_length);
    SCHEMA_FIELD(CUtlSymbolLarge, m_altName);
    SCHEMA_FIELD(int32_t, m_nIterVal);
    SCHEMA_FIELD(TrackOrientationType_t, m_eOrientationType);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPass);

public:
    static CPathTrack* New(const char* className)
    {
        return CBaseEntity::New<CPathTrack>(className);
    }

    static CPathTrack* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPathTrack>(iIndex);
    }

    static CPathTrack* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
