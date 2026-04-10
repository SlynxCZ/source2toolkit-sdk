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

class CTriggerToggleSave : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerToggleSave);


public:
    static CTriggerToggleSave* New(const char* className)
    {
        return CBaseEntity::New<CTriggerToggleSave>(className);
    }

    static CTriggerToggleSave* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerToggleSave>(iIndex);
    }

    static CTriggerToggleSave* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
