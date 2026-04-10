#pragma once
#include <cstdint>

enum class HandshakeTagState_t : uint8_t
{
    eInactive = 0,
    eActive = 1,
    eMomentarilyInactive = 2,
};
