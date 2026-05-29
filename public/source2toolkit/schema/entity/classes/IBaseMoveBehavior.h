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

#ifndef _INCLUDE_IBASEMOVEBEHAVIOR_H
#define _INCLUDE_IBASEMOVEBEHAVIOR_H

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

#include "IPathKeyFrame.h"

class CBaseMoveBehavior;
class CPathKeyFrame;

class IBaseMoveBehavior : public virtual IPathKeyFrame
{
public:
    virtual ~IBaseMoveBehavior() = default;

    virtual int32_t& PositionInterpolator() = 0;
    virtual void PositionInterpolatorUpdated() = 0;
    virtual int32_t& RotationInterpolator() = 0;
    virtual void RotationInterpolatorUpdated() = 0;
    virtual float& AnimStartTime() = 0;
    virtual void AnimStartTimeUpdated() = 0;
    virtual float& AnimEndTime() = 0;
    virtual void AnimEndTimeUpdated() = 0;
    virtual float& AverageSpeedAcrossFrame() = 0;
    virtual void AverageSpeedAcrossFrameUpdated() = 0;
    virtual CHandle<CPathKeyFrame>& CurrentKeyFrame() = 0;
    virtual void CurrentKeyFrameUpdated() = 0;
    virtual CHandle<CPathKeyFrame>& TargetKeyFrame() = 0;
    virtual void TargetKeyFrameUpdated() = 0;
    virtual CHandle<CPathKeyFrame>& PreKeyFrame() = 0;
    virtual void PreKeyFrameUpdated() = 0;
    virtual CHandle<CPathKeyFrame>& PostKeyFrame() = 0;
    virtual void PostKeyFrameUpdated() = 0;
    virtual float& TimeIntoFrame() = 0;
    virtual void TimeIntoFrameUpdated() = 0;
    virtual int32_t& Direction() = 0;
    virtual void DirectionUpdated() = 0;
    static IBaseMoveBehavior* FromOriginal(CBaseMoveBehavior* p);
};

#endif // _INCLUDE_IBASEMOVEBEHAVIOR_H
