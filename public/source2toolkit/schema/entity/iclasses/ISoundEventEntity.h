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

#ifndef _INCLUDE_ISOUNDEVENTENTITY_H
#define _INCLUDE_ISOUNDEVENTENTITY_H

#pragma once

#include <cstdint>

#include "IBaseEntity.h"

class ISoundEventEntity : public virtual IBaseEntity
{
public:
    virtual ~ISoundEventEntity() = default;

    virtual bool& StartOnSpawn() = 0;
    virtual void StartOnSpawnUpdated() = 0;
    virtual bool& ToLocalPlayer() = 0;
    virtual void ToLocalPlayerUpdated() = 0;
    virtual bool& StopOnNew() = 0;
    virtual void StopOnNewUpdated() = 0;
    virtual bool& SaveRestore() = 0;
    virtual void SaveRestoreUpdated() = 0;
    virtual bool& SavedIsPlaying() = 0;
    virtual void SavedIsPlayingUpdated() = 0;
    virtual float& SavedElapsedTime() = 0;
    virtual void SavedElapsedTimeUpdated() = 0;
    virtual CUtlSymbolLarge& SourceEntityName() = 0;
    virtual void SourceEntityNameUpdated() = 0;
    virtual CUtlSymbolLarge& AttachmentName() = 0;
    virtual void AttachmentNameUpdated() = 0;
    virtual CEntityIOOutput& OnSoundFinished() = 0;
    virtual void OnSoundFinishedUpdated() = 0;
    virtual float& ClientCullRadius() = 0;
    virtual void ClientCullRadiusUpdated() = 0;
    virtual CUtlSymbolLarge& SoundName() = 0;
    virtual void SoundNameUpdated() = 0;
    virtual CEntityHandle& Source() = 0;
    virtual void SourceUpdated() = 0;
    virtual int32_t& EntityIndexSelection() = 0;
    virtual void EntityIndexSelectionUpdated() = 0;
};

#endif // _INCLUDE_ISOUNDEVENTENTITY_H
