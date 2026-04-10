#pragma once
#include <cstdint>

enum class ScriptedOnDeath_t : int32_t
{
    SS_ONDEATH_NOT_APPLICABLE = -1,
    SS_ONDEATH_UNDEFINED = 0,
    SS_ONDEATH_RAGDOLL = 1,
    SS_ONDEATH_ANIMATED_DEATH = 2,
};
