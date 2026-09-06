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
 * @file IToolkitMySQL.h
 * @brief Interfaces and utilities for MySQL database access.
 *
 * This module provides functionality for:
 * * MySQL connections
 * * Query execution
 * * Transactions
 * * Result set handling
 * * Data escaping
 *
 * @note Commonly used for persistent storage and asynchronous database operations.
 */

#ifndef _INCLUDE_ITOOLKIT_MYSQL_H
#define _INCLUDE_ITOOLKIT_MYSQL_H

#pragma once
#include "IToolkitPlugin.h"

#include <functional>
#include <string>
#include <vector>

/* =========================
Forward declarations
========================= */

class IToolkitMySQLQuery;

/* =========================
Callback typedefs
========================= */

typedef std::function<void(bool)> ToolkitMySQLConnectCallbackFunc;
typedef std::function<void(IToolkitMySQLQuery*)> ToolkitMySQLQueryCallbackFunc;
typedef std::function<void(std::vector<IToolkitMySQLQuery*>)> ToolkitMySQLTransactionSuccessCallbackFunc;
typedef std::function<void(std::string, int)> ToolkitMySQLTransactionFailureCallbackFunc;

/* =========================
MySQL field types
========================= */

typedef enum EToolkitMySQLType
{
    TOOLKIT_MYSQL_TYPE_DECIMAL,
    TOOLKIT_MYSQL_TYPE_TINY,
    TOOLKIT_MYSQL_TYPE_SHORT,
    TOOLKIT_MYSQL_TYPE_LONG,
    TOOLKIT_MYSQL_TYPE_FLOAT,
    TOOLKIT_MYSQL_TYPE_DOUBLE,
    TOOLKIT_MYSQL_TYPE_NULL,
    TOOLKIT_MYSQL_TYPE_TIMESTAMP,
    TOOLKIT_MYSQL_TYPE_LONGLONG,
    TOOLKIT_MYSQL_TYPE_INT24,
    TOOLKIT_MYSQL_TYPE_DATE,
    TOOLKIT_MYSQL_TYPE_TIME,
    TOOLKIT_MYSQL_TYPE_DATETIME,
    TOOLKIT_MYSQL_TYPE_YEAR,
    TOOLKIT_MYSQL_TYPE_NEWDATE,
    TOOLKIT_MYSQL_TYPE_VARCHAR,
    TOOLKIT_MYSQL_TYPE_BIT,
    TOOLKIT_MYSQL_TYPE_TIMESTAMP2,
    TOOLKIT_MYSQL_TYPE_DATETIME2,
    TOOLKIT_MYSQL_TYPE_TIME2,
    TOOLKIT_MYSQL_TYPE_UNKNOWN,

    TOOLKIT_MYSQL_TYPE_JSON = 245,
    TOOLKIT_MYSQL_TYPE_NEWDECIMAL = 246,
    TOOLKIT_MYSQL_TYPE_ENUM = 247,
    TOOLKIT_MYSQL_TYPE_SET = 248,
    TOOLKIT_MYSQL_TYPE_TINY_BLOB = 249,
    TOOLKIT_MYSQL_TYPE_MEDIUM_BLOB = 250,
    TOOLKIT_MYSQL_TYPE_LONG_BLOB = 251,
    TOOLKIT_MYSQL_TYPE_BLOB = 252,
    TOOLKIT_MYSQL_TYPE_VAR_STRING = 253,
    TOOLKIT_MYSQL_TYPE_STRING = 254,
    TOOLKIT_MYSQL_TYPE_GEOMETRY = 255
} EToolkitMySQLType;

/* =========================
Transaction
========================= */

struct ToolkitMySQLTransaction
{
    std::vector<std::string> queries;
};

/* =========================
Connection info
========================= */

struct ToolkitMySQLConnectionInfo
{
    const char* host;
    const char* user;
    const char* pass;
    const char* database;

    int port = 3306;
    int timeout = 60;
};

/* =========================
Result row
========================= */

class IToolkitMySQLRow
{
public:
    virtual ~IToolkitMySQLRow() = default;
};

/* =========================
Result set
========================= */

class IToolkitMySQLResult
{
public:
    virtual ~IToolkitMySQLResult() = default;

    /**
     * @brief Returns the total number of rows in the result set.
     */
    virtual int GetRowCount() = 0;

    /**
     * @brief Returns the number of columns in the result set.
     */
    virtual int GetFieldCount() = 0;

    /**
     * @brief Converts a field name into a column index.
     *
     * @param name Field name to search for.
     * @param columnId Output column index.
     * @return True if the field exists, false otherwise.
     */
    virtual bool FieldNameToNum(const char* name, unsigned int* columnId) = 0;

    /**
     * @brief Returns the field name for a column index.
     *
     * @param colId Column index.
     * @return Field name string.
     */
    virtual const char* FieldNumToName(unsigned int colId) = 0;

    /**
     * @brief Checks whether additional rows are available.
     *
     * @return True if more rows can be fetched.
     */
    virtual bool MoreRows() = 0;

    /**
     * @brief Fetches the next row from the result set.
     *
     * @return Pointer to the fetched row.
     */
    virtual IToolkitMySQLRow* FetchRow() = 0;

    /**
     * @brief Returns the currently active row.
     *
     * @return Pointer to the current row.
     */
    virtual IToolkitMySQLRow* CurrentRow() = 0;

    /**
     * @brief Rewinds the internal row cursor to the beginning.
     *
     * @return True on success.
     */
    virtual bool Rewind() = 0;

    /**
     * @brief Returns the MySQL field type of a column.
     *
     * @param field Column index.
     * @return Field type identifier.
     */
    virtual int GetFieldType(unsigned int field) = 0;

    /**
     * @brief Retrieves a string value from a column.
     *
     * @param columnId Column index.
     * @param length Optional output string length.
     * @return Pointer to string data.
     */
    virtual const char* GetString(unsigned int columnId, size_t* length = nullptr) = 0;

    /**
     * @brief Returns the raw data size of a column value.
     *
     * @param columnId Column index.
     * @return Size in bytes.
     */
    virtual size_t GetDataSize(unsigned int columnId) = 0;

    /**
     * @brief Retrieves a floating-point value from a column.
     *
     * @param columnId Column index.
     * @return Float value.
     */
    virtual float GetFloat(unsigned int columnId) = 0;

    /**
     * @brief Retrieves an integer value from a column.
     *
     * @param columnId Column index.
     * @return Integer value.
     */
    virtual int GetInt(unsigned int columnId) = 0;

    /**
     * @brief Retrieves a 64-bit integer value from a column.
     *
     * @param columnId Column index.
     * @return 64-bit integer value.
     */
    virtual int64_t GetInt64(unsigned int columnId) = 0;

    /**
     * @brief Checks whether a column contains a NULL value.
     *
     * @param columnId Column index.
     * @return True if the value is NULL.
     */
    virtual bool IsNull(unsigned int columnId) = 0;
};

/* =========================
Query
========================= */

class IToolkitMySQLQuery
{
public:
    virtual ~IToolkitMySQLQuery() = default;

    /**
     * @brief Returns the current result set.
     *
     * @return Pointer to the result set.
     */
    virtual IToolkitMySQLResult* GetResultSet() = 0;

    /**
     * @brief Advances to the next available result set.
     *
     * @return True if another result set exists.
     */
    virtual bool FetchMoreResults() = 0;

    /**
     * @brief Returns the last inserted row ID.
     *
     * @return Insert ID value.
     */
    virtual unsigned int GetInsertId() = 0;

    /**
     * @brief Returns the number of affected rows.
     *
     * @return Affected row count.
     */
    virtual unsigned int GetAffectedRows() = 0;
};

/* =========================
Connection
========================= */

class IToolkitMySQLConnection
{
public:
    virtual ~IToolkitMySQLConnection() = default;

    /**
     * @brief Establishes a connection to the MySQL server.
     *
     * @param callback Callback invoked after connection attempt.
     */
    virtual void Connect(ToolkitMySQLConnectCallbackFunc callback) = 0;

    /**
     * @brief Executes a raw SQL query.
     *
     * @param query SQL query string.
     * @param callback Callback invoked with query result.
     */
    virtual void Query(char* query, ToolkitMySQLQueryCallbackFunc callback) = 0;

    /**
     * @brief Executes a formatted SQL query.
     *
     * @param query SQL format string.
     * @param callback Callback invoked with query result.
     */
    virtual void Query(const char* query, ToolkitMySQLQueryCallbackFunc callback, ...) = 0;

    /**
     * @brief Executes multiple queries as a transaction.
     *
     * @param txn Transaction query batch.
     * @param success Callback invoked on success.
     * @param failure Callback invoked on failure.
     */
    virtual void ExecuteTransaction(ToolkitMySQLTransaction txn, ToolkitMySQLTransactionSuccessCallbackFunc success,
                                    ToolkitMySQLTransactionFailureCallbackFunc failure) = 0;

    /**
     * @brief Destroys and releases the connection instance.
     */
    virtual void Destroy() = 0;

    /**
     * @brief Escapes a mutable string for safe SQL usage.
     *
     * @param string Input string.
     * @return Escaped string.
     */
    virtual std::string Escape(char* string) = 0;

    /**
     * @brief Escapes a constant string for safe SQL usage.
     *
     * @param string Input string.
     * @return Escaped string.
     */
    virtual std::string Escape(const char* string) = 0;
};

/* =========================
Serverless queries
========================= */

/**
 * @brief What one serverless query came back with.
 *
 * @note m_bSuccess is about the query, not about rows -- a SELECT that matched
 *       nothing is a success with an empty result set. A query that failed has
 *       m_bSuccess false, m_sError filled in and m_pQuery null.
 */
struct ToolkitMySQLServerlessResult
{
    bool m_bSuccess = false;

    /// MySQL's own error number, or 0 when the query never reached the server.
    unsigned int m_nErrorCode = 0;
    std::string m_sError;

    /// Rows, insert id and affected rows, read off the connection before it
    /// was closed again. Owned by the toolkit and valid only for the duration
    /// of the callback -- copy anything you keep. Null when the query failed.
    IToolkitMySQLQuery* m_pQuery = nullptr;
};

/**
 * @brief Callback for a completed serverless query. Runs on the main thread.
 */
typedef std::function<void(const ToolkitMySQLServerlessResult&)> ToolkitMySQLServerlessCallbackFunc;

/**
 * @brief A set of connection details that queries are run against one at a time.
 *
 * Every query opens its own connection, runs, reads its rows out and closes
 * again -- there is nothing to keep alive, nothing to reconnect, and nothing
 * that can go stale over a map change. None of it happens on the main thread:
 * queries go through the toolkit's shared MySQL worker, one thread for all of
 * them however many plugins are using it, and land back in a callback on the
 * main thread.
 *
 * Meant for the occasional query -- loading a player on connect, writing their
 * stats on disconnect. A connection costs a handshake and a login every single
 * time, so for anything that runs per tick or per shot, keep an
 * IToolkitMySQLConnection open instead.
 *
 * @code
 * // once, when your plugin loads
 * m_pDb = api->MySQL()->CreateServerless(g_PLID, { "127.0.0.1", "user", "pass", "db" });
 *
 * // wherever you need it
 * m_pDb->Query("SELECT name, kills FROM players WHERE steamid = ?", { steamid },
 *     [](const ToolkitMySQLServerlessResult& r)
 * {
 *     if (!r.m_bSuccess)
 *         return; // r.m_sError says what went wrong
 *
 *     IToolkitMySQLResult* pSet = r.m_pQuery->GetResultSet();
 *     while (pSet && pSet->MoreRows() && pSet->FetchRow())
 *     {
 *         // pSet->GetString(0), pSet->GetInt(1) -- copy anything you keep.
 *     }
 * });
 * @endcode
 */
class IToolkitMySQLServerless
{
public:
    virtual ~IToolkitMySQLServerless() = default;

    /**
     * @brief Runs one query on a connection of its own.
     *
     * @param query SQL to run.
     * @param callback Callback invoked with the result, on the main thread.
     */
    virtual void Query(const char* query, ToolkitMySQLServerlessCallbackFunc callback) = 0;

    /**
     * @brief Runs one parameterised query on a connection of its own.
     *
     * Placeholders are filled in on the worker against the live connection:
     * `?` becomes the escaped value in quotes, `??` becomes a quoted
     * identifier -- a table or column name, which cannot be a `?`. A `?`
     * inside a string literal is left alone, and a placeholder count that does
     * not match @p params fails the query instead of running it.
     *
     * @param query SQL to run, with `?` / `??` placeholders.
     * @param params Values for the placeholders, in order.
     * @param callback Callback invoked with the result, on the main thread.
     */
    virtual void Query(const char* query, std::vector<std::string> params,
                       ToolkitMySQLServerlessCallbackFunc callback) = 0;

    /**
     * @brief Drops these details and cancels what they still have queued. A
     *        query already on the wire is left to finish and its result thrown
     *        away -- its callback does not run.
     */
    virtual void Destroy() = 0;
};

/* =========================
MySQL client
========================= */

#define TOOLKIT_MYSQL_INTERFACE "IToolkitMySQL003"

class IToolkitMySQL
{
public:
    virtual ~IToolkitMySQL() = default;

    /**
     * @brief Creates a new MySQL connection instance.
     *
     * @param owner Plugin the connection belongs to.
     * @param info Connection configuration data.
     * @return Newly created MySQL connection.
     *
     * @note Destroyed for you if the owning plugin unloads without calling
     *       Destroy(): the worker thread runs code, and the query callbacks
     *       are std::functions holding code, inside that plugin's library.
     */
    virtual IToolkitMySQLConnection* CreateConnection(PluginId owner, ToolkitMySQLConnectionInfo info) = 0;

    /**
     * @brief Creates a handle that runs each of its queries on a connection of
     *        its own, opened and closed around that one query.
     *
     * @param owner Plugin the handle belongs to.
     * @param info Connection configuration data. Copied, strings included --
     *             it does not have to outlive this call.
     * @return Newly created serverless handle.
     *
     * @note Destroyed for you if the owning plugin unloads without calling
     *       Destroy(), together with every query of its still in the air: a
     *       pending callback is a std::function holding code inside that
     *       plugin's library.
     */
    virtual IToolkitMySQLServerless* CreateServerless(PluginId owner, ToolkitMySQLConnectionInfo info) = 0;
};

#define MYSQL_CREATE_CONNECTION(info)    g_pToolkitMySQL->CreateConnection(g_PluginID, info)

#endif //_INCLUDE_ITOOLKIT_MYSQL_H
