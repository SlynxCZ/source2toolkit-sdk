//
// Created by Michal Přikryl on 11.03.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
#include "CBasePlayerWeapon.h"
#include "strtools.h"

CCSWeaponBaseVData* CBasePlayerWeapon::GetWeaponVData()
{
    return (CCSWeaponBaseVData*)GetVData();
}

const char* CBasePlayerWeapon::GetWeaponClassname()
{
    const char* pszClassname = GetClassname();
    if (V_StringHasPrefixCaseSensitive(pszClassname, "item_"))
        return pszClassname;

    switch (m_AttributeManager().m_Item().m_iItemDefinitionIndex)
    {
    case 23:
        return "weapon_mp5sd";
    case 41:
        return "weapon_knifegg";
    case 42:
        return "weapon_knife";
    case 59:
        return "weapon_knife_t";
    case 60:
        return "weapon_m4a1_silencer";
    case 61:
        return "weapon_usp_silencer";
    case 63:
        return "weapon_cz75a";
    case 64:
        return "weapon_revolver";
    default:
        return pszClassname;
    }
}