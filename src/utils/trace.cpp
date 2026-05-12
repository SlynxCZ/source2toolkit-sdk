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

#include "source2toolkit/utils/trace.h"

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

TraceResult UTIL_TraceShape(const Vector& vecStart, const QAngle& angAngles, CBaseEntity* pIgnoreEntity, TraceOptions* pTraceOptions)
{
    return GetTrace()->TraceShape(vecStart, angAngles, pIgnoreEntity, pTraceOptions);
}

TraceResult UTIL_TraceEndShape(const Vector& vecStart, const Vector& vecEnd, CBaseEntity* pIgnoreEntity, TraceOptions* pTraceOptions)
{
    return GetTrace()->TraceEndShape(vecStart, vecEnd, pIgnoreEntity, pTraceOptions);
}

TraceResult UTIL_TraceHullShape(const Vector& vecStart, const Vector& vecEnd, const Vector& vecMins, const Vector& vecMaxs, CBaseEntity* pIgnoreEntity, TraceOptions* pTraceOptions)
{
    return GetTrace()->TraceHullShape(vecStart, vecEnd, vecMins, vecMaxs, pIgnoreEntity, pTraceOptions);
}

TraceResult UTIL_TraceShapeEx(const Vector& vecStart, const Vector& vecEnd, CTraceFilter* pTraceFilter, Ray_t* pRay)
{
    return GetTrace()->TraceShapeEx(vecStart, vecEnd, pTraceFilter, pRay);
}

uint64 UTIL_PointContents(const Vector* const vTestPos, uint64 nContentsMask)
{
    return GetTrace()->PointContents(vTestPos, nContentsMask);
}

bool UTIL_CheckAreaOverlappingEntity(const void* const rArea, const CBaseEntity* const rEntity, bool bExtrudeHullHeight)
{
    return GetTrace()->CheckAreaOverlappingEntity(rArea, rEntity, bExtrudeHullHeight);
}

void UTIL_GetEntityWorldSpaceAABB(const CBaseEntity* const rEntity, Vector* pMinsOut, Vector* pMaxsOut)
{
    GetTrace()->GetEntityWorldSpaceAABB(rEntity, pMinsOut, pMaxsOut);
}