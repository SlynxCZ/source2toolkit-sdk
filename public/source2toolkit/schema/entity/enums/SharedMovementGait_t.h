#pragma once
#include <cstdint>

enum class SharedMovementGait_t : int8_t
{
    eInvalid = -1,
    eSlow = 0,
    eMedium = 1,
    eFast = 2,
    eVeryFast = 3,
    eCount = 4,
};
