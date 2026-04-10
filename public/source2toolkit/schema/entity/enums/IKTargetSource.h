#pragma once
#include <cstdint>

enum class IKTargetSource : uint32_t
{
    IKTARGETSOURCE_Bone = 0,
    IKTARGETSOURCE_AnimgraphParameter = 1,
    IKTARGETSOURCE_COUNT = 2,
};
