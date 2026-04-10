#pragma once
#include <cstdint>

enum class NavScope_t : uint8_t
{
    eGround = 0,
    eAir = 1,
    eCount = 2,
    eFirst = 0,
    eInvalid = 255,
};
