/**
 * vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
 * AlliedModders LLC. All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
 * AlliedModders LLC give you permission to link the code of this program
 * (as well as its derivative works) to "Counter-Strike 2," "Source 2,"
 * "Steam," and any Game MODs or server software running on software by
 * Valve Corporation. You must obey the GNU General Public License in all
 * respects for all other code used.
 *
 * Additionally, this exception applies to all derivative works unless
 * otherwise stated in LICENSE.txt.
 *
 * Authors:
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

#include "source2toolkit/utils/mysql.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/mysql.h"
#include "core/pluginapi.h"
#include "core/shared.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitMySQL.h"
#endif

static IToolkitMySQL* GetMySQL()
{
#ifdef SOURCE2TOOLKIT_CORE
    return &mysql::mysqlManager;
#else
    return g_ToolkitAPI->MySQL();
#endif
}

IToolkitMySQLConnection* UTIL_CreateMySQLConnection(ToolkitMySQLConnectionInfo info)
{
    return GetMySQL()->CreateConnection(info);
}

void UTIL_MySQLConnect(IToolkitMySQLConnection* pConnection, ToolkitMySQLConnectCallbackFunc callback)
{
    pConnection->Connect(callback);
}

void UTIL_MySQLQuery(IToolkitMySQLConnection* pConnection, char* query, ToolkitMySQLQueryCallbackFunc callback)
{
    pConnection->Query(query, callback);
}

void UTIL_MySQLQueryFormat(IToolkitMySQLConnection* pConnection, ToolkitMySQLQueryCallbackFunc callback, const char* query, ...)
{
    char szQuery[4096];

    va_list args;
    va_start(args, query);

#ifdef SOURCE2TOOLKIT_CORE
    pluginApi.Format(szQuery, sizeof(szQuery), query, args);
#else
    g_ToolkitAPI->Format(szQuery, sizeof(szQuery), query, args);
#endif

    va_end(args);

    pConnection->Query(szQuery, callback);
}

void UTIL_MySQLExecuteTransaction(IToolkitMySQLConnection* pConnection, ToolkitMySQLTransaction txn, ToolkitMySQLTransactionSuccessCallbackFunc success, ToolkitMySQLTransactionFailureCallbackFunc failure)
{
    pConnection->ExecuteTransaction(txn, success, failure);
}

std::string UTIL_MySQLEscape(IToolkitMySQLConnection* pConnection, char* string)
{
    return pConnection->Escape(string);
}

std::string UTIL_MySQLEscape(IToolkitMySQLConnection* pConnection, const char* string)
{
    return pConnection->Escape(string);
}

void UTIL_DestroyMySQLConnection(IToolkitMySQLConnection* pConnection)
{
    pConnection->Destroy();
}