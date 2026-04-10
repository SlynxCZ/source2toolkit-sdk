#pragma once
#include <cstdint>

enum class BeginDeathLifeStateTransition_t : uint8_t
{
    TRANSITION_TO_LIFESTATE_DYING = 0,
    TRANSITION_TO_LIFESTATE_DEAD = 1,
};
