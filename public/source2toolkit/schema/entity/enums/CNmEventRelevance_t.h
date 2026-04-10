#pragma once
#include <cstdint>

enum class CNmEventRelevance_t : uint32_t
{
    ClientOnly = 0,
    ServerOnly = 1,
    ClientAndServer = 2,
};
