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

class CTestPulseIO : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CTestPulseIO);

    SCHEMA_FIELD(CEntityIOOutput, m_OnVariantVoid);
    SCHEMA_FIELD(bool, m_bAllowEmptyInputs);

public:
    static CTestPulseIO* New(const char* className)
    {
        return CBaseEntity::New<CTestPulseIO>(className);
    }

    static CTestPulseIO* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTestPulseIO>(iIndex);
    }

    static CTestPulseIO* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
