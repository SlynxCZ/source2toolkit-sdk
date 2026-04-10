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


class CGameSceneNode;

class CBodyComponent : public CEntityComponent
{
public:
    DECLARE_SCHEMA_CLASS(CBodyComponent);

    SCHEMA_FIELD(CGameSceneNode*, m_pSceneNode);
    SCHEMA_FIELD(CEntityInstance*, __m_pChainEntity);
};
