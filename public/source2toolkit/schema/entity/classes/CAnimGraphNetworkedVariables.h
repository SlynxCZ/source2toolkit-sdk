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

class CAnimGraphNetworkedVariables
{
public:
    DECLARE_SCHEMA_CLASS(CAnimGraphNetworkedVariables);

    SCHEMA_FIELD(CUtlVector<uint32_t>, m_PredNetBoolVariables);
    SCHEMA_FIELD(CUtlVector<uint8_t>, m_PredNetByteVariables);
    SCHEMA_FIELD(CUtlVector<uint16_t>, m_PredNetUInt16Variables);
    SCHEMA_FIELD(CUtlVector<int32_t>, m_PredNetIntVariables);
    SCHEMA_FIELD(CUtlVector<uint32_t>, m_PredNetUInt32Variables);
    SCHEMA_FIELD(CUtlVector<uint64_t>, m_PredNetUInt64Variables);
    SCHEMA_FIELD(CUtlVector<float>, m_PredNetFloatVariables);
    SCHEMA_FIELD(CUtlVector<Vector>, m_PredNetVectorVariables);
    SCHEMA_FIELD(CUtlVector<Quaternion>, m_PredNetQuaternionVariables);
    SCHEMA_FIELD(CUtlVector<CGlobalSymbol>, m_PredNetGlobalSymbolVariables);
    SCHEMA_FIELD(CUtlVector<uint32_t>, m_OwnerOnlyPredNetBoolVariables);
    SCHEMA_FIELD(CUtlVector<uint8_t>, m_OwnerOnlyPredNetByteVariables);
    SCHEMA_FIELD(CUtlVector<uint16_t>, m_OwnerOnlyPredNetUInt16Variables);
    SCHEMA_FIELD(CUtlVector<int32_t>, m_OwnerOnlyPredNetIntVariables);
    SCHEMA_FIELD(CUtlVector<uint32_t>, m_OwnerOnlyPredNetUInt32Variables);
    SCHEMA_FIELD(CUtlVector<uint64_t>, m_OwnerOnlyPredNetUInt64Variables);
    SCHEMA_FIELD(CUtlVector<float>, m_OwnerOnlyPredNetFloatVariables);
    SCHEMA_FIELD(CUtlVector<Vector>, m_OwnerOnlyPredNetVectorVariables);
    SCHEMA_FIELD(CUtlVector<Quaternion>, m_OwnerOnlyPredNetQuaternionVariables);
    SCHEMA_FIELD(CUtlVector<CGlobalSymbol>, m_OwnerOnlyPredNetGlobalSymbolVariables);
    SCHEMA_FIELD(int32_t, m_nBoolVariablesCount);
    SCHEMA_FIELD(int32_t, m_nOwnerOnlyBoolVariablesCount);
    SCHEMA_FIELD(int32_t, m_nRandomSeedOffset);
    SCHEMA_FIELD(float, m_flLastTeleportTime);
};
