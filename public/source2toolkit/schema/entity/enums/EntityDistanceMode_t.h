#pragma once
#include <cstdint>

enum class EntityDistanceMode_t : uint32_t
{
    eOriginToOrigin = 0,
    eCenterToCenter = 1,
    eAxisToAxis = 2,
};
