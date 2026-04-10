#pragma once
#include <cstdint>

enum class EntitySubclassScope_t : int32_t
{
    SUBCLASS_SCOPE_NONE = -1,
    SUBCLASS_SCOPE_PRECIPITATION = 0,
    SUBCLASS_SCOPE_PLAYER_WEAPONS = 1,
    SUBCLASS_SCOPE_COUNT = 2,
};
