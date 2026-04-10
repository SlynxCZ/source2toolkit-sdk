#pragma once
#include <cstdint>

enum class BBoxVolumeType_t : uint32_t
{
    BBOX_VOLUME = 0,
    BBOX_DIMENSIONS = 1,
    BBOX_MINS_MAXS = 2,
    BBOX_RADIUS = 3,
};
