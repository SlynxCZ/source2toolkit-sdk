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

#ifndef _INCLUDE_IFUNCMOVELINEAR_H
#define _INCLUDE_IFUNCMOVELINEAR_H

#pragma once

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

#include "IBaseToggle.h"

#include "../enums/MoveLinearAuthoredPos_t.h"

class CFuncMoveLinear;

class IFuncMoveLinear : public virtual IBaseToggle
{
public:
    virtual ~IFuncMoveLinear() = default;
    CFuncMoveLinear* GetOriginal() { return reinterpret_cast<CFuncMoveLinear*>(IEntityInstance::GetOriginal()); }

    virtual ::MoveLinearAuthoredPos_t& AuthoredPosition() = 0;
    virtual void AuthoredPositionUpdated() = 0;
    virtual QAngle& MoveEntitySpace() = 0;
    virtual void MoveEntitySpaceUpdated() = 0;
    virtual Vector& MoveDirParentSpace() = 0;
    virtual void MoveDirParentSpaceUpdated() = 0;
    virtual CUtlSymbolLarge& SoundStart() = 0;
    virtual void SoundStartUpdated() = 0;
    virtual CUtlSymbolLarge& SoundStop() = 0;
    virtual void SoundStopUpdated() = 0;
    virtual CUtlSymbolLarge& CurrentSound() = 0;
    virtual void CurrentSoundUpdated() = 0;
    virtual float& BlockDamage() = 0;
    virtual void BlockDamageUpdated() = 0;
    virtual float& StartPosition() = 0;
    virtual void StartPositionUpdated() = 0;
    virtual ::CEntityIOOutput& OnFullyOpen() = 0;
    virtual void OnFullyOpenUpdated() = 0;
    virtual ::CEntityIOOutput& OnFullyClosed() = 0;
    virtual void OnFullyClosedUpdated() = 0;
    virtual bool& CreateMovableNavMesh() = 0;
    virtual void CreateMovableNavMeshUpdated() = 0;
    virtual bool& AllowMovableNavMeshDockingOnEntireEntity() = 0;
    virtual void AllowMovableNavMeshDockingOnEntireEntityUpdated() = 0;
    virtual bool& CreateNavObstacle() = 0;
    virtual void CreateNavObstacleUpdated() = 0;
    static IFuncMoveLinear* FromOriginal(CFuncMoveLinear* p);
};

#endif // _INCLUDE_IFUNCMOVELINEAR_H
