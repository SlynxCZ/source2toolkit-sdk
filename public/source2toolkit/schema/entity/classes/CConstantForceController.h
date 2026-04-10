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

class CConstantForceController
{
public:
    DECLARE_SCHEMA_CLASS(CConstantForceController);

    SCHEMA_FIELD(Vector, m_linear);
    SCHEMA_FIELD(RotationVector, m_angular);
    SCHEMA_FIELD(Vector, m_linearSave);
    SCHEMA_FIELD(RotationVector, m_angularSave);
};
