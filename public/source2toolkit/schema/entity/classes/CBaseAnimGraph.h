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

#include "CAnimGraphControllerManager.h"
#include "CBaseModelEntity.h"
#include "PhysicsRagdollPose_t.h"

class CAnimGraphControllerBase;
class IChoreoServices;

class CBaseAnimGraph : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CBaseAnimGraph);

    SCHEMA_FIELD(CAnimGraphControllerManager, m_graphControllerManager);
    SCHEMA_FIELD(CAnimGraphControllerBase*, m_pMainGraphController);
    SCHEMA_FIELD(bool, m_bInitiallyPopulateInterpHistory);
    SCHEMA_FIELD(IChoreoServices*, m_pChoreoServices);
    SCHEMA_FIELD(bool, m_bAnimGraphUpdateEnabled);
    SCHEMA_FIELD(float, m_flMaxSlopeDistance);
    SCHEMA_FIELD(Vector, m_vLastSlopeCheckPos);
    SCHEMA_FIELD(uint32_t, m_nAnimGraphUpdateId);
    SCHEMA_FIELD(bool, m_bAnimationUpdateScheduled);
    SCHEMA_FIELD(Vector, m_vecForce);
    SCHEMA_FIELD(int32_t, m_nForceBone);
    SCHEMA_FIELD(PhysicsRagdollPose_t, m_RagdollPose);
    SCHEMA_FIELD(bool, m_bRagdollEnabled);
    SCHEMA_FIELD(bool, m_bRagdollClientSide);
    SCHEMA_FIELD(CTransform, m_xParentedRagdollRootInEntitySpace);

public:
    static CBaseAnimGraph* New(const char* className)
    {
        return CBaseEntity::New<CBaseAnimGraph>(className);
    }

    static CBaseAnimGraph* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseAnimGraph>(iIndex);
    }

    static CBaseAnimGraph* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
