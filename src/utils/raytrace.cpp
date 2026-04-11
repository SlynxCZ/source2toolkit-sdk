//
// Created by Michal Přikryl on 11.03.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
/**
 * =============================================================================
 * CS2Fixes
 * Copyright (C) 2023-2026 Source2ZE
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "source2toolkit/utils/raytrace.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/raytrace.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitTrace.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

static IToolkitTrace* GetTrace()
{
#ifdef SOURCE2TOOLKIT_CORE
    return &raytrace::rayTrace;
#else
    return g_ToolkitAPI->Trace();
#endif
}

TraceResult UTIL_TraceShape(const Vector& vecStart, const QAngle& angAngles, CEntityInstance* pIgnoreEntity, TraceOptions* pTraceOptions)
{
    return GetTrace()->TraceShape(vecStart, angAngles, pIgnoreEntity, pTraceOptions);
}

TraceResult UTIL_TraceEndShape(const Vector& vecStart, const Vector& vecEnd, CEntityInstance* pIgnoreEntity, TraceOptions* pTraceOptions)
{
    return GetTrace()->TraceEndShape(vecStart, vecEnd, pIgnoreEntity, pTraceOptions);
}

TraceResult UTIL_TraceHullShape(const Vector& vecStart, const Vector& vecEnd, const Vector& vecMins, const Vector& vecMaxs, CEntityInstance* pIgnoreEntity, TraceOptions* pTraceOptions)
{
    return GetTrace()->TraceHullShape(vecStart, vecEnd, vecMins, vecMaxs, pIgnoreEntity, pTraceOptions);
}

TraceResult UTIL_TraceShapeEx(const Vector& vecStart, const Vector& vecEnd, CTraceFilter* pTraceFilter, Ray_t* pRay)
{
    return GetTrace()->TraceShapeEx(vecStart, vecEnd, pTraceFilter, pRay);
}