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

#include "CSoundAreaEntityBase.h"

class CSoundAreaEntityOrientedBox : public CSoundAreaEntityBase
{
public:
    DECLARE_SCHEMA_CLASS(CSoundAreaEntityOrientedBox);

    SCHEMA_FIELD(Vector, m_vMin);
    SCHEMA_FIELD(Vector, m_vMax);

public:
    static CSoundAreaEntityOrientedBox* New(const char* className)
    {
        return CBaseEntity::New<CSoundAreaEntityOrientedBox>(className);
    }

    static CSoundAreaEntityOrientedBox* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundAreaEntityOrientedBox>(iIndex);
    }

    static CSoundAreaEntityOrientedBox* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
