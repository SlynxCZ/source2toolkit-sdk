#pragma once
#include <cstdint>

enum class NmTargetWarpRule_t : uint8_t
{
    WarpXY = 0,
    WarpZ = 1,
    WarpXYZ = 2,
    RotationOnly = 3,
    FixedSection = 4,
};
