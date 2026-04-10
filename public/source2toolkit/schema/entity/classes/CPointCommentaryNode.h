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

#include "CBaseAnimGraph.h"

class CBaseEntity;

class CPointCommentaryNode : public CBaseAnimGraph
{
public:
    DECLARE_SCHEMA_CLASS(CPointCommentaryNode);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPreCommands);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPostCommands);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszCommentaryFile);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszViewTarget);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hViewTarget);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hViewTargetAngles);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszViewPosition);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hViewPosition);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hViewPositionMover);
    SCHEMA_FIELD(bool, m_bPreventMovement);
    SCHEMA_FIELD(bool, m_bUnderCrosshair);
    SCHEMA_FIELD(bool, m_bUnstoppable);
    SCHEMA_FIELD(float, m_flFinishedTime);
    SCHEMA_FIELD(Vector, m_vecFinishOrigin);
    SCHEMA_FIELD(QAngle, m_vecOriginalAngles);
    SCHEMA_FIELD(QAngle, m_vecFinishAngles);
    SCHEMA_FIELD(bool, m_bPreventChangesWhileMoving);
    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(Vector, m_vecTeleportOrigin);
    SCHEMA_FIELD(float, m_flAbortedPlaybackAt);
    SCHEMA_FIELD(CEntityIOOutput, m_pOnCommentaryStarted);
    SCHEMA_FIELD(CEntityIOOutput, m_pOnCommentaryStopped);
    SCHEMA_FIELD(bool, m_bActive);
    SCHEMA_FIELD(float, m_flStartTime);
    SCHEMA_FIELD(float, m_flStartTimeInCommentary);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszTitle);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSpeakers);
    SCHEMA_FIELD(int32_t, m_iNodeNumber);
    SCHEMA_FIELD(int32_t, m_iNodeNumberMax);
    SCHEMA_FIELD(bool, m_bListenedTo);

public:
    static CPointCommentaryNode* New(const char* className)
    {
        return CBaseEntity::New<CPointCommentaryNode>(className);
    }

    static CPointCommentaryNode* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointCommentaryNode>(iIndex);
    }

    static CPointCommentaryNode* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
