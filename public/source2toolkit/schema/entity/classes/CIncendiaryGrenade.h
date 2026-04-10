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

#include "CMolotovGrenade.h"

class CIncendiaryGrenade : public CMolotovGrenade
{
public:
    DECLARE_SCHEMA_CLASS(CIncendiaryGrenade);


public:
    static CIncendiaryGrenade* New(const char* className)
    {
        return CBaseEntity::New<CIncendiaryGrenade>(className);
    }

    static CIncendiaryGrenade* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CIncendiaryGrenade>(iIndex);
    }

    static CIncendiaryGrenade* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
