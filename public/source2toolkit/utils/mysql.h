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

/**
 * @file mysql.h
 * @brief High-level helper functions for MySQL database operations.
 *
 * These functions provide simplified access to the IToolkitMySQL interfaces.
 *
 * Used for:
 * * MySQL connections
 * * Query execution
 * * Transactions
 * * String escaping
 *
 * @note Internally wraps IToolkitMySQL.
 */

#ifndef _INCLUDE_ITOOLKIT_UTILS_MYSQL_H
#define _INCLUDE_ITOOLKIT_UTILS_MYSQL_H

#pragma once

#ifdef SOURCE2TOOLKIT_CORE
#include "core/mysql.h"
#else
#include "source2toolkit/IToolkitMySQL.h"
#endif

/**
 * @brief Creates a new MySQL connection instance.
 *
 * @param info Connection configuration data.
 * @return Newly created MySQL connection.
 */
IToolkitMySQLConnection* UTIL_CreateConnection(ToolkitMySQLConnectionInfo info);

/**
 * @brief Establishes a connection to the MySQL server.
 *
 * @param pConnection MySQL connection instance.
 * @param callback Callback invoked after connection attempt.
 */
void UTIL_MySQLConnect(IToolkitMySQLConnection* pConnection, ToolkitMySQLConnectCallbackFunc callback);

/**
 * @brief Executes a raw SQL query.
 *
 * @param pConnection MySQL connection instance.
 * @param query SQL query string.
 * @param callback Callback invoked with query result.
 */
void UTIL_MySQLQuery(IToolkitMySQLConnection* pConnection, char* query, ToolkitMySQLQueryCallbackFunc callback);

/**
 * @brief Executes a formatted SQL query.
 *
 * @param pConnection MySQL connection instance.
 * @param callback Callback invoked with query result.
 * @param query SQL format string.
 */
void UTIL_MySQLQueryFormat(IToolkitMySQLConnection* pConnection, ToolkitMySQLQueryCallbackFunc callback, const char* query, ...);

/**
 * @brief Executes multiple queries as a transaction.
 *
 * @param pConnection MySQL connection instance.
 * @param txn Transaction query batch.
 * @param success Callback invoked on success.
 * @param failure Callback invoked on failure.
 */
void UTIL_MySQLExecuteTransaction(IToolkitMySQLConnection* pConnection, ToolkitMySQLTransaction txn, ToolkitMySQLTransactionSuccessCallbackFunc success, ToolkitMySQLTransactionFailureCallbackFunc failure);

/**
 * @brief Escapes a mutable string for safe SQL usage.
 *
 * @param pConnection MySQL connection instance.
 * @param string Input string.
 * @return Escaped string.
 */
std::string UTIL_MySQLEscape(IToolkitMySQLConnection* pConnection, char* string);

/**
 * @brief Escapes a constant string for safe SQL usage.
 *
 * @param pConnection MySQL connection instance.
 * @param string Input string.
 * @return Escaped string.
 */
std::string UTIL_MySQLEscape(IToolkitMySQLConnection* pConnection, const char* string);

/**
 * @brief Destroys and releases the MySQL connection instance.
 *
 * @param pConnection MySQL connection instance.
 */
void UTIL_DestroyMySQLConnection(IToolkitMySQLConnection* pConnection);

#endif //_INCLUDE_ITOOLKIT_UTILS_MYSQL_H