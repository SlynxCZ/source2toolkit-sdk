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

class CFuncTrainControls : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncTrainControls);


public:
    static CFuncTrainControls* New(const char* className)
    {
        return CBaseEntity::New<CFuncTrainControls>(className);
    }

    static CFuncTrainControls* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncTrainControls>(iIndex);
    }

    static CFuncTrainControls* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
