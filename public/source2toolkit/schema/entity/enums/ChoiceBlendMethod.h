#pragma once
#include <cstdint>

enum class ChoiceBlendMethod : uint32_t
{
    SingleBlendTime = 0,
    PerChoiceBlendTimes = 1,
};
