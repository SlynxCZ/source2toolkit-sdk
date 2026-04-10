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

#include "CBasePlatTrain.h"

class CFuncPlat : public CBasePlatTrain
{
public:
    DECLARE_SCHEMA_CLASS(CFuncPlat);

    SCHEMA_FIELD(CUtlSymbolLarge, m_sNoise);

public:
    static CFuncPlat* New(const char* className)
    {
        return CBaseEntity::New<CFuncPlat>(className);
    }

    static CFuncPlat* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncPlat>(iIndex);
    }

    static CFuncPlat* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
