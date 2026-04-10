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

class CAI_ChangeHintGroup : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CAI_ChangeHintGroup);

    SCHEMA_FIELD(int32_t, m_iSearchType);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strSearchName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strNewHintGroup);
    SCHEMA_FIELD(float, m_flRadius);

public:
    static CAI_ChangeHintGroup* New(const char* className)
    {
        return CBaseEntity::New<CAI_ChangeHintGroup>(className);
    }

    static CAI_ChangeHintGroup* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CAI_ChangeHintGroup>(iIndex);
    }

    static CAI_ChangeHintGroup* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
