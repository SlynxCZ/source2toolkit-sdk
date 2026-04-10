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

#include "CBaseEntity.h"
#include "CCollisionProperty.h"
#include "CGlowProperty.h"
#include "CNetworkViewOffsetVector.h"
#include "EntityRenderAttribute_t.h"
#include "CHitboxComponent.h"

class CDestructiblePartsComponent;
class CRenderComponent;

class CBaseModelEntity : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CBaseModelEntity);

    SCHEMA_FIELD(CRenderComponent*, m_CRenderComponent);
    SCHEMA_FIELD(CHitboxComponent, m_CHitboxComponent);
    SCHEMA_FIELD(HitGroup_t, m_nDestructiblePartInitialStateDestructed0);
    SCHEMA_FIELD(HitGroup_t, m_nDestructiblePartInitialStateDestructed1);
    SCHEMA_FIELD(HitGroup_t, m_nDestructiblePartInitialStateDestructed2);
    SCHEMA_FIELD(HitGroup_t, m_nDestructiblePartInitialStateDestructed3);
    SCHEMA_FIELD(HitGroup_t, m_nDestructiblePartInitialStateDestructed4);
    SCHEMA_FIELD(int32_t, m_nDestructiblePartInitialStateDestructed0_PartIndex);
    SCHEMA_FIELD(int32_t, m_nDestructiblePartInitialStateDestructed1_PartIndex);
    SCHEMA_FIELD(int32_t, m_nDestructiblePartInitialStateDestructed2_PartIndex);
    SCHEMA_FIELD(int32_t, m_nDestructiblePartInitialStateDestructed3_PartIndex);
    SCHEMA_FIELD(int32_t, m_nDestructiblePartInitialStateDestructed4_PartIndex);
    SCHEMA_FIELD(CDestructiblePartsComponent*, m_pDestructiblePartsSystemComponent);
    SCHEMA_FIELD(float, m_flDissolveStartTime);
    SCHEMA_FIELD(CEntityIOOutput, m_OnIgnite);
    SCHEMA_FIELD(RenderMode_t, m_nRenderMode);
    SCHEMA_FIELD(RenderFx_t, m_nRenderFX);
    SCHEMA_FIELD(bool, m_bAllowFadeInView);
    SCHEMA_FIELD(Color, m_clrRender);
    SCHEMA_FIELD(CUtlVector<EntityRenderAttribute_t>, m_vecRenderAttributes);
    SCHEMA_FIELD(bool, m_bRenderToCubemaps);
    SCHEMA_FIELD(bool, m_bNoInterpolate);
    SCHEMA_FIELD(CCollisionProperty, m_Collision);
    SCHEMA_FIELD(CGlowProperty, m_Glow);
    SCHEMA_FIELD(float, m_flGlowBackfaceMult);
    SCHEMA_FIELD(float, m_fadeMinDist);
    SCHEMA_FIELD(float, m_fadeMaxDist);
    SCHEMA_FIELD(float, m_flFadeScale);
    SCHEMA_FIELD(float, m_flShadowStrength);
    SCHEMA_FIELD(uint8_t, m_nObjectCulling);
    SCHEMA_FIELD(CNetworkViewOffsetVector, m_vecViewOffset);
    SCHEMA_FIELD_POINTER(uint32_t, m_bvDisabledHitGroups);

public:
    /// <summary>Get model name.</summary>
    CUtlSymbolLarge GetModelName();
    /// <summary>Get eye position.</summary>
    Vector GetEyePosition();
    /// <summary>Set entity model.</summary>
    void SetModel(const char* pszModel);

public:
    static CBaseModelEntity* New(const char* className)
    {
        return CBaseEntity::New<CBaseModelEntity>(className);
    }

    static CBaseModelEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseModelEntity>(iIndex);
    }

    static CBaseModelEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
