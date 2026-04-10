#pragma once
#include <cstdint>

enum class DestructiblePartDestructionDeathBehavior_t : uint32_t
{
    eDoNotKill = 0,
    eKill = 1,
    eGib = 2,
    eRemove = 3,
};
