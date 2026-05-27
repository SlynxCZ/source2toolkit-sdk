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

#ifndef _INCLUDE_IROPEKEYFRAME_H
#define _INCLUDE_IROPEKEYFRAME_H

#pragma once

#include <cstdint>

#include "IBaseModelEntity.h"

class CBaseEntity;
class InfoForResourceTypeIMaterial2;

class IRopeKeyframe : public virtual IBaseModelEntity
{
public:
    virtual ~IRopeKeyframe() = default;

    virtual uint16_t& RopeFlags() = 0;
    virtual void RopeFlagsUpdated() = 0;
    virtual CUtlSymbolLarge& NextLinkName() = 0;
    virtual void NextLinkNameUpdated() = 0;
    virtual int16_t& Slack() = 0;
    virtual void SlackUpdated() = 0;
    virtual float& Width() = 0;
    virtual void WidthUpdated() = 0;
    virtual float& TextureScale() = 0;
    virtual void TextureScaleUpdated() = 0;
    virtual uint8_t& Segments() = 0;
    virtual void SegmentsUpdated() = 0;
    virtual bool& ConstrainBetweenEndpoints() = 0;
    virtual void ConstrainBetweenEndpointsUpdated() = 0;
    virtual CUtlSymbolLarge& StrRopeMaterialModel() = 0;
    virtual void StrRopeMaterialModelUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIMaterial2>& RopeMaterialModelIndex() = 0;
    virtual void RopeMaterialModelIndexUpdated() = 0;
    virtual uint8_t& Subdiv() = 0;
    virtual void SubdivUpdated() = 0;
    virtual uint8_t& ChangeCount() = 0;
    virtual void ChangeCountUpdated() = 0;
    virtual int16_t& RopeLength() = 0;
    virtual void RopeLengthUpdated() = 0;
    virtual uint8_t& LockedPoints() = 0;
    virtual void LockedPointsUpdated() = 0;
    virtual bool& CreatedFromMapFile() = 0;
    virtual void CreatedFromMapFileUpdated() = 0;
    virtual float& ScrollSpeed() = 0;
    virtual void ScrollSpeedUpdated() = 0;
    virtual bool& StartPointValid() = 0;
    virtual void StartPointValidUpdated() = 0;
    virtual bool& EndPointValid() = 0;
    virtual void EndPointValidUpdated() = 0;
    virtual CHandle<CBaseEntity>& StartPoint() = 0;
    virtual void StartPointUpdated() = 0;
    virtual CHandle<CBaseEntity>& EndPoint() = 0;
    virtual void EndPointUpdated() = 0;
};

#endif // _INCLUDE_IROPEKEYFRAME_H
