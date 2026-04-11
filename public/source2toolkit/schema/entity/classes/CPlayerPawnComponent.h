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


class CCSPlayerPawn;

class CPlayerPawnComponent
{
public:
    DECLARE_SCHEMA_CLASS(CPlayerPawnComponent);

    SCHEMA_FIELD(CEntityInstance*, __m_pChainEntity);

public:
    /// <summary>Get player pawn.</summary>
    CCSPlayerPawn* GetPlayerPawn();
};
