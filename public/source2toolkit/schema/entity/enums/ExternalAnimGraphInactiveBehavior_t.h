#pragma once
#include <cstdint>

enum class ExternalAnimGraphInactiveBehavior_t : uint8_t
{
    eNone = 0,
    eUnbind = 1,
    eUnbindAndDelete = 2,
};
