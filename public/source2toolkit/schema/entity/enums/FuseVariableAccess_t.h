#pragma once
#include <cstdint>

enum class FuseVariableAccess_t : uint8_t
{
    WRITABLE = 0,
    READ_ONLY = 1,
};
