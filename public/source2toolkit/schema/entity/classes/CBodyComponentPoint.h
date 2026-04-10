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

#include "CBodyComponent.h"
#include "CGameSceneNode.h"

class CBodyComponentPoint : public CBodyComponent
{
public:
    DECLARE_SCHEMA_CLASS(CBodyComponentPoint);

    SCHEMA_FIELD(CGameSceneNode, m_sceneNode);
};
