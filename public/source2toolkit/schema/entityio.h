/**
 * =============================================================================
 * CS2Fixes
 * Copyright (C) 2023-2026 Source2ZE
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

// Bandaid needed for #include "string_t.h" to compile...
#ifndef NULL
	#define NULL 0
#endif
#include "entity.h"

#include "entityhandle.h"
#include "entityinstance.h"
#include "entitysystem.h"
#include "string_t.h"

struct EntityIOConnectionDesc_t
{
	string_t m_targetDesc;
	string_t m_targetInput;
	string_t m_valueOverride;
	CEntityHandle m_hTarget;
	EntityIOTargetType_t m_nTargetType;
	int32 m_nTimesToFire;
	float m_flDelay;
};

struct EntityIOConnection_t : EntityIOConnectionDesc_t
{
	bool m_bMarkedForRemoval;
	EntityIOConnection_t* m_pNext;
};

struct EntityIOOutputDesc_t
{
	const char* m_pName;
	uint32 m_nFlags;
	uint32 m_nOutputOffset;
};

class CEntityIOOutput
{
public:
	void* vtable;
	EntityIOConnection_t* m_pConnections;
	EntityIOOutputDesc_t* m_pDesc;
};

class InputData_t
{
public:
	CBaseEntity* pActivator;
	CBaseEntity* pCaller;
	variant_t value;
	int nOutputID;
};

class IEntityIOListener
{
public:
	virtual Action OnEntityOutput(const char* pchOutputName, CEntityInstance* pActivator, CEntityInstance* pCaller, float flDelay, Mode nMode) {};
};

class CSingleEntityIOListener : public IEntityIOListener
{
public:
	CEntityInstance* m_pTarget;
	std::function<Action(const char*, CEntityInstance*, CEntityInstance*, float, Mode)> m_Callback;

	CSingleEntityIOListener(CEntityInstance* target, std::function<Action(const char*, CEntityInstance*, CEntityInstance*, float, Mode)> cb) :
		m_pTarget(target),
		m_Callback(std::move(cb))
	{
	}

	Action OnEntityOutput(const char* outputName, CEntityInstance* pActivator, CEntityInstance* pCaller, float delay, Mode mode) override
	{
		if (pCaller != m_pTarget)
			return Action::Ignore;

		return m_Callback(outputName, pActivator, pCaller, delay, mode);
	}
};

class CEntityIOListenerHandle
{
public:
	CSingleEntityIOListener* m_pListener = nullptr;
	std::string m_szClassname;
	std::string m_szOutput;
	Mode m_nMode = Mode::Pre;

	void Unhook()
	{
		if (!m_pListener)
			return;

		UTIL_RemoveEntityIOListener(m_pListener, m_szClassname.c_str(), m_szOutput.c_str(), m_nMode);

		delete m_pListener;
		m_pListener = nullptr;
	}

	~CEntityIOListenerHandle()
	{
		Unhook();
	}
};

struct EntityIOCallbackPair
{
	std::vector<IEntityIOListener*> m_vecPre;
	std::vector<IEntityIOListener*> m_vecPost;
};

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

struct OutputKeyHash
{
	size_t operator()(const OutputKey& k) const
	{
		return std::hash<std::string>()(k.m_szClassName) ^
			   (std::hash<std::string>()(k.m_szOutputName) << 1);
	}
};