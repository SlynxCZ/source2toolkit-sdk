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

* @file IToolkitHTTP.h
* @brief Interface for HTTP requests.
*
* Requests go out through Steam's own HTTP client, which the game server already
* has, so there is no curl to link and nothing to pump. Steam only hands that
* client over once the API has activated, which happens after level startup --
* requests made before then are queued and sent when it does, so a plugin does
* not have to care whether it is early.
*
* Responses come back on the main thread.
  */

#ifndef _INCLUDE_ITOOLKIT_HTTP_H
#define _INCLUDE_ITOOLKIT_HTTP_H

#pragma once
#include "IToolkitJSON.h"
#include "IToolkitPlugin.h"

#include <string>
#include <vector>

/* =========================
Request types
========================= */

/**

* @brief HTTP method of a request.
  */
enum class EToolkitHTTPMethod : int
{
    Get = 0,
    Post,
    Put,
    Patch,
    Delete,
    Head,
};

/**

* @brief One request or response header.
  */
struct ToolkitHTTPHeader
{
    ToolkitHTTPHeader() = default;
    ToolkitHTTPHeader(std::string name, std::string value)
        : m_sName(std::move(name)), m_sValue(std::move(value))
    {
    }

    std::string m_sName;
    std::string m_sValue;
};

/**

* @brief What a completed request came back with.
*
* @note m_bSuccess is about the transport, not the status code -- a 404 that
*       arrived is a success with m_nStatusCode == 404. A request that never
*       completed has m_bSuccess false and m_nStatusCode 0.
  */
struct ToolkitHTTPResponse
{
    bool m_bSuccess = false;
    int m_nStatusCode = 0;
    std::string m_sBody;

    /// The body parsed as JSON, when it was JSON. Owned by the toolkit and
    /// valid only for the duration of the callback -- copy anything you keep.
    /// Null when the body was empty or did not parse.
    const IToolkitJSONValue* m_pJson = nullptr;
};

/**

* @brief Callback for a completed request.
  */
using ToolkitHTTPCallback = std::function<void(const ToolkitHTTPResponse& response)>;

/* =========================
Core Toolkit HTTP
========================= */

/**

* @brief Issues HTTP requests through Steam's HTTP client.
*
* @code
* HTTP_GET("https://example.com/api", [](const ToolkitHTTPResponse& r)
* {
*     if (!r.m_bSuccess || r.m_nStatusCode != 200)
*         return;
*
*     // r.m_sBody -- parse with whatever your plugin already uses.
* });
* @endcode
  */
#define TOOLKIT_HTTP_INTERFACE "IToolkitHTTP002"

class IToolkitHTTP
{
public:
    virtual ~IToolkitHTTP() = default;

    /**

    * @brief Whether Steam's HTTP client is available yet.
    *
    * Requests made while this is false are queued, not dropped, so checking is
    * only worth it to avoid building a body you cannot send.
      */
    virtual bool IsAvailable() const = 0;

    /**

    * @brief Number of requests waiting for Steam's HTTP client.
      */
    virtual int PendingCount() const = 0;

    /**

    * @brief Issues a request.
    *
    * @param owner Plugin the request belongs to
    * @param method HTTP method
    * @param pszUrl Absolute URL
    * @param pszBody Request body, or nullptr for methods that take none
    * @param callback Called once the request completes; may be null
    * @param pHeaders Extra request headers, or nullptr
    *
    * @note Cancelled, callback and all, if the owning plugin unloads first --
    *       the callback holds code inside that plugin's library.
      */
    virtual void Request(PluginId owner,
                         EToolkitHTTPMethod method,
                         const char* pszUrl,
                         const char* pszBody,
                         ToolkitHTTPCallback callback,
                         const std::vector<ToolkitHTTPHeader>* pHeaders = nullptr) = 0;

    /* =========================
    Shorthands
    ========================= */

    virtual void Get(PluginId owner, const char* pszUrl, ToolkitHTTPCallback callback,
                     const std::vector<ToolkitHTTPHeader>* pHeaders = nullptr) = 0;

    virtual void Post(PluginId owner, const char* pszUrl, const char* pszBody, ToolkitHTTPCallback callback,
                      const std::vector<ToolkitHTTPHeader>* pHeaders = nullptr) = 0;

    virtual void Put(PluginId owner, const char* pszUrl, const char* pszBody, ToolkitHTTPCallback callback,
                     const std::vector<ToolkitHTTPHeader>* pHeaders = nullptr) = 0;

    virtual void Patch(PluginId owner, const char* pszUrl, const char* pszBody, ToolkitHTTPCallback callback,
                       const std::vector<ToolkitHTTPHeader>* pHeaders = nullptr) = 0;

    virtual void Delete(PluginId owner, const char* pszUrl, const char* pszBody, ToolkitHTTPCallback callback,
                        const std::vector<ToolkitHTTPHeader>* pHeaders = nullptr) = 0;
};

#define HTTP_REQUEST(method, pszUrl, pszBody, cb, ...) \
    g_pToolkitHTTP->Request(g_PluginID, method, pszUrl, pszBody, cb, ##__VA_ARGS__)

#define HTTP_GET(pszUrl, cb, ...) \
    g_pToolkitHTTP->Get(g_PluginID, pszUrl, cb, ##__VA_ARGS__)
#define HTTP_POST(pszUrl, pszBody, cb, ...) \
    g_pToolkitHTTP->Post(g_PluginID, pszUrl, pszBody, cb, ##__VA_ARGS__)
#define HTTP_PUT(pszUrl, pszBody, cb, ...) \
    g_pToolkitHTTP->Put(g_PluginID, pszUrl, pszBody, cb, ##__VA_ARGS__)
#define HTTP_PATCH(pszUrl, pszBody, cb, ...) \
    g_pToolkitHTTP->Patch(g_PluginID, pszUrl, pszBody, cb, ##__VA_ARGS__)
#define HTTP_DELETE(pszUrl, pszBody, cb, ...) \
    g_pToolkitHTTP->Delete(g_PluginID, pszUrl, pszBody, cb, ##__VA_ARGS__)

#endif //_INCLUDE_ITOOLKIT_HTTP_H
