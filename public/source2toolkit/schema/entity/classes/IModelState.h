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

#ifndef _INCLUDE_IMODELSTATE_H
#define _INCLUDE_IMODELSTATE_H

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
#include <cstdint>

class IPhysAggregateInstance;
class InfoForResourceTypeCModel;

class IModelState
{
public:
    virtual ~IModelState() = default;

    virtual CStrongHandle<InfoForResourceTypeCModel>& Model() = 0;
    virtual void ModelUpdated() = 0;
    virtual CUtlSymbolLarge& ModelName() = 0;
    virtual void ModelNameUpdated() = 0;
    virtual IPhysAggregateInstance*& VPhysicsAggregate() = 0;
    virtual void VPhysicsAggregateUpdated() = 0;
    virtual float& RootBoneOffset_x() = 0;
    virtual void RootBoneOffset_xUpdated() = 0;
    virtual float& RootBoneOffset_y() = 0;
    virtual void RootBoneOffset_yUpdated() = 0;
    virtual float& RootBoneOffset_z() = 0;
    virtual void RootBoneOffset_zUpdated() = 0;
    virtual uint8_t& RootBoneOffsetResetSerialNumber() = 0;
    virtual void RootBoneOffsetResetSerialNumberUpdated() = 0;
    virtual bool& ClientClothCreationSuppressed() = 0;
    virtual void ClientClothCreationSuppressedUpdated() = 0;
    virtual uint8_t& AnimStateNoInterpSerialNumber() = 0;
    virtual void AnimStateNoInterpSerialNumberUpdated() = 0;
    virtual uint64_t& MeshGroupMask() = 0;
    virtual void MeshGroupMaskUpdated() = 0;
    virtual CUtlVector<int32_t>& BodyGroupChoices() = 0;
    virtual void BodyGroupChoicesUpdated() = 0;
    virtual int8_t& IdealMotionType() = 0;
    virtual void IdealMotionTypeUpdated() = 0;
    virtual int8_t& ForceLOD() = 0;
    virtual void ForceLODUpdated() = 0;
    virtual int8_t& ClothUpdateFlags() = 0;
    virtual void ClothUpdateFlagsUpdated() = 0;
};

#endif // _INCLUDE_IMODELSTATE_H
