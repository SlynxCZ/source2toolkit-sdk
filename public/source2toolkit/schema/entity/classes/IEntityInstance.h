/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
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
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
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
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

#ifndef _INCLUDE_IENTITYINSTANCE_H
#define _INCLUDE_IENTITYINSTANCE_H

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
#include "entity2/entityinstance.h"
#include "entity2/entitysystem.h"

class CEntityInstance;

class IEntityInstance
{
public:
    virtual ~IEntityInstance() = default;
    virtual CEntityInstance* GetOriginal() const = 0;

    virtual CNetworkSerializerClassInfo* GetNetworkSerializerInfo() = 0;
    virtual void unk001() = 0;
    virtual void unk002() = 0;
    virtual void* GetScriptDesc() = 0;
    virtual void Connect() = 0;
    virtual void Disconnect() = 0;
    virtual void Precache( const CEntityPrecacheContext* pContext ) = 0;
    virtual void AddedToEntityDatabase() = 0;
    virtual void Spawn( const CEntityKeyValues* pKeyValues ) = 0;
    virtual void unk101() = 0;
    virtual void PostDataUpdate( int updateType ) = 0;
    virtual void OnDataUnchangedInPVS() = 0;
    virtual void Activate( int activateType ) = 0;
    virtual void UpdateOnRemove() = 0;
    virtual void OnSetDormant( int prevDormancyType, int newDormancyType ) = 0;
    virtual void* ScriptEntityIO() = 0;
    virtual int ScriptAcceptInput( const CUtlSymbolLarge& sInputName, IEntityInstance* pActivator, IEntityInstance* pCaller, const variant_t& value, int nOutputID, void* pUnk1, void* pUnk2 ) = 0;
    virtual void PreDataUpdate( int updateType ) = 0;
    virtual void DrawEntityDebugOverlays( uint64_t debug_bits ) = 0;
    virtual void DrawDebugTextOverlays( void* unk, uint64_t debug_bits, int flags ) = 0;
    virtual int Save( ISave& save ) = 0;
    virtual int Restore( IRestore& restore ) = 0;
    virtual void OnSave() = 0;
    virtual void OnRestore() = 0;
    virtual void unk201() = 0;
    virtual int ObjectCaps() = 0;
    virtual CEntityIndex RequiredEdictIndex() = 0;
    virtual void NetworkStateChanged( const NetworkStateChangedData& data ) = 0;
    virtual void unk301( const void* data ) = 0;
    virtual void unk302( const void* data ) = 0;
    virtual void NetworkUpdateState( bool state ) = 0;
    virtual void NetworkStateChangedLog( const char* pszFieldName, const char* pszInfo ) = 0;
    virtual bool FullEdictChanged() = 0;
    virtual void unk401() = 0;
    virtual void unk402() = 0;
    virtual ChangeAccessorFieldPathIndex_t AddChangeAccessorPath( const CFieldPath& path ) = 0;
    virtual void AssignChangeAccessorPathIds() = 0;
    virtual ChangeAccessorFieldPathIndexInfo_t* GetChangeAccessorPathInfo_1() = 0;
    virtual ChangeAccessorFieldPathIndexInfo_t* GetChangeAccessorPathInfo_2() = 0;
    virtual void unk501() = 0;
    virtual void unk502() = 0;
    virtual void ReloadPrivateScripts() = 0;
    virtual datamap_t* GetDataDescMap() = 0;
    virtual void unk601() = 0;
    virtual void unk602() = 0;
    virtual SchemaMetaInfoHandle_t<CSchemaClassInfo> Schema_DynamicBinding() = 0;

public:
    /// <summary>Create entity by classname.</summary>
    template<typename T>
    static T* New(const char* pszClassName)
    {
        return reinterpret_cast<T*>(_CreateRaw(pszClassName));
    }
    /// <summary>Get entity by index.</summary>
    template<typename T>
    static T* FromIndex(int iIndex)
    {
        return reinterpret_cast<T*>(GetEntitySystem()->GetEntityInstance(CEntityIndex(iIndex)));
    }
    /// <summary>Get entity by entity index.</summary>
    template<typename T>
    static T* FromIndex(CEntityIndex index)
    {
        return FromIndex<T>(index.Get());
    }
    /// <summary>Wrap a raw CEntityInstance pointer as its interface.</summary>
    static IEntityInstance* FromOriginal(CEntityInstance* p);

private:
    static CEntityInstance* _CreateRaw(const char* pszClassName);

};

#endif // _INCLUDE_IENTITYINSTANCE_H
