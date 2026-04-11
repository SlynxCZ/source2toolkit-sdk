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
                               CEntityInstance* pIgnoreEntity,
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
                                CEntityInstance* pIgnoreEntity,
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
