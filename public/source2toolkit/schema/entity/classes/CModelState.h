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

#include "InfoForResourceTypeCModel.h"

class CModelState
{
public:
    DECLARE_SCHEMA_CLASS(CModelState);

    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeCModel >, m_hModel);
    SCHEMA_FIELD(CUtlSymbolLarge, m_ModelName);
    SCHEMA_FIELD(bool, m_bClientClothCreationSuppressed);
    SCHEMA_FIELD(uint64_t, m_MeshGroupMask);
    SCHEMA_FIELD(CUtlVector<int32_t>, m_nBodyGroupChoices);
    SCHEMA_FIELD(int8_t, m_nIdealMotionType);
    SCHEMA_FIELD(int8_t, m_nForceLOD);
    SCHEMA_FIELD(int8_t, m_nClothUpdateFlags);
};
