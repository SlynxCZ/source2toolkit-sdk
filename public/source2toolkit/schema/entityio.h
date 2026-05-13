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

* @file entityio.h
* @brief Entity I/O system (inputs/outputs) for Source2Toolkit.
*
* Provides:
* * Access to entity outputs (OnTrigger, OnUse, etc.)
* * Hooking system for listening to outputs
* * Filtering by entity + classname + output name
*
* @note Equivalent to Hammer I/O system (FireOutput / AcceptInput).
*/

#ifndef ENTITYIO_H
#define ENTITYIO_H

#pragma once

#ifndef NULL
#define NULL 0
#endif

#include "entity.h"
#include "entityhandle.h"
#include "entityinstance.h"
#include "entitysystem.h"
#include "string_t.h"

/* =========================
Connection descriptors
========================= */

/**

* @brief Describes a single output connection.
*
* Example (Hammer):
* OnTrigger -> target_entity -> input_name
  */
struct EntityIOConnectionDesc_t
{
    string_t m_targetDesc; ///< Target entity name
    string_t m_targetInput; ///< Input name to call
    string_t m_valueOverride; ///< Override value
    CEntityHandle m_hTarget; ///< Target handle
    EntityIOTargetType_t m_nTargetType;
    int32 m_nTimesToFire; ///< How many times it can fire
    float m_flDelay; ///< Delay before firing
};

/**

* @brief Runtime connection node.
  */
struct EntityIOConnection_t : EntityIOConnectionDesc_t
{
    bool m_bMarkedForRemoval;
    EntityIOConnection_t* m_pNext;
};

/* =========================
Output system
========================= */

/**

* @brief Output metadata.
  */
struct EntityIOOutputDesc_t
{
    const char* m_pName; ///< Output name (e.g. "OnTrigger")
    uint32 m_nFlags;
    uint32 m_nOutputOffset;
};

/**

* @brief Represents an entity output.
  */
class CEntityIOOutput
{
public:
    void* vtable;

    /// Linked list of connections
    EntityIOConnection_t* m_pConnections;

    /// Output descriptor
    EntityIOOutputDesc_t* m_pDesc;
};

/* =========================
Input system
========================= */

/**

* @brief Data passed to inputs.
  */
class InputData_t
{
public:
    CBaseEntity* pActivator; ///< Entity that triggered the input
    CBaseEntity* pCaller; ///< Entity owning the output
    variant_t value; ///< Passed value
    int nOutputID;
};

/* =========================
Listener system
========================= */

/**

* @brief Interface for listening to entity outputs.
  */
class IEntityIOListener
{
public:
    virtual ~IEntityIOListener() = default;

    /**

    * @brief Called when an entity fires an output.
    *
    * @param pchOutputName Output name (e.g. "OnTrigger")
    * @param pActivator Activator entity
    * @param pCaller Caller entity
    * @param flDelay Delay before execution
    * @param nMode Pre/Post hook
    *
    * @return Action (Ignore / Override / Supersede)
      */
    virtual Action OnEntityOutput(const char* pchOutputName,
                                  CEntityInstance* pActivator,
                                  CEntityInstance* pCaller,
                                  float flDelay,
                                  Mode nMode)
    {
        return Action::Ignore;
    }
};

/**

* @brief Listener bound to a specific entity.
  */
class CSingleEntityIOListener : public IEntityIOListener
{
public:
    CEntityInstance* m_pTarget;

    /// Callback handler
    std::function<Action(const char*, CEntityInstance*, CEntityInstance*, float, Mode)> m_Callback;

    CSingleEntityIOListener(CEntityInstance* target,
                            std::function<Action(const char*, CEntityInstance*, CEntityInstance*, float, Mode)> cb)
        : m_pTarget(target), m_Callback(std::move(cb))
    {
    }

    Action OnEntityOutput(const char* outputName,
                          CEntityInstance* pActivator,
                          CEntityInstance* pCaller,
                          float delay,
                          Mode mode) override
    {
        if (pCaller != m_pTarget)
            return Action::Ignore;

        return m_Callback(outputName, pActivator, pCaller, delay, mode);
    }
};

/**

* @brief RAII handle for entity output listeners.
*
* Automatically unregisters listener on destruction.
  */
class CEntityIOListenerHandle
{
public:
    CSingleEntityIOListener* m_pListener = nullptr;
    std::string m_szClassname;
    std::string m_szOutput;
    Mode m_nMode = Mode::Pre;

    /**

    * @brief Removes listener.
      */
    void Unhook()
    {
        if (!m_pListener)
            return;

        UTIL_RemoveEntityIOListener(
            m_pListener,
            m_szClassname.c_str(),
            m_szOutput.c_str(),
            m_nMode
        );

        delete m_pListener;
        m_pListener = nullptr;
    }

    /**

    * @brief Destructor auto-unhooks listener.
      */
    ~CEntityIOListenerHandle()
    {
        Unhook();
    }
};

/* =========================
Internal storage
========================= */

/**

* @brief Stores listeners per output.
  */
struct EntityIOCallbackPair
{
    std::vector<IEntityIOListener*> m_vecPre;
    std::vector<IEntityIOListener*> m_vecPost;
};

/**

* @brief Key for output lookup.
  */
struct OutputKey
{
    std::string m_szClassName;
    std::string m_szOutputName;

    bool operator==(const OutputKey& other) const
    {
        return m_szClassName == other.m_szClassName &&
            m_szOutputName == other.m_szOutputName;
    }
};

/**

* @brief Hash function for OutputKey.
  */
struct OutputKeyHash
{
    size_t operator()(const OutputKey& k) const
    {
        return std::hash<std::string>()(k.m_szClassName) ^
            (std::hash<std::string>()(k.m_szOutputName) << 1);
    }
};

#endif // ENTITYIO_H
