#pragma once
#include <cstdint>

enum class NavScopeFlags_t : uint8_t
{
    eGround = 1,
    eAir = 2,
    eAll = 3,
    eNone = 0,
};
