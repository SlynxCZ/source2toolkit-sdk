/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
 * AlliedModders LLC. All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
 * AlliedModders LLC give you permission to link the code of this program
 * (as well as its derivative works) to "Counter-Strike 2," "Source 2,"
 * "Steam," and any Game MODs or server software running on software by
 * Valve Corporation. You must obey the GNU General Public License in all
 * respects for all other code used.
 *
 * Additionally, this exception applies to all derivative works unless
 * otherwise stated in LICENSE.txt.
 *
 * Authors:
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

#ifndef _INCLUDE_IBASEMODELENTITY_H
#define _INCLUDE_IBASEMODELENTITY_H

#pragma once

#include <cstdint>

#include "IBaseEntity.h"

#include "CCollisionProperty.h"
#include "CGlowProperty.h"
#include "CHitboxComponent.h"
#include "CNetworkViewOffsetVector.h"
#include "EntityRenderAttribute_t.h"

class CChoreoComponent;
class CDestructiblePartsComponent;
class CRenderComponent;

class IBaseModelEntity : public virtual IBaseEntity
{
public:
    virtual ~IBaseModelEntity() = default;

    virtual CRenderComponent*& CRenderComponent() = 0;
    virtual void CRenderComponentUpdated() = 0;
    virtual CHitboxComponent& CHitboxComponent() = 0;
    virtual void CHitboxComponentUpdated() = 0;
    virtual CChoreoComponent*& ChoreoComponent() = 0;
    virtual void ChoreoComponentUpdated() = 0;
    virtual HitGroup_t& DestructiblePartInitialStateDestructed0() = 0;
    virtual void DestructiblePartInitialStateDestructed0Updated() = 0;
    virtual HitGroup_t& DestructiblePartInitialStateDestructed1() = 0;
    virtual void DestructiblePartInitialStateDestructed1Updated() = 0;
    virtual HitGroup_t& DestructiblePartInitialStateDestructed2() = 0;
    virtual void DestructiblePartInitialStateDestructed2Updated() = 0;
    virtual HitGroup_t& DestructiblePartInitialStateDestructed3() = 0;
    virtual void DestructiblePartInitialStateDestructed3Updated() = 0;
    virtual HitGroup_t& DestructiblePartInitialStateDestructed4() = 0;
    virtual void DestructiblePartInitialStateDestructed4Updated() = 0;
    virtual int32_t& DestructiblePartInitialStateDestructed0_PartIndex() = 0;
    virtual void DestructiblePartInitialStateDestructed0_PartIndexUpdated() = 0;
    virtual int32_t& DestructiblePartInitialStateDestructed1_PartIndex() = 0;
    virtual void DestructiblePartInitialStateDestructed1_PartIndexUpdated() = 0;
    virtual int32_t& DestructiblePartInitialStateDestructed2_PartIndex() = 0;
    virtual void DestructiblePartInitialStateDestructed2_PartIndexUpdated() = 0;
    virtual int32_t& DestructiblePartInitialStateDestructed3_PartIndex() = 0;
    virtual void DestructiblePartInitialStateDestructed3_PartIndexUpdated() = 0;
    virtual int32_t& DestructiblePartInitialStateDestructed4_PartIndex() = 0;
    virtual void DestructiblePartInitialStateDestructed4_PartIndexUpdated() = 0;
    virtual bool& DestructiblePartInitialStateDestructed0_GenerateBreakpieces() = 0;
    virtual void DestructiblePartInitialStateDestructed0_GenerateBreakpiecesUpdated() = 0;
    virtual bool& DestructiblePartInitialStateDestructed1_GenerateBreakpieces() = 0;
    virtual void DestructiblePartInitialStateDestructed1_GenerateBreakpiecesUpdated() = 0;
    virtual bool& DestructiblePartInitialStateDestructed2_GenerateBreakpieces() = 0;
    virtual void DestructiblePartInitialStateDestructed2_GenerateBreakpiecesUpdated() = 0;
    virtual bool& DestructiblePartInitialStateDestructed3_GenerateBreakpieces() = 0;
    virtual void DestructiblePartInitialStateDestructed3_GenerateBreakpiecesUpdated() = 0;
    virtual bool& DestructiblePartInitialStateDestructed4_GenerateBreakpieces() = 0;
    virtual void DestructiblePartInitialStateDestructed4_GenerateBreakpiecesUpdated() = 0;
    virtual CDestructiblePartsComponent*& DestructiblePartsSystemComponent() = 0;
    virtual void DestructiblePartsSystemComponentUpdated() = 0;
    virtual float& DissolveStartTime() = 0;
    virtual void DissolveStartTimeUpdated() = 0;
    virtual CEntityIOOutput& OnIgnite() = 0;
    virtual void OnIgniteUpdated() = 0;
    virtual RenderMode_t& RenderMode() = 0;
    virtual void RenderModeUpdated() = 0;
    virtual RenderFx_t& RenderFX() = 0;
    virtual void RenderFXUpdated() = 0;
    virtual bool& AllowFadeInView() = 0;
    virtual void AllowFadeInViewUpdated() = 0;
    virtual Color& Render() = 0;
    virtual void RenderUpdated() = 0;
    virtual CUtlVector<EntityRenderAttribute_t>& RenderAttributes() = 0;
    virtual void RenderAttributesUpdated() = 0;
    virtual bool& RenderToCubemaps() = 0;
    virtual void RenderToCubemapsUpdated() = 0;
    virtual bool& NoInterpolate() = 0;
    virtual void NoInterpolateUpdated() = 0;
    virtual CCollisionProperty& Collision() = 0;
    virtual void CollisionUpdated() = 0;
    virtual CGlowProperty& Glow() = 0;
    virtual void GlowUpdated() = 0;
    virtual float& GlowBackfaceMult() = 0;
    virtual void GlowBackfaceMultUpdated() = 0;
    virtual float& FadeMinDist() = 0;
    virtual void FadeMinDistUpdated() = 0;
    virtual float& FadeMaxDist() = 0;
    virtual void FadeMaxDistUpdated() = 0;
    virtual float& FadeScale() = 0;
    virtual void FadeScaleUpdated() = 0;
    virtual float& ShadowStrength() = 0;
    virtual void ShadowStrengthUpdated() = 0;
    virtual uint8_t& ObjectCulling() = 0;
    virtual void ObjectCullingUpdated() = 0;
    virtual CNetworkViewOffsetVector& ViewOffset() = 0;
    virtual void ViewOffsetUpdated() = 0;
    virtual uint32_t* DisabledHitGroups() = 0;
};

#endif // _INCLUDE_IBASEMODELENTITY_H
