#pragma once
#include <cstdint>

enum class BlendKeyType : uint32_t
{
    BlendKey_UserValue = 0,
    BlendKey_Velocity = 1,
    BlendKey_Distance = 2,
    BlendKey_RemainingDistance = 3,
};
