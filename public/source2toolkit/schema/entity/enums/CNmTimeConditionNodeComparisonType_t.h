#pragma once
#include <cstdint>

enum class CNmTimeConditionNode::ComparisonType_t : uint8_t
{
    PercentageThroughState = 0,
    PercentageThroughSyncEvent = 1,
    ElapsedTime = 2,
};
