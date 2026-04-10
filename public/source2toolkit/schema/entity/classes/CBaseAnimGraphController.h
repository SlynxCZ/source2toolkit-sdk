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

#include "../enums/AnimationAlgorithm_t.h"
#include "../enums/AnimLoopMode_t.h"
#include "CAnimGraphNetworkedVariables.h"
#include "CSkeletonAnimationController.h"
#include "ExternalAnimGraph_t.h"
#include "ExternalAnimGraphHandle_t.h"
#include "InfoForResourceTypeCNmGraphDefinition.h"
#include "ResourceId_t.h"
#include "../enums/SequenceFinishNotifyState_t.h"

class CBaseAnimGraph;

class CBaseAnimGraphController : public CSkeletonAnimationController
{
public:
    DECLARE_SCHEMA_CLASS(CBaseAnimGraphController);

    SCHEMA_FIELD(AnimationAlgorithm_t, m_nAnimationAlgorithm);
    SCHEMA_FIELD(CAnimGraphNetworkedVariables, m_animGraphNetworkedVars);
    SCHEMA_FIELD(ExternalAnimGraphHandle_t, m_nNextExternalGraphHandle);
    SCHEMA_FIELD(CUtlVector<CGlobalSymbol>, m_vecSecondarySkeletonNames);
    SCHEMA_FIELD(CUtlVector<CHandle<CBaseAnimGraph>>, m_vecSecondarySkeletons);
    SCHEMA_FIELD(int32_t, m_nSecondarySkeletonMasterCount);
    SCHEMA_FIELD(float, m_flSoundSyncTime);
    SCHEMA_FIELD(uint32_t, m_nActiveIKChainMask);
    SCHEMA_FIELD(int32_t, m_hSequence);
    SCHEMA_FIELD(float, m_flSeqStartTime);
    SCHEMA_FIELD(float, m_flSeqFixedCycle);
    SCHEMA_FIELD(AnimLoopMode_t, m_nAnimLoopMode);
    SCHEMA_FIELD(float, m_flPlaybackRate);
    SCHEMA_FIELD(SequenceFinishNotifyState_t, m_nNotifyState);
    SCHEMA_FIELD(bool, m_bNetworkedAnimationInputsChanged);
    SCHEMA_FIELD(bool, m_bNetworkedSequenceChanged);
    SCHEMA_FIELD(bool, m_bLastUpdateSkipped);
    SCHEMA_FIELD(bool, m_bSequenceFinished);
    SCHEMA_FIELD(int32_t, m_nPrevAnimUpdateTick);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeCNmGraphDefinition >, m_hGraphDefinitionAG2);
    SCHEMA_FIELD(CUtlVector<uint8_t>, m_serializedPoseRecipeAG2);
    SCHEMA_FIELD(int32_t, m_nSerializePoseRecipeSizeAG2);
    SCHEMA_FIELD(int32_t, m_nSerializePoseRecipeVersionAG2);
    SCHEMA_FIELD(int32_t, m_nServerGraphInstanceIteration);
    SCHEMA_FIELD(int32_t, m_nServerSerializationContextIteration);
    SCHEMA_FIELD(ResourceId_t, m_primaryGraphId);
    SCHEMA_FIELD(CUtlVector<ResourceId_t>, m_vecExternalGraphIds);
    SCHEMA_FIELD(CUtlVector<ResourceId_t>, m_vecExternalClipIds);
    SCHEMA_FIELD(CGlobalSymbol, m_sAnimGraph2Identifier);
    SCHEMA_FIELD(CUtlVector<ExternalAnimGraph_t>, m_vecExternalGraphs);
};
