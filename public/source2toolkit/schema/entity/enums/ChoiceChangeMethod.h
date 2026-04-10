#pragma once
#include <cstdint>

enum class ChoiceChangeMethod : uint32_t
{
    OnReset = 0,
    OnCycleEnd = 1,
    OnResetOrCycleEnd = 2,
};
