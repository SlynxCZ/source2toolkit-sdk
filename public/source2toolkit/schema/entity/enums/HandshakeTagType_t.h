#pragma once
#include <cstdint>

enum class HandshakeTagType_t : int32_t
{
    eInvalid = -1,
    eTask = 0,
    eMovement = 1,
    eCount = 2,
};
