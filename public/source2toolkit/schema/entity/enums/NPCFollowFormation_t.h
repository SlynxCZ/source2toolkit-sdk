#pragma once
#include <cstdint>

enum class NPCFollowFormation_t : int32_t
{
    Default = -1,
    CloseCircle = 0,
    WideCircle = 1,
    MediumCircle = 5,
    Sidekick = 6,
};
