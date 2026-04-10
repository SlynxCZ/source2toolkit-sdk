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

#include "CPlayerPawnComponent.h"

class CCSPlayer_RadioServices : public CPlayerPawnComponent
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayer_RadioServices);

    SCHEMA_FIELD(float, m_flGotHostageTalkTimer);
    SCHEMA_FIELD(float, m_flDefusingTalkTimer);
    SCHEMA_FIELD(float, m_flC4PlantTalkTimer);
    SCHEMA_FIELD_POINTER(float, m_flRadioTokenSlots);
    SCHEMA_FIELD(bool, m_bIgnoreRadio);
};
