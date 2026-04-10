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

#include "CBaseClientUIEntity.h"

class CBaseEntity;

class CPointClientUIDialog : public CBaseClientUIEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointClientUIDialog);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hActivator);
    SCHEMA_FIELD(bool, m_bStartEnabled);

public:
    static CPointClientUIDialog* New(const char* className)
    {
        return CBaseEntity::New<CPointClientUIDialog>(className);
    }

    static CPointClientUIDialog* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointClientUIDialog>(iIndex);
    }

    static CPointClientUIDialog* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
