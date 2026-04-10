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

#include "CBaseTrigger.h"
#include "lerpdata_t.h"

class CBaseEntity;

class CTriggerLerpObject : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerLerpObject);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszLerpTarget);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hLerpTarget);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszLerpTargetAttachment);
    SCHEMA_FIELD(float, m_flLerpDuration);
    SCHEMA_FIELD(bool, m_bAttachedEntityWasParented);
    SCHEMA_FIELD(bool, m_bLerpRestoreMoveType);
    SCHEMA_FIELD(bool, m_bSingleLerpObject);
    SCHEMA_FIELD(CUtlVector<lerpdata_t>, m_vecLerpingObjects);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszLerpEffect);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszLerpSound);
    SCHEMA_FIELD(bool, m_bAttachTouchingObject);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hEntityToWaitForDisconnect);
    SCHEMA_FIELD(CEntityIOOutput, m_OnLerpStarted);
    SCHEMA_FIELD(CEntityIOOutput, m_OnLerpFinished);
    SCHEMA_FIELD(CEntityIOOutput, m_OnDetached);

public:
    static CTriggerLerpObject* New(const char* className)
    {
        return CBaseEntity::New<CTriggerLerpObject>(className);
    }

    static CTriggerLerpObject* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerLerpObject>(iIndex);
    }

    static CTriggerLerpObject* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
