#pragma once
#include <cstdint>

enum class PulseCursorExecResult_t : uint32_t
{
    Succeeded = 0,
    Canceled = 1,
    Failed = 2,
    OngoingNotify = 3,
};
