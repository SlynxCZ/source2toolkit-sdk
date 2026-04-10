#pragma once
#include <cstdint>

enum class ChoiceMethod : uint32_t
{
    WeightedRandom = 0,
    WeightedRandomNoRepeat = 1,
    Iterate = 2,
    IterateRandom = 3,
};
