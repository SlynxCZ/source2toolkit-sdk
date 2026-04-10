#pragma once
#include <cstdint>

enum class RenderMeshSlotType_t : int8_t
{
    RENDERMESH_SLOT_INVALID = -1,
    RENDERMESH_SLOT_PER_VERTEX = 0,
    RENDERMESH_SLOT_PER_INSTANCE = 1,
};
