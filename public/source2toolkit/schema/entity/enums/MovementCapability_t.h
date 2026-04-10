#pragma once
#include <cstdint>

enum class MovementCapability_t : uint32_t
{
    eStrafe = 0,
    eIdleTurn = 1,
    eStart = 2,
    eStop = 3,
    eInstantStop = 4,
    eShuffle = 5,
    ePlantedTurn = 6,
    eCount = 7,
};
