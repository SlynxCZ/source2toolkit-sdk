#pragma once
#include <cstdint>

enum class SequenceFinishNotifyState_t : uint8_t
{
    eDoNotNotify = 0,
    eNotifyWhenFinished = 1,
    eNotifyTriggered = 2,
};
