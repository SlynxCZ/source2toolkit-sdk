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

#include "CPlayerControllerComponent.h"
#include "../enums/MedalRank_t.h"
#include "ServerAuthoritativeWeaponSlot_t.h"

class CCSPlayerController_InventoryServices : public CPlayerControllerComponent
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayerController_InventoryServices);

    SCHEMA_FIELD(uint16_t, m_unMusicID);
    SCHEMA_FIELD_POINTER(MedalRank_t, m_rank);
    SCHEMA_FIELD(int32_t, m_nPersonaDataPublicLevel);
    SCHEMA_FIELD(int32_t, m_nPersonaDataPublicCommendsLeader);
    SCHEMA_FIELD(int32_t, m_nPersonaDataPublicCommendsTeacher);
    SCHEMA_FIELD(int32_t, m_nPersonaDataPublicCommendsFriendly);
    SCHEMA_FIELD(int32_t, m_nPersonaDataXpTrailLevel);
    SCHEMA_FIELD_POINTER(uint32_t, m_unEquippedPlayerSprayIDs);
    SCHEMA_FIELD(uint64_t, m_unCurrentLoadoutHash);
    SCHEMA_FIELD(CUtlVector<ServerAuthoritativeWeaponSlot_t>, m_vecServerAuthoritativeWeaponSlots);
};
