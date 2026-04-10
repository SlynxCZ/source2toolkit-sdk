#pragma once
#include <cstdint>

enum class OrientationWarpRootMotionSource_t : uint32_t
{
    eAnimationOrProcedural = 0,
    eAnimationOnly = 1,
    eProceduralOnly = 2,
};
