#pragma once
#include <cstdint>

enum class CanPlaySequence_t : uint32_t
{
    CANNOT_PLAY = 0,
    CAN_PLAY_NOW = 1,
    CAN_PLAY_ENQUEUED = 2,
};
