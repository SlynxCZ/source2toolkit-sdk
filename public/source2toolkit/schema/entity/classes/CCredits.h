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

class CCredits : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CCredits);

    SCHEMA_FIELD(CEntityIOOutput, m_OnCreditsDone);
    SCHEMA_FIELD(bool, m_bRolledOutroCredits);
    SCHEMA_FIELD(float, m_flLogoLength);

public:
    static CCredits* New(const char* className)
    {
        return CBaseEntity::New<CCredits>(className);
    }

    static CCredits* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCredits>(iIndex);
    }

    static CCredits* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
