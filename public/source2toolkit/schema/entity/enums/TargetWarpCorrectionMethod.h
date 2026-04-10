#pragma once
#include <cstdint>

enum class TargetWarpCorrectionMethod : uint32_t
{
    ScaleMotion = 0,
    AddCorrectionDelta = 1,
};
