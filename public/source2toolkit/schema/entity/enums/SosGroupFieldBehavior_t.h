#pragma once
#include <cstdint>

enum class SosGroupFieldBehavior_t : uint32_t
{
    kIgnore = 0,
    kBranch = 1,
    kMatch = 2,
};
