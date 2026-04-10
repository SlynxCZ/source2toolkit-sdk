#pragma once
#include <cstdint>

enum class EDestructiblePartRadiusDamageApplyType : uint32_t
{
    ScaleByExplosionRadius = 0,
    PrioritizeClosestPart = 1,
};
