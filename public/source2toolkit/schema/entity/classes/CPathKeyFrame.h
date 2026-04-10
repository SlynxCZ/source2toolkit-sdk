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

#include "CLogicalEntity.h"

class CPathKeyFrame : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPathKeyFrame);

    SCHEMA_FIELD(Vector, m_Origin);
    SCHEMA_FIELD(QAngle, m_Angles);
    SCHEMA_FIELD(Quaternion, m_qAngle);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iNextKey);
    SCHEMA_FIELD(float, m_flNextTime);
    SCHEMA_FIELD(CPathKeyFrame*, m_pNextKey);
    SCHEMA_FIELD(CPathKeyFrame*, m_pPrevKey);
    SCHEMA_FIELD(float, m_flMoveSpeed);

public:
    static CPathKeyFrame* New(const char* className)
    {
        return CBaseEntity::New<CPathKeyFrame>(className);
    }

    static CPathKeyFrame* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPathKeyFrame>(iIndex);
    }

    static CPathKeyFrame* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
