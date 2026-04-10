#pragma once
#include <cstdint>

enum class ParticleEntityPos_t : uint32_t
{
    PARTICLE_ABS_ORIGIN = 0,
    PARTICLE_WORLDSPACE_CENTER = 1,
    PARTICLE_EYES = 2,
};
