#pragma once
#include <cstdint>

enum class RenderSlotType_t : int8_t
{
    RENDER_SLOT_INVALID = -1,
    RENDER_SLOT_PER_VERTEX = 0,
    RENDER_SLOT_PER_INSTANCE = 1,
};
