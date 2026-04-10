#pragma once
#include <cstdint>

enum class PulseVariableKeysSource_t : uint32_t
{
    PRIVATE = 0,
    CPP = 1,
    VMAP = 2,
    VMDL = 3,
    XML = 4,
    COUNT = 5,
};
