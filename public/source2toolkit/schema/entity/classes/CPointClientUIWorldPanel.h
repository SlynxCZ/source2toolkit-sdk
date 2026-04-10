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

#include "CBaseClientUIEntity.h"

class CPointClientUIWorldPanel : public CBaseClientUIEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointClientUIWorldPanel);

    SCHEMA_FIELD(bool, m_bIgnoreInput);
    SCHEMA_FIELD(bool, m_bLit);
    SCHEMA_FIELD(bool, m_bFollowPlayerAcrossTeleport);
    SCHEMA_FIELD(float, m_flWidth);
    SCHEMA_FIELD(float, m_flHeight);
    SCHEMA_FIELD(float, m_flDPI);
    SCHEMA_FIELD(float, m_flInteractDistance);
    SCHEMA_FIELD(float, m_flDepthOffset);
    SCHEMA_FIELD(uint32_t, m_unOwnerContext);
    SCHEMA_FIELD(uint32_t, m_unHorizontalAlign);
    SCHEMA_FIELD(uint32_t, m_unVerticalAlign);
    SCHEMA_FIELD(uint32_t, m_unOrientation);
    SCHEMA_FIELD(bool, m_bAllowInteractionFromAllSceneWorlds);
    SCHEMA_FIELD(CUtlVector<CUtlSymbolLarge>, m_vecCSSClasses);
    SCHEMA_FIELD(bool, m_bOpaque);
    SCHEMA_FIELD(bool, m_bNoDepth);
    SCHEMA_FIELD(bool, m_bVisibleWhenParentNoDraw);
    SCHEMA_FIELD(bool, m_bRenderBackface);
    SCHEMA_FIELD(bool, m_bUseOffScreenIndicator);
    SCHEMA_FIELD(bool, m_bExcludeFromSaveGames);
    SCHEMA_FIELD(bool, m_bGrabbable);
    SCHEMA_FIELD(bool, m_bOnlyRenderToTexture);
    SCHEMA_FIELD(bool, m_bDisableMipGen);
    SCHEMA_FIELD(int32_t, m_nExplicitImageLayout);

public:
    static CPointClientUIWorldPanel* New(const char* className)
    {
        return CBaseEntity::New<CPointClientUIWorldPanel>(className);
    }

    static CPointClientUIWorldPanel* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointClientUIWorldPanel>(iIndex);
    }

    static CPointClientUIWorldPanel* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
