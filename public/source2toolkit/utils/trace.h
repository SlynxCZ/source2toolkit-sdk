/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
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
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
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
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

/**

* @file trace.h
* @brief High-level helper functions for ray tracing and collision queries.
*
* These functions provide simplified access to the IToolkitTrace interface.
*
* Used for:
* * Line traces (raycasts)
* * Bullet simulation
* * Collision detection
* * Visibility checks
*
* @note Internally wraps IToolkitTrace.
  */

#pragma once

#ifdef SOURCE2TOOLKIT_CORE
#include "core/raytrace.h"
#else
#include "source2toolkit/IToolkitTrace.h"
#endif

/**

* @brief Performs a directional trace using angles.
*
* @param vecStart Starting position
* @param angAngles Direction angles
* @param pIgnoreEntity Entity to ignore (optional)
* @param pTraceOptions Trace configuration
*
* @return TraceResult containing hit data
*
* @note Useful for forward traces (e.g. player view direction)
  */
TraceResult UTIL_TraceShape(const Vector& vecStart,
                            const QAngle& angAngles,
                            CEntityInstance* pIgnoreEntity,
                            TraceOptions* pTraceOptions);

/**

* @brief Performs a trace between two points.
*
* @param vecStart Start position
* @param vecEnd End position
* @param pIgnoreEntity Entity to ignore
* @param pTraceOptions Trace configuration
*
* @return TraceResult
  */
TraceResult UTIL_TraceEndShape(const Vector& vecStart,
                               const Vector& vecEnd,
                               CBaseEntity* pIgnoreEntity,
                               TraceOptions* pTraceOptions);

/**

* @brief Performs a hull (box) trace.
*
* @param vecStart Start position
* @param vecEnd End position
* @param vecMins Minimum bounds
* @param vecMaxs Maximum bounds
* @param pIgnoreEntity Entity to ignore
* @param pTraceOptions Trace configuration
*
* @return TraceResult
*
* @note Used for player movement or bounding box collision
  */
TraceResult UTIL_TraceHullShape(const Vector& vecStart,
                                const Vector& vecEnd,
                                const Vector& vecMins,
                                const Vector& vecMaxs,
                                CBaseEntity* pIgnoreEntity,
                                TraceOptions* pTraceOptions);

/**

* @brief Advanced trace using custom filter and ray.
*
* @param vecStart Start position
* @param vecEnd End position
* @param pTraceFilter Custom filter
* @param pRay Ray definition
*
* @return TraceResult
*
* @note Low-level API for advanced use cases
  */
TraceResult UTIL_TraceShapeEx(const Vector& vecStart,
                              const Vector& vecEnd,
                              CTraceFilter* pTraceFilter,
                              Ray_t* pRay);

/**

* @brief Returns the contents bitmask at a world position.
*
* @param vTestPos Position to test
* @param nContentsMask Mask of content types to query
*
* @return Contents bitmask
  */
uint64 UTIL_PointContents(const Vector* const vTestPos,
                          uint64 nContentsMask);

/**

* @brief Checks whether a nav area overlaps with an entity.
*
* @param rArea Nav area pointer
* @param rEntity Entity to test against
* @param bExtrudeHullHeight Whether to extrude by hull height
*
* @return true if overlapping
  */
bool UTIL_CheckAreaOverlappingEntity(const void* const rArea,
                                     const CBaseEntity* const rEntity,
                                     bool bExtrudeHullHeight);

/**

* @brief Retrieves the world-space AABB of an entity.
*
* @param rEntity Entity to query
* @param pMinsOut Output minimum bounds
* @param pMaxsOut Output maximum bounds
  */
void UTIL_GetEntityWorldSpaceAABB(const CBaseEntity* const rEntity,
                                  Vector* pMinsOut,
                                  Vector* pMaxsOut);
