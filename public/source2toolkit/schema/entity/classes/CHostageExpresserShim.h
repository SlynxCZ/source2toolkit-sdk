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

#include "CBaseCombatCharacter.h"

class CAI_Expresser;

class CHostageExpresserShim : public CBaseCombatCharacter
{
public:
    DECLARE_SCHEMA_CLASS(CHostageExpresserShim);

    SCHEMA_FIELD(CAI_Expresser*, m_pExpresser);

public:
    static CHostageExpresserShim* New(const char* className)
    {
        return CBaseEntity::New<CHostageExpresserShim>(className);
    }

    static CHostageExpresserShim* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CHostageExpresserShim>(iIndex);
    }

    static CHostageExpresserShim* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
