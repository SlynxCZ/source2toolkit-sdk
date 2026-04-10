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

#include "CRagdollProp.h"

class CRagdollPropAttached : public CRagdollProp
{
public:
    DECLARE_SCHEMA_CLASS(CRagdollPropAttached);

    SCHEMA_FIELD(uint32_t, m_boneIndexAttached);
    SCHEMA_FIELD(uint32_t, m_ragdollAttachedObjectIndex);
    SCHEMA_FIELD(Vector, m_attachmentPointBoneSpace);
    SCHEMA_FIELD(Vector, m_attachmentPointRagdollSpace);
    SCHEMA_FIELD(bool, m_bShouldDetach);
    SCHEMA_FIELD(bool, m_bShouldDeleteAttachedActivationRecord);

public:
    static CRagdollPropAttached* New(const char* className)
    {
        return CBaseEntity::New<CRagdollPropAttached>(className);
    }

    static CRagdollPropAttached* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRagdollPropAttached>(iIndex);
    }

    static CRagdollPropAttached* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
