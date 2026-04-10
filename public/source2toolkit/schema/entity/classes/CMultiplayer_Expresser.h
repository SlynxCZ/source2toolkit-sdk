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

#include "CAI_ExpresserWithFollowup.h"

class CMultiplayer_Expresser : public CAI_ExpresserWithFollowup
{
public:
    DECLARE_SCHEMA_CLASS(CMultiplayer_Expresser);

    SCHEMA_FIELD(bool, m_bAllowMultipleScenes);
};
