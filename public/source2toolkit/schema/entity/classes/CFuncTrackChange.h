#pragma once
#include "CBaseEntity.h"
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

#include "CFuncPlatRot.h"
#include "../enums/TRAIN_CODE.h"

class CFuncTrackTrain;
class CPathTrack;

class CFuncTrackChange : public CFuncPlatRot
{
public:
    DECLARE_SCHEMA_CLASS(CFuncTrackChange);

    SCHEMA_FIELD(CPathTrack*, m_trackTop);
    SCHEMA_FIELD(CPathTrack*, m_trackBottom);
    SCHEMA_FIELD(CFuncTrackTrain*, m_train);
    SCHEMA_FIELD(CUtlSymbolLarge, m_trackTopName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_trackBottomName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_trainName);
    SCHEMA_FIELD(TRAIN_CODE, m_code);
    SCHEMA_FIELD(int32_t, m_targetState);
    SCHEMA_FIELD(int32_t, m_use);

public:
    static CFuncTrackChange* New(const char* className)
    {
        return CBaseEntity::New<CFuncTrackChange>(className);
    }

    static CFuncTrackChange* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncTrackChange>(iIndex);
    }

    static CFuncTrackChange* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
