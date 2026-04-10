#pragma once
#include <cstdint>

enum class JumpCorrectionMethod : uint32_t
{
    ScaleMotion = 0,
    AddCorrectionDelta = 1,
};
