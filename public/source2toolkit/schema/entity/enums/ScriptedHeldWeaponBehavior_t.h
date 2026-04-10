#pragma once
#include <cstdint>

enum class ScriptedHeldWeaponBehavior_t : int32_t
{
    eInvalid = -1,
    eHolster = 0,
    eDeploy = 1,
    eDrop = 2,
};
