#pragma once
#include <cstdint>

enum class EDestructibleParts_DestroyParameterFlags : uint32_t
{
    None = 0,
    GenerateBreakpieces = 1,
    SetBodyGroupAndCollisionState = 2,
    EnableFlinches = 4,
    ForceDamageApply = 8,
    IgnoreKillEntityFlag = 16,
    IgnoreHealthCheck = 32,
    Default = 7,
};
