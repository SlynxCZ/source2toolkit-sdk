#pragma once
#include "igameevents.h"
#include "ehandle.h"
#include "entityhandle.h"
#include "vector.h"
#include "utlsymbol.h"
#include "utlsymbollarge.h"
#include "utlstring.h"
#include "utlstringtoken.h"
#include "source2toolkit/IToolkitTypes.h"
#include "source2toolkit/schema/entityio.h"
#include "source2toolkit/schema/schema.h"
#include <cstdint>

class CBaseFlex;

class CAI_Expresser
{
public:
    DECLARE_SCHEMA_CLASS(CAI_Expresser);

    SCHEMA_FIELD(float, m_flStopTalkTime);
    SCHEMA_FIELD(float, m_flStopTalkTimeWithoutDelay);
    SCHEMA_FIELD(float, m_flQueuedSpeechTime);
    SCHEMA_FIELD(float, m_flBlockedTalkTime);
    SCHEMA_FIELD(int32_t, m_voicePitch);
    SCHEMA_FIELD(float, m_flLastTimeAcceptedSpeak);
    SCHEMA_FIELD(bool, m_bAllowSpeakingInterrupts);
    SCHEMA_FIELD(bool, m_bConsiderSceneInvolvementAsSpeech);
    SCHEMA_FIELD(bool, m_bSceneEntityDisabled);
    SCHEMA_FIELD(int32_t, m_nLastSpokenPriority);
    SCHEMA_FIELD(CBaseFlex*, m_pOuter);
};
