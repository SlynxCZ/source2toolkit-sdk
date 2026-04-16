#include "source2toolkit/utils/gameconfig.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/gameconfig.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitGameConfig.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

static IToolkitGameConfig* GetGameConfig()
{
#ifdef SOURCE2TOOLKIT_CORE
    return shared::g_pGameConfig;
#else
    return g_ToolkitAPI->GameConfig();
#endif
}

const char* UTIL_GetLibrary(const char* pchName)
{
    return GetGameConfig()->GetLibrary(pchName);
}

const char* UTIL_GetSignature(const char* pchName)
{
    return GetGameConfig()->GetSignature(pchName);
}

const char* UTIL_GetSymbol(const char* pchName)
{
    return GetGameConfig()->GetSymbol(pchName);
}

const char* UTIL_GetPatch(const char* pchName)
{
    return GetGameConfig()->GetPatch(pchName);
}

int UTIL_GetOffset(const char* pchName)
{
    return GetGameConfig()->GetOffset(pchName);
}
