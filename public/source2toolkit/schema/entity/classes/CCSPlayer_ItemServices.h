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

#include "CPlayer_ItemServices.h"

class CBasePlayerWeapon;

class CCSPlayer_ItemServices : public CPlayer_ItemServices
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayer_ItemServices);

    SCHEMA_FIELD(bool, m_bHasDefuser);
    SCHEMA_FIELD(bool, m_bHasHelmet);

public:
    /// <summary>Drop active weapon.</summary>
    void DropActivePlayerWeapon(CBasePlayerWeapon* pActiveWeapon);
    /// <summary>Remove all weapons.</summary>
    void RemoveWeapons();
    /// <summary>Give item.</summary>
    CBasePlayerWeapon* GiveNamedItem(const char* pszItem);
};
