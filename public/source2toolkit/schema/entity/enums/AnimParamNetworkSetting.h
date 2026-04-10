#pragma once
#include <cstdint>

enum class AnimParamNetworkSetting : uint32_t
{
    Auto = 0,
    AlwaysNetwork = 1,
    NeverNetwork = 2,
};
