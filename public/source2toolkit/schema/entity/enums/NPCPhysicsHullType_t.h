#pragma once
#include <cstdint>

enum class NPCPhysicsHullType_t : uint32_t
{
    eInvalid = 0,
    eGroundCapsule = 1,
    eCenteredCapsule = 2,
    eGenericCapsule = 3,
    eGroundBox = 4,
};
