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
#include "IToolkitTypes.h"

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
    virtual void ExecuteTransaction(ToolkitMySQLTransaction txn, ToolkitMySQLTransactionSuccessCallbackFunc success, ToolkitMySQLTransactionFailureCallbackFunc failure) = 0;

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
MySQL client
========================= */

class IToolkitMySQL
{
public:
    virtual ~IToolkitMySQL() = default;

    /**
     * @brief Creates a new MySQL connection instance.
     *
     * @param info Connection configuration data.
     * @return Newly created MySQL connection.
     */
    virtual IToolkitMySQLConnection* CreateConnection(ToolkitMySQLConnectionInfo info) = 0;
};

#endif //_INCLUDE_ITOOLKIT_MYSQL_H