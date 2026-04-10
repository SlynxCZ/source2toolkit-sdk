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

#include "CBaseTrigger.h"

class CTriggerActiveWeaponDetect : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerActiveWeaponDetect);

    SCHEMA_FIELD(CEntityIOOutput, m_OnTouchedActiveWeapon);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszWeaponClassName);

public:
    static CTriggerActiveWeaponDetect* New(const char* className)
    {
        return CBaseEntity::New<CTriggerActiveWeaponDetect>(className);
    }

    static CTriggerActiveWeaponDetect* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerActiveWeaponDetect>(iIndex);
    }

    static CTriggerActiveWeaponDetect* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
