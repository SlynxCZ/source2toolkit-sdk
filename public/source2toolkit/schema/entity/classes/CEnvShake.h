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

#include "CPhysicsShake.h"
#include "CPointEntity.h"

class CEnvShake : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvShake);

    SCHEMA_FIELD(CUtlSymbolLarge, m_limitToEntity);
    SCHEMA_FIELD(float, m_Amplitude);
    SCHEMA_FIELD(float, m_Frequency);
    SCHEMA_FIELD(float, m_Duration);
    SCHEMA_FIELD(float, m_Radius);
    SCHEMA_FIELD(float, m_stopTime);
    SCHEMA_FIELD(float, m_nextShake);
    SCHEMA_FIELD(float, m_currentAmp);
    SCHEMA_FIELD(Vector, m_maxForce);
    SCHEMA_FIELD(CPhysicsShake, m_shakeCallback);

public:
    static CEnvShake* New(const char* className)
    {
        return CBaseEntity::New<CEnvShake>(className);
    }

    static CEnvShake* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvShake>(iIndex);
    }

    static CEnvShake* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
