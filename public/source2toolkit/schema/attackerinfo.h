//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================//
#pragma once

#ifndef ATTACKERINFO_H
#define ATTACKERINFO_H

#include "ehandle.h"
#include "tier1/mempool.h"

class CCSPlayerPawn;

struct AttackerInfo_t
{
    bool m_bNeedInit;
    bool m_bIsPawn;
    bool m_bIsWorld;
    CHandle<CCSPlayerPawn> m_hAttackerPawn;
    int32_t m_nAttackerPlayerSlot;
    int m_iTeamChecked;
    int m_nTeam;
};
static_assert(sizeof(AttackerInfo_t) == 20);

#endif // ATTACKERINFO_H