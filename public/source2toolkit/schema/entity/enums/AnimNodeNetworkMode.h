#pragma once
#include <cstdint>

enum class AnimNodeNetworkMode : uint32_t
{
    ServerAuthoritative = 0,
    ClientSimulate = 1,
};
