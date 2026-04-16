#include "source2toolkit/utils/convars.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/convars.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitConVars.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

static IToolkitConVars* GetConVars()
{
#ifdef SOURCE2TOOLKIT_CORE
    return &convars::convarsManager;
#else
    return g_ToolkitAPI->ConVars();
#endif
}

uint16 UTIL_FindConVar(const char* name)
{
    return GetConVars()->GetConvarAccessIndexByName(name);
}

int UTIL_GetConVarInt(uint16 accessIndex)
{
    return GetConVars()->GetInt(accessIndex);
}

float UTIL_GetConVarFloat(uint16 accessIndex)
{
    return GetConVars()->GetFloat(accessIndex);
}

bool UTIL_GetConVarBool(uint16 accessIndex)
{
    return GetConVars()->GetBool(accessIndex);
}

void UTIL_SetConVarInt(uint16 accessIndex, int value)
{
    GetConVars()->SetInt(accessIndex, value);
}

void UTIL_SetConVarFloat(uint16 accessIndex, float value)
{
    GetConVars()->SetFloat(accessIndex, value);
}

void UTIL_SetConVarBool(uint16 accessIndex, bool value)
{
    GetConVars()->SetBool(accessIndex, value);
}

const char* UTIL_GetConVarString(uint16 accessIndex)
{
    return GetConVars()->GetString(accessIndex);
}

void UTIL_SetConVarString(uint16 accessIndex, const char* value)
{
    GetConVars()->SetString(accessIndex, value);
}

void* UTIL_GetConVarValueAddress(uint16 accessIndex)
{
    return GetConVars()->GetValueAddress(accessIndex);
}

void UTIL_SetConVarValue(uint16 accessIndex, const void* value)
{
    GetConVars()->SetValue(accessIndex, value);
}