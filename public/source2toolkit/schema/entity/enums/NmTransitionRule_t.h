#pragma once
#include <cstdint>

enum class NmTransitionRule_t : uint8_t
{
    AllowTransition = 0,
    ConditionallyAllowTransition = 1,
    BlockTransition = 2,
};
