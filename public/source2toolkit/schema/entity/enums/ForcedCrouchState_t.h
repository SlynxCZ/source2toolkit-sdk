#pragma once
#include <cstdint>

enum class ForcedCrouchState_t : uint32_t
{
    FORCEDCROUCH_NONE = 0,
    FORCEDCROUCH_CROUCHED = 1,
    FORCEDCROUCH_UNCROUCHED = 2,
};
