#pragma once
#include <cstdint>

enum class DecalFlags_t : uint32_t
{
    eNone = 0,
    eCannotClear = 1,
    eDecalProjectToBackfaces = 2,
    eAll = 4294967295,
    eAllButCannotClear = 4294967294,
};
