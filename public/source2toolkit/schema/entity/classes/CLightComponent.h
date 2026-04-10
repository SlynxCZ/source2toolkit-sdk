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

#include "InfoForResourceTypeCTextureBase.h"

class CLightComponent : public CEntityComponent
{
public:
    DECLARE_SCHEMA_CLASS(CLightComponent);

    SCHEMA_FIELD(CEntityInstance*, __m_pChainEntity);
    SCHEMA_FIELD(Color, m_Color);
    SCHEMA_FIELD(Color, m_SecondaryColor);
    SCHEMA_FIELD(float, m_flBrightness);
    SCHEMA_FIELD(float, m_flBrightnessScale);
    SCHEMA_FIELD(float, m_flBrightnessMult);
    SCHEMA_FIELD(float, m_flRange);
    SCHEMA_FIELD(float, m_flFalloff);
    SCHEMA_FIELD(float, m_flAttenuation0);
    SCHEMA_FIELD(float, m_flAttenuation1);
    SCHEMA_FIELD(float, m_flAttenuation2);
    SCHEMA_FIELD(float, m_flTheta);
    SCHEMA_FIELD(float, m_flPhi);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeCTextureBase >, m_hLightCookie);
    SCHEMA_FIELD(int32_t, m_nCascades);
    SCHEMA_FIELD(int32_t, m_nCastShadows);
    SCHEMA_FIELD(int32_t, m_nShadowWidth);
    SCHEMA_FIELD(int32_t, m_nShadowHeight);
    SCHEMA_FIELD(bool, m_bRenderDiffuse);
    SCHEMA_FIELD(int32_t, m_nRenderSpecular);
    SCHEMA_FIELD(bool, m_bRenderTransmissive);
    SCHEMA_FIELD(float, m_flOrthoLightWidth);
    SCHEMA_FIELD(float, m_flOrthoLightHeight);
    SCHEMA_FIELD(int32_t, m_nStyle);
    SCHEMA_FIELD(CUtlString, m_Pattern);
    SCHEMA_FIELD(int32_t, m_nCascadeRenderStaticObjects);
    SCHEMA_FIELD(float, m_flShadowCascadeCrossFade);
    SCHEMA_FIELD(float, m_flShadowCascadeDistanceFade);
    SCHEMA_FIELD(float, m_flShadowCascadeDistance0);
    SCHEMA_FIELD(float, m_flShadowCascadeDistance1);
    SCHEMA_FIELD(float, m_flShadowCascadeDistance2);
    SCHEMA_FIELD(float, m_flShadowCascadeDistance3);
    SCHEMA_FIELD(int32_t, m_nShadowCascadeResolution0);
    SCHEMA_FIELD(int32_t, m_nShadowCascadeResolution1);
    SCHEMA_FIELD(int32_t, m_nShadowCascadeResolution2);
    SCHEMA_FIELD(int32_t, m_nShadowCascadeResolution3);
    SCHEMA_FIELD(bool, m_bUsesBakedShadowing);
    SCHEMA_FIELD(int32_t, m_nShadowPriority);
    SCHEMA_FIELD(int32_t, m_nBakedShadowIndex);
    SCHEMA_FIELD(int32_t, m_nLightPathUniqueId);
    SCHEMA_FIELD(int32_t, m_nLightMapUniqueId);
    SCHEMA_FIELD(bool, m_bRenderToCubemaps);
    SCHEMA_FIELD(bool, m_bAllowSSTGeneration);
    SCHEMA_FIELD(int32_t, m_nDirectLight);
    SCHEMA_FIELD(int32_t, m_nIndirectLight);
    SCHEMA_FIELD(bool, m_bDynamicBounce);
    SCHEMA_FIELD(float, m_flFadeMinDist);
    SCHEMA_FIELD(float, m_flFadeMaxDist);
    SCHEMA_FIELD(float, m_flShadowFadeMinDist);
    SCHEMA_FIELD(float, m_flShadowFadeMaxDist);
    SCHEMA_FIELD(bool, m_bEnabled);
    SCHEMA_FIELD(bool, m_bFlicker);
    SCHEMA_FIELD(bool, m_bPrecomputedFieldsValid);
    SCHEMA_FIELD(Vector, m_vPrecomputedBoundsMins);
    SCHEMA_FIELD(Vector, m_vPrecomputedBoundsMaxs);
    SCHEMA_FIELD(Vector, m_vPrecomputedOBBOrigin);
    SCHEMA_FIELD(QAngle, m_vPrecomputedOBBAngles);
    SCHEMA_FIELD(Vector, m_vPrecomputedOBBExtent);
    SCHEMA_FIELD(float, m_flPrecomputedMaxRange);
    SCHEMA_FIELD(int32_t, m_nFogLightingMode);
    SCHEMA_FIELD(float, m_flFogContributionStength);
    SCHEMA_FIELD(float, m_flNearClipPlane);
    SCHEMA_FIELD(Color, m_SkyColor);
    SCHEMA_FIELD(float, m_flSkyIntensity);
    SCHEMA_FIELD(Color, m_SkyAmbientBounce);
    SCHEMA_FIELD(bool, m_bUseSecondaryColor);
    SCHEMA_FIELD(bool, m_bMixedShadows);
    SCHEMA_FIELD(float, m_flLightStyleStartTime);
    SCHEMA_FIELD(float, m_flCapsuleLength);
    SCHEMA_FIELD(float, m_flMinRoughness);
    SCHEMA_FIELD(bool, m_bPvsModifyEntity);
};
