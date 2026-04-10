#pragma once
#include <cstdint>

enum class ParticleEndcapMode_t : int32_t
{
    PARTICLE_ENDCAP_ALWAYS_ON = -1,
    PARTICLE_ENDCAP_ENDCAP_OFF = 0,
    PARTICLE_ENDCAP_ENDCAP_ON = 1,
};
