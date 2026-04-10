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

class CFuncInteractionLayerClip : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncInteractionLayerClip);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszInteractsAs);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszInteractsWith);

public:
    static CFuncInteractionLayerClip* New(const char* className)
    {
        return CBaseEntity::New<CFuncInteractionLayerClip>(className);
    }

    static CFuncInteractionLayerClip* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncInteractionLayerClip>(iIndex);
    }

    static CFuncInteractionLayerClip* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
