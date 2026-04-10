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

#include "CSoundOpvarSetPointEntity.h"

class CSoundOpvarSetPathCornerEntity : public CSoundOpvarSetPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundOpvarSetPathCornerEntity);

    SCHEMA_FIELD(bool, m_bUseParentedPath);
    SCHEMA_FIELD(float, m_flDistMinSqr);
    SCHEMA_FIELD(float, m_flDistMaxSqr);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPathCornerEntityName);

public:
    static CSoundOpvarSetPathCornerEntity* New(const char* className)
    {
        return CBaseEntity::New<CSoundOpvarSetPathCornerEntity>(className);
    }

    static CSoundOpvarSetPathCornerEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundOpvarSetPathCornerEntity>(iIndex);
    }

    static CSoundOpvarSetPathCornerEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
