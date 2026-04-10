#pragma once
#include <cstdint>

enum class AnimationAlgorithm_t : int8_t
{
    eInvalid = -1,
    eNone = 0,
    eSequence = 1,
    eAnimGraph2 = 2,
    eAnimGraph2Secondary = 3,
    eAnimGraph1 = 4,
    eCount = 5,
};
