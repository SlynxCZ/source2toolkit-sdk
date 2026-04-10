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

class CTriggerBrush : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerBrush);

    SCHEMA_FIELD(CEntityIOOutput, m_OnStartTouch);
    SCHEMA_FIELD(CEntityIOOutput, m_OnEndTouch);
    SCHEMA_FIELD(CEntityIOOutput, m_OnUse);
    SCHEMA_FIELD(int32_t, m_iInputFilter);
    SCHEMA_FIELD(int32_t, m_iDontMessageParent);

public:
    static CTriggerBrush* New(const char* className)
    {
        return CBaseEntity::New<CTriggerBrush>(className);
    }

    static CTriggerBrush* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerBrush>(iIndex);
    }

    static CTriggerBrush* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
