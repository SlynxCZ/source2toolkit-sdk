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

#include "CBeam.h"

class CSprite;

class CEnvLaser : public CBeam
{
public:
    DECLARE_SCHEMA_CLASS(CEnvLaser);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszLaserTarget);
    SCHEMA_FIELD(CSprite*, m_pSprite);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSpriteName);
    SCHEMA_FIELD(Vector, m_firePosition);
    SCHEMA_FIELD(float, m_flStartFrame);

public:
    static CEnvLaser* New(const char* className)
    {
        return CBaseEntity::New<CEnvLaser>(className);
    }

    static CEnvLaser* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvLaser>(iIndex);
    }

    static CEnvLaser* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
