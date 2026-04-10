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

#include "CEntitySubclassVDataBase.h"
#include "../enums/ParticleAttachment_t.h"

class CPrecipitationVData : public CEntitySubclassVDataBase
{
public:
    DECLARE_SCHEMA_CLASS(CPrecipitationVData);

    SCHEMA_FIELD(float, m_flInnerDistance);
    SCHEMA_FIELD(ParticleAttachment_t, m_nAttachType);
    SCHEMA_FIELD(bool, m_bBatchSameVolumeType);
    SCHEMA_FIELD(int32_t, m_nRTEnvCP);
    SCHEMA_FIELD(int32_t, m_nRTEnvCPComponent);
    SCHEMA_FIELD(CUtlString, m_szModifier);
};
