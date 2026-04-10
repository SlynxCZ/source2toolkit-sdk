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

#include "CFuncBrush.h"

class CFuncElectrifiedVolume : public CFuncBrush
{
public:
    DECLARE_SCHEMA_CLASS(CFuncElectrifiedVolume);

    SCHEMA_FIELD(CUtlSymbolLarge, m_EffectName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_EffectInterpenetrateName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_EffectZapName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszEffectSource);

public:
    static CFuncElectrifiedVolume* New(const char* className)
    {
        return CBaseEntity::New<CFuncElectrifiedVolume>(className);
    }

    static CFuncElectrifiedVolume* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncElectrifiedVolume>(iIndex);
    }

    static CFuncElectrifiedVolume* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
