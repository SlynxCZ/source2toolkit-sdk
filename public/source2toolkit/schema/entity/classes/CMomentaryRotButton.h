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

#include "CRotButton.h"

class CMomentaryRotButton : public CRotButton
{
public:
    DECLARE_SCHEMA_CLASS(CMomentaryRotButton);

    SCHEMA_FIELD(CEntityIOOutput, m_OnUnpressed);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFullyOpen);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFullyClosed);
    SCHEMA_FIELD(CEntityIOOutput, m_OnReachedPosition);
    SCHEMA_FIELD(int32_t, m_lastUsed);
    SCHEMA_FIELD(QAngle, m_start);
    SCHEMA_FIELD(QAngle, m_end);
    SCHEMA_FIELD(float, m_IdealYaw);
    SCHEMA_FIELD(CUtlSymbolLarge, m_sNoise);
    SCHEMA_FIELD(bool, m_bUpdateTarget);
    SCHEMA_FIELD(int32_t, m_direction);
    SCHEMA_FIELD(float, m_returnSpeed);
    SCHEMA_FIELD(float, m_flStartPosition);

public:
    static CMomentaryRotButton* New(const char* className)
    {
        return CBaseEntity::New<CMomentaryRotButton>(className);
    }

    static CMomentaryRotButton* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CMomentaryRotButton>(iIndex);
    }

    static CMomentaryRotButton* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
