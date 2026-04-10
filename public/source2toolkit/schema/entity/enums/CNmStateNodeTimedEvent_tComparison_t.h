#pragma once
#include <cstdint>

enum class CNmStateNode::TimedEvent_t::Comparison_t : uint8_t
{
    LessThanEqual = 0,
    GreaterThanEqual = 1,
};
