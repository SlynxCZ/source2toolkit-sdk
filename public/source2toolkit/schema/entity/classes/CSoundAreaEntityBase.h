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

class CSoundAreaEntityBase : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundAreaEntityBase);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSoundAreaType);
    SCHEMA_FIELD(Vector, m_vPos);

public:
    static CSoundAreaEntityBase* New(const char* className)
    {
        return CBaseEntity::New<CSoundAreaEntityBase>(className);
    }

    static CSoundAreaEntityBase* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundAreaEntityBase>(iIndex);
    }

    static CSoundAreaEntityBase* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
