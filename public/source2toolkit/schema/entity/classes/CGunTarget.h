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

#include "CBaseToggle.h"

class CBaseEntity;

class CGunTarget : public CBaseToggle
{
public:
    DECLARE_SCHEMA_CLASS(CGunTarget);

    SCHEMA_FIELD(bool, m_on);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hTargetEnt);
    SCHEMA_FIELD(CEntityIOOutput, m_OnDeath);

public:
    static CGunTarget* New(const char* className)
    {
        return CBaseEntity::New<CGunTarget>(className);
    }

    static CGunTarget* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CGunTarget>(iIndex);
    }

    static CGunTarget* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
