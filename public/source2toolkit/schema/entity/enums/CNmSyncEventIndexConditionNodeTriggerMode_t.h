#pragma once
#include <cstdint>

enum class CNmSyncEventIndexConditionNode::TriggerMode_t : uint8_t
{
    ExactlyAtEventIndex = 0,
    GreaterThanEqualToEventIndex = 1,
};
