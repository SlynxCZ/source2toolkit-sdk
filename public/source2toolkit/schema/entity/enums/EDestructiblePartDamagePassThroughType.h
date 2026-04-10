#pragma once
#include <cstdint>

enum class EDestructiblePartDamagePassThroughType : uint32_t
{
    Normal = 0,
    Absorb = 1,
    InvincibleAbsorb = 2,
    InvinciblePassthrough = 3,
};
