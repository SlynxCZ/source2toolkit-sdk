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

#include "CBaseAnimGraphController.h"
#include "CBodyComponentSkeletonInstance.h"

class CBodyComponentBaseAnimGraph : public CBodyComponentSkeletonInstance
{
public:
    DECLARE_SCHEMA_CLASS(CBodyComponentBaseAnimGraph);

    SCHEMA_FIELD(CBaseAnimGraphController, m_animationController);
};
