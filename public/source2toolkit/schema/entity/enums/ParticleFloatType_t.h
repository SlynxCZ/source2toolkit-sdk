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

#ifndef _INCLUDE_PARTICLEFLOATTYPE_T_H
#define _INCLUDE_PARTICLEFLOATTYPE_T_H

#pragma once

#include <cstdint>

enum class ParticleFloatType_t : int32_t
{
    PF_TYPE_INVALID = -1,
    PF_TYPE_LITERAL = 0,
    PF_TYPE_NAMED_VALUE = 1,
    PF_TYPE_RANDOM_UNIFORM = 2,
    PF_TYPE_RANDOM_BIASED = 3,
    PF_TYPE_COLLECTION_AGE = 4,
    PF_TYPE_ENDCAP_AGE = 5,
    PF_TYPE_CONTROL_POINT_COMPONENT = 6,
    PF_TYPE_CONTROL_POINT_CHANGE_AGE = 7,
    PF_TYPE_CONTROL_POINT_SPEED = 8,
    PF_TYPE_PARTICLE_DETAIL_LEVEL = 9,
    PF_TYPE_CONCURRENT_DEF_COUNT = 10,
    PF_TYPE_CLOSEST_CAMERA_DISTANCE = 11,
    PF_TYPE_SNAPSHOT_COUNT = 12,
    PF_TYPE_SNAPSHOT_CHANGED = 13,
    PF_TYPE_RENDERER_CAMERA_DISTANCE = 14,
    PF_TYPE_RENDERER_CAMERA_DOT_PRODUCT = 15,
    PF_TYPE_PARTICLE_NOISE = 16,
    PF_TYPE_PARTICLE_AGE = 17,
    PF_TYPE_PARTICLE_AGE_NORMALIZED = 18,
    PF_TYPE_PARTICLE_FLOAT = 19,
    PF_TYPE_PARTICLE_INITIAL_FLOAT = 20,
    PF_TYPE_PARTICLE_VECTOR_COMPONENT = 21,
    PF_TYPE_PARTICLE_INITIAL_VECTOR_COMPONENT = 22,
    PF_TYPE_PARTICLE_SPEED = 23,
    PF_TYPE_PARTICLE_NUMBER = 24,
    PF_TYPE_PARTICLE_NUMBER_NORMALIZED = 25,
    PF_TYPE_PARTICLE_ROPE_SEGMENT = 26,
    PF_TYPE_PARTICLE_ROPE_SEGMENT_NORMALIZED = 27,
    PF_TYPE_PARTICLE_SCREENSPACE_CAMERA_DISTANCE = 28,
    PF_TYPE_PARTICLE_SCREENSPACE_CAMERA_DOT_PRODUCT = 29,
    PF_TYPE_COUNT = 30,
};

#endif // _INCLUDE_PARTICLEFLOATTYPE_T_H
