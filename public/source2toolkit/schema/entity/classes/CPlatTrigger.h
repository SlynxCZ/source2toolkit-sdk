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

#include "CBaseModelEntity.h"

class CFuncPlat;

class CPlatTrigger : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPlatTrigger);

    SCHEMA_FIELD(CHandle<CFuncPlat>, m_pPlatform);

public:
    static CPlatTrigger* New(const char* className)
    {
        return CBaseEntity::New<CPlatTrigger>(className);
    }

    static CPlatTrigger* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPlatTrigger>(iIndex);
    }

    static CPlatTrigger* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
