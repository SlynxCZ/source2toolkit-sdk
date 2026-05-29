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

#ifndef _INCLUDE_ITRIGGERLERPOBJECT_H
#define _INCLUDE_ITRIGGERLERPOBJECT_H

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

#include "IBaseTrigger.h"

class CBaseEntity;
class CTriggerLerpObject;
class lerpdata_t;

class ITriggerLerpObject : public virtual IBaseTrigger
{
public:
    virtual ~ITriggerLerpObject() = default;

    virtual CUtlSymbolLarge& LerpTarget() = 0;
    virtual void LerpTargetUpdated() = 0;
    virtual CUtlSymbolLarge& LerpTargetAttachment() = 0;
    virtual void LerpTargetAttachmentUpdated() = 0;
    virtual float& LerpDuration() = 0;
    virtual void LerpDurationUpdated() = 0;
    virtual bool& AttachedEntityWasParented() = 0;
    virtual void AttachedEntityWasParentedUpdated() = 0;
    virtual bool& LerpRestoreMoveType() = 0;
    virtual void LerpRestoreMoveTypeUpdated() = 0;
    virtual bool& SingleLerpObject() = 0;
    virtual void SingleLerpObjectUpdated() = 0;
    virtual CUtlVector<lerpdata_t>& LerpingObjects() = 0;
    virtual void LerpingObjectsUpdated() = 0;
    virtual CUtlSymbolLarge& LerpEffect() = 0;
    virtual void LerpEffectUpdated() = 0;
    virtual CUtlSymbolLarge& LerpSound() = 0;
    virtual void LerpSoundUpdated() = 0;
    virtual bool& AttachTouchingObject() = 0;
    virtual void AttachTouchingObjectUpdated() = 0;
    virtual CHandle<CBaseEntity>& EntityToWaitForDisconnect() = 0;
    virtual void EntityToWaitForDisconnectUpdated() = 0;
    virtual ::CEntityIOOutput& OnLerpStarted() = 0;
    virtual void OnLerpStartedUpdated() = 0;
    virtual ::CEntityIOOutput& OnLerpFinished() = 0;
    virtual void OnLerpFinishedUpdated() = 0;
    virtual ::CEntityIOOutput& OnDetached() = 0;
    virtual void OnDetachedUpdated() = 0;
    static ITriggerLerpObject* FromOriginal(CTriggerLerpObject* p);
    static ITriggerLerpObject* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_ITRIGGERLERPOBJECT_H
