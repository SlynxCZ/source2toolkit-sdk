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

#include "CInButtonState.h"
#include "CPlayerPawnComponent.h"

class CPlayer_MovementServices : public CPlayerPawnComponent
{
public:
    DECLARE_SCHEMA_CLASS(CPlayer_MovementServices);

    SCHEMA_FIELD(int32_t, m_nImpulse);
    SCHEMA_FIELD(CInButtonState, m_nButtons);
    SCHEMA_FIELD(uint64_t, m_nQueuedButtonDownMask);
    SCHEMA_FIELD(uint64_t, m_nQueuedButtonChangeMask);
    SCHEMA_FIELD(uint64_t, m_nButtonDoublePressed);
    SCHEMA_FIELD_POINTER(uint32_t, m_pButtonPressedCmdNumber);
    SCHEMA_FIELD(uint32_t, m_nLastCommandNumberProcessed);
    SCHEMA_FIELD(uint64_t, m_nToggleButtonDownMask);
    SCHEMA_FIELD(float, m_flMaxspeed);
    SCHEMA_FIELD_POINTER(float, m_arrForceSubtickMoveWhen);
    SCHEMA_FIELD(float, m_flForwardMove);
    SCHEMA_FIELD(float, m_flLeftMove);
    SCHEMA_FIELD(float, m_flUpMove);
    SCHEMA_FIELD(Vector, m_vecLastMovementImpulses);
    SCHEMA_FIELD(QAngle, m_vecOldViewAngles);
};
