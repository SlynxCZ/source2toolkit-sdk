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

class CInfoPlayerStart : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoPlayerStart);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(bool, m_bIsMaster);
    SCHEMA_FIELD(CGlobalSymbol, m_pPawnSubclass);

public:
    static CInfoPlayerStart* New(const char* className)
    {
        return CBaseEntity::New<CInfoPlayerStart>(className);
    }

    static CInfoPlayerStart* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoPlayerStart>(iIndex);
    }

    static CInfoPlayerStart* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
