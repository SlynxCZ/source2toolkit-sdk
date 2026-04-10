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

class CCommentaryAuto : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CCommentaryAuto);

    SCHEMA_FIELD(CEntityIOOutput, m_OnCommentaryNewGame);
    SCHEMA_FIELD(CEntityIOOutput, m_OnCommentaryMidGame);
    SCHEMA_FIELD(CEntityIOOutput, m_OnCommentaryMultiplayerSpawn);

public:
    static CCommentaryAuto* New(const char* className)
    {
        return CBaseEntity::New<CCommentaryAuto>(className);
    }

    static CCommentaryAuto* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCommentaryAuto>(iIndex);
    }

    static CCommentaryAuto* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
