#pragma once
#include <cstdint>

enum class TargetWarpTimingMethod : uint32_t
{
    ReachDestinationOnRootMotionEnd = 0,
    ReachDestinationOnWarpTagEnd = 1,
};
