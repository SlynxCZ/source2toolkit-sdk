#pragma once
#include <cstdint>

enum class BoneTransformSpace_t : int32_t
{
    BoneTransformSpace_Invalid = -1,
    BoneTransformSpace_Parent = 0,
    BoneTransformSpace_Model = 1,
    BoneTransformSpace_World = 2,
};
