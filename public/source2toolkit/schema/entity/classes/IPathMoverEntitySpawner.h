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

#ifndef _INCLUDE_IPATHMOVERENTITYSPAWNER_H
#define _INCLUDE_IPATHMOVERENTITYSPAWNER_H

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

#include "ILogicalEntity.h"

class CFuncMover;
class CPathMover;
class CPathMoverEntitySpawner;

class IPathMoverEntitySpawner : public virtual ILogicalEntity
{
public:
    virtual ~IPathMoverEntitySpawner() = default;

    virtual CUtlSymbolLarge* SpawnTemplates() = 0;
    virtual int32_t& SpawnIndex() = 0;
    virtual void SpawnIndexUpdated() = 0;
    virtual CHandle<CPathMover>& PathMover() = 0;
    virtual void PathMoverUpdated() = 0;
    virtual float& SpawnFrequencySeconds() = 0;
    virtual void SpawnFrequencySecondsUpdated() = 0;
    virtual float& SpawnFrequencyDistToNearestMover() = 0;
    virtual void SpawnFrequencyDistToNearestMoverUpdated() = 0;
    virtual int32_t& MaxActive() = 0;
    virtual void MaxActiveUpdated() = 0;
    virtual int32_t& SpawnNum() = 0;
    virtual void SpawnNumUpdated() = 0;
    virtual float& LastSpawnTime() = 0;
    virtual void LastSpawnTimeUpdated() = 0;
    virtual bool& Enabled() = 0;
    virtual void EnabledUpdated() = 0;
    virtual bool& DestroyMoverOnArrivedAtEnd() = 0;
    virtual void DestroyMoverOnArrivedAtEndUpdated() = 0;
    virtual CUtlVector<CHandle<CFuncMover>>& QueuedRemovals() = 0;
    virtual void QueuedRemovalsUpdated() = 0;
    virtual ::CEntityIOOutput& OnTemplateSpawned() = 0;
    virtual void OnTemplateSpawnedUpdated() = 0;
    virtual ::CEntityIOOutput& OnTemplateGroupSpawned() = 0;
    virtual void OnTemplateGroupSpawnedUpdated() = 0;
    static IPathMoverEntitySpawner* FromOriginal(CPathMoverEntitySpawner* p);
};

#endif // _INCLUDE_IPATHMOVERENTITYSPAWNER_H
