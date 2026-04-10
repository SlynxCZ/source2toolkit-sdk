#pragma once
#include <cstdint>

enum class CNmRootMotionData::SamplingMode_t : uint8_t
{
    Delta = 0,
    WorldSpace = 1,
};
