#pragma once
#include <cstdint>

enum class DecalRtEncoding_t : uint8_t
{
    kDecalInvalid = 255,
    kDecalMin = 0,
    kDecalBlood = 0,
    kDecalCloak = 1,
    kDecalMax = 2,
    kDecalDefault = 0,
};
