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