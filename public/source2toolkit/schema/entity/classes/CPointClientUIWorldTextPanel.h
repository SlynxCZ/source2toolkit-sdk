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

#include "CPointClientUIWorldPanel.h"

class CPointClientUIWorldTextPanel : public CPointClientUIWorldPanel
{
public:
    DECLARE_SCHEMA_CLASS(CPointClientUIWorldTextPanel);

    SCHEMA_FIELD_POINTER(char, m_messageText);

public:
    static CPointClientUIWorldTextPanel* New(const char* className)
    {
        return CBaseEntity::New<CPointClientUIWorldTextPanel>(className);
    }

    static CPointClientUIWorldTextPanel* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointClientUIWorldTextPanel>(iIndex);
    }

    static CPointClientUIWorldTextPanel* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
