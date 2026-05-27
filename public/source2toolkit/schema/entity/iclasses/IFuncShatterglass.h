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

#ifndef _INCLUDE_IFUNCSHATTERGLASS_H
#define _INCLUDE_IFUNCSHATTERGLASS_H

#pragma once

#include <cstdint>

#include "IBaseModelEntity.h"

class InfoForResourceTypeIMaterial2;

class IFuncShatterglass : public virtual IBaseModelEntity
{
public:
    virtual ~IFuncShatterglass() = default;

    virtual matrix3x4_t& MatPanelTransform() = 0;
    virtual void MatPanelTransformUpdated() = 0;
    virtual matrix3x4_t& MatPanelTransformWsTemp() = 0;
    virtual void MatPanelTransformWsTempUpdated() = 0;
    virtual CUtlVector<uint32_t>& ShatterGlassShards() = 0;
    virtual void ShatterGlassShardsUpdated() = 0;
    virtual Vector2D& PanelSize() = 0;
    virtual void PanelSizeUpdated() = 0;
    virtual float& LastShatterSoundEmitTime() = 0;
    virtual void LastShatterSoundEmitTimeUpdated() = 0;
    virtual float& LastCleanupTime() = 0;
    virtual void LastCleanupTimeUpdated() = 0;
    virtual float& InitAtTime() = 0;
    virtual void InitAtTimeUpdated() = 0;
    virtual float& GlassThickness() = 0;
    virtual void GlassThicknessUpdated() = 0;
    virtual float& SpawnInvulnerability() = 0;
    virtual void SpawnInvulnerabilityUpdated() = 0;
    virtual bool& BreakSilent() = 0;
    virtual void BreakSilentUpdated() = 0;
    virtual bool& BreakShardless() = 0;
    virtual void BreakShardlessUpdated() = 0;
    virtual bool& Broken() = 0;
    virtual void BrokenUpdated() = 0;
    virtual bool& GlassNavIgnore() = 0;
    virtual void GlassNavIgnoreUpdated() = 0;
    virtual bool& GlassInFrame() = 0;
    virtual void GlassInFrameUpdated() = 0;
    virtual bool& StartBroken() = 0;
    virtual void StartBrokenUpdated() = 0;
    virtual uint8_t& InitialDamageType() = 0;
    virtual void InitialDamageTypeUpdated() = 0;
    virtual CUtlSymbolLarge& DamagePositioningEntityName01() = 0;
    virtual void DamagePositioningEntityName01Updated() = 0;
    virtual CUtlSymbolLarge& DamagePositioningEntityName02() = 0;
    virtual void DamagePositioningEntityName02Updated() = 0;
    virtual CUtlSymbolLarge& DamagePositioningEntityName03() = 0;
    virtual void DamagePositioningEntityName03Updated() = 0;
    virtual CUtlSymbolLarge& DamagePositioningEntityName04() = 0;
    virtual void DamagePositioningEntityName04Updated() = 0;
    virtual CUtlVector<Vector>& InitialDamagePositions() = 0;
    virtual void InitialDamagePositionsUpdated() = 0;
    virtual CUtlVector<Vector>& ExtraDamagePositions() = 0;
    virtual void ExtraDamagePositionsUpdated() = 0;
    virtual CUtlVector<Vector4D>& InitialPanelVertices() = 0;
    virtual void InitialPanelVerticesUpdated() = 0;
    virtual CEntityIOOutput& OnBroken() = 0;
    virtual void OnBrokenUpdated() = 0;
    virtual uint8_t& SurfaceType() = 0;
    virtual void SurfaceTypeUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIMaterial2>& MaterialDamageBase() = 0;
    virtual void MaterialDamageBaseUpdated() = 0;
};

#endif // _INCLUDE_IFUNCSHATTERGLASS_H
