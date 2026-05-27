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

#ifndef _INCLUDE_IBASEENTITY_H
#define _INCLUDE_IBASEENTITY_H

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
#include <cstdint>
#include <functional>

#include "../enums/BloodType.h"
#include "../enums/EntityPlatformTypes_t.h"
#include "../enums/TakeDamageFlags_t.h"

class CBaseFilter;
class CBodyComponent;
class CCollisionProperty;
class CEntityIOListenerHandle;
class CEntityInstance;
class CEntityKeyValues;
class CEntitySubclassVDataBase;
class CNetworkTransmitComponent;
class CNetworkVelocityVector;
class CPulseGraphInstance_ServerEntity;
class ResponseContext_t;
class thinkfunc_t;

class IBaseEntity
{
public:
    virtual ~IBaseEntity() = default;

    virtual CBodyComponent*& CBodyComponent() = 0;
    virtual void CBodyComponentUpdated() = 0;
    virtual CNetworkTransmitComponent& NetworkTransmitComponent() = 0;
    virtual void NetworkTransmitComponentUpdated() = 0;
    virtual CUtlVector<thinkfunc_t>& ThinkFunctions() = 0;
    virtual void ThinkFunctionsUpdated() = 0;
    virtual int32_t& CurrentThinkContext() = 0;
    virtual void CurrentThinkContextUpdated() = 0;
    virtual int32_t& LastThinkTick() = 0;
    virtual void LastThinkTickUpdated() = 0;
    virtual bool& DisabledContextThinks() = 0;
    virtual void DisabledContextThinksUpdated() = 0;
    virtual CTypedBitVec<64>& IsSteadyState() = 0;
    virtual void IsSteadyStateUpdated() = 0;
    virtual float& LastNetworkChange() = 0;
    virtual void LastNetworkChangeUpdated() = 0;
    virtual BASEPTR& Think() = 0;
    virtual void ThinkUpdated() = 0;
    virtual CUtlVector<ResponseContext_t>& ResponseContexts() = 0;
    virtual void ResponseContextsUpdated() = 0;
    virtual CUtlSymbolLarge& ResponseContext() = 0;
    virtual void ResponseContextUpdated() = 0;
    virtual ENTITYFUNCPTR& PfnTouch() = 0;
    virtual void PfnTouchUpdated() = 0;
    virtual USEPTR& PfnUse() = 0;
    virtual void PfnUseUpdated() = 0;
    virtual ENTITYFUNCPTR& PfnBlocked() = 0;
    virtual void PfnBlockedUpdated() = 0;
    virtual BASEPTR& PfnMoveDone() = 0;
    virtual void PfnMoveDoneUpdated() = 0;
    virtual int32_t& Health() = 0;
    virtual void HealthUpdated() = 0;
    virtual int32_t& MaxHealth() = 0;
    virtual void MaxHealthUpdated() = 0;
    virtual uint8_t& LifeState() = 0;
    virtual void LifeStateUpdated() = 0;
    virtual float& DamageAccumulator() = 0;
    virtual void DamageAccumulatorUpdated() = 0;
    virtual bool& TakesDamage() = 0;
    virtual void TakesDamageUpdated() = 0;
    virtual TakeDamageFlags_t& TakeDamageFlags() = 0;
    virtual void TakeDamageFlagsUpdated() = 0;
    virtual EntityPlatformTypes_t& PlatformType() = 0;
    virtual void PlatformTypeUpdated() = 0;
    virtual MoveCollide_t& MoveCollide() = 0;
    virtual void MoveCollideUpdated() = 0;
    virtual MoveType_t& MoveType() = 0;
    virtual void MoveTypeUpdated() = 0;
    virtual MoveType_t& PreviouslySetMoveType() = 0;
    virtual void PreviouslySetMoveTypeUpdated() = 0;
    virtual MoveType_t& ActualMoveType() = 0;
    virtual void ActualMoveTypeUpdated() = 0;
    virtual uint8_t& WaterTouch() = 0;
    virtual void WaterTouchUpdated() = 0;
    virtual uint8_t& SlimeTouch() = 0;
    virtual void SlimeTouchUpdated() = 0;
    virtual bool& RestoreInHierarchy() = 0;
    virtual void RestoreInHierarchyUpdated() = 0;
    virtual CUtlSymbolLarge& Target() = 0;
    virtual void TargetUpdated() = 0;
    virtual CHandle<CBaseFilter>& DamageFilter() = 0;
    virtual void DamageFilterUpdated() = 0;
    virtual CUtlSymbolLarge& DamageFilterName() = 0;
    virtual void DamageFilterNameUpdated() = 0;
    virtual float& MoveDoneTime() = 0;
    virtual void MoveDoneTimeUpdated() = 0;
    virtual CUtlStringToken* SubclassID() = 0;
    virtual float& AnimTime() = 0;
    virtual void AnimTimeUpdated() = 0;
    virtual float& SimulationTime() = 0;
    virtual void SimulationTimeUpdated() = 0;
    virtual float& CreateTime() = 0;
    virtual void CreateTimeUpdated() = 0;
    virtual bool& ClientSideRagdoll() = 0;
    virtual void ClientSideRagdollUpdated() = 0;
    virtual uint8_t& InterpolationFrame() = 0;
    virtual void InterpolationFrameUpdated() = 0;
    virtual Vector& PrevVPhysicsUpdatePos() = 0;
    virtual void PrevVPhysicsUpdatePosUpdated() = 0;
    virtual uint8_t& TeamNum() = 0;
    virtual void TeamNumUpdated() = 0;
    virtual CUtlSymbolLarge& Globalname() = 0;
    virtual void GlobalnameUpdated() = 0;
    virtual int32_t& SentToClients() = 0;
    virtual void SentToClientsUpdated() = 0;
    virtual float& Speed() = 0;
    virtual void SpeedUpdated() = 0;
    virtual CUtlString& UniqueHammerID() = 0;
    virtual void UniqueHammerIDUpdated() = 0;
    virtual uint32_t& Spawnflags() = 0;
    virtual void SpawnflagsUpdated() = 0;
    virtual int32_t& NextThinkTick() = 0;
    virtual void NextThinkTickUpdated() = 0;
    virtual int32_t& SimulationTick() = 0;
    virtual void SimulationTickUpdated() = 0;
    virtual CEntityIOOutput& OnKilled() = 0;
    virtual void OnKilledUpdated() = 0;
    virtual uint32_t& Flags() = 0;
    virtual void FlagsUpdated() = 0;
    virtual Vector& AbsVelocity() = 0;
    virtual void AbsVelocityUpdated() = 0;
    virtual CNetworkVelocityVector& Velocity() = 0;
    virtual void VelocityUpdated() = 0;
    virtual Vector& BaseVelocity() = 0;
    virtual void BaseVelocityUpdated() = 0;
    virtual int32_t& PushEnumCount() = 0;
    virtual void PushEnumCountUpdated() = 0;
    virtual CCollisionProperty*& Collision() = 0;
    virtual void CollisionUpdated() = 0;
    virtual CHandle<CBaseEntity>& EffectEntity() = 0;
    virtual void EffectEntityUpdated() = 0;
    virtual CHandle<CBaseEntity>& OwnerEntity() = 0;
    virtual void OwnerEntityUpdated() = 0;
    virtual uint32_t& Effects() = 0;
    virtual void EffectsUpdated() = 0;
    virtual CHandle<CBaseEntity>& GroundEntity() = 0;
    virtual void GroundEntityUpdated() = 0;
    virtual int32_t& GroundBodyIndex() = 0;
    virtual void GroundBodyIndexUpdated() = 0;
    virtual float& Friction() = 0;
    virtual void FrictionUpdated() = 0;
    virtual float& Elasticity() = 0;
    virtual void ElasticityUpdated() = 0;
    virtual float& GravityScale() = 0;
    virtual void GravityScaleUpdated() = 0;
    virtual float& TimeScale() = 0;
    virtual void TimeScaleUpdated() = 0;
    virtual float& WaterLevel() = 0;
    virtual void WaterLevelUpdated() = 0;
    virtual bool& GravityDisabled() = 0;
    virtual void GravityDisabledUpdated() = 0;
    virtual bool& AnimatedEveryTick() = 0;
    virtual void AnimatedEveryTickUpdated() = 0;
    virtual float& ActualGravityScale() = 0;
    virtual void ActualGravityScaleUpdated() = 0;
    virtual bool& GravityActuallyDisabled() = 0;
    virtual void GravityActuallyDisabledUpdated() = 0;
    virtual bool& DisableLowViolence() = 0;
    virtual void DisableLowViolenceUpdated() = 0;
    virtual uint8_t& WaterType() = 0;
    virtual void WaterTypeUpdated() = 0;
    virtual int32_t& EFlags() = 0;
    virtual void EFlagsUpdated() = 0;
    virtual CEntityIOOutput& OnUser1() = 0;
    virtual void OnUser1Updated() = 0;
    virtual CEntityIOOutput& OnUser2() = 0;
    virtual void OnUser2Updated() = 0;
    virtual CEntityIOOutput& OnUser3() = 0;
    virtual void OnUser3Updated() = 0;
    virtual CEntityIOOutput& OnUser4() = 0;
    virtual void OnUser4Updated() = 0;
    virtual int32_t& InitialTeamNum() = 0;
    virtual void InitialTeamNumUpdated() = 0;
    virtual float& NavIgnoreUntilTime() = 0;
    virtual void NavIgnoreUntilTimeUpdated() = 0;
    virtual QAngle& AngVelocity() = 0;
    virtual void AngVelocityUpdated() = 0;
    virtual bool& NetworkQuantizeOriginAndAngles() = 0;
    virtual void NetworkQuantizeOriginAndAnglesUpdated() = 0;
    virtual bool& LagCompensate() = 0;
    virtual void LagCompensateUpdated() = 0;
    virtual CHandle<CBaseEntity>& Blocker() = 0;
    virtual void BlockerUpdated() = 0;
    virtual float& LocalTime() = 0;
    virtual void LocalTimeUpdated() = 0;
    virtual float& VPhysicsUpdateLocalTime() = 0;
    virtual void VPhysicsUpdateLocalTimeUpdated() = 0;
    virtual BloodType& BloodType() = 0;
    virtual void BloodTypeUpdated() = 0;
    virtual CPulseGraphInstance_ServerEntity*& PulseGraphInstance() = 0;
    virtual void PulseGraphInstanceUpdated() = 0;

    virtual void AcceptInput(const char* pszInput, CEntityInstance* pActivator = nullptr, CEntityInstance* pCaller = nullptr, const char* pszValue = "") = 0;
    virtual void AddEntityIOEvent(const char* pszInput, CEntityInstance* pActivator = nullptr, CEntityInstance* pCaller = nullptr, const char* pszValue = "", float flDelay = 0.0f) = 0;
    virtual CEntityIOListenerHandle* AddSingleEntityIOListener(const char* pszOutput, std::function<Action(const char*,CEntityInstance*, CEntityInstance*, float, Mode)> callback, Mode mode) = 0;
    virtual Vector GetAbsOrigin() = 0;
    virtual QAngle GetAngRotation() = 0;
    virtual QAngle GetAbsRotation() = 0;
    virtual Vector GetAbsVelocity() = 0;
    virtual void SetAbsOrigin(Vector vecOrigin) = 0;
    virtual void SetAbsRotation(QAngle angAbsRotation) = 0;
    virtual void SetAngRotation(QAngle angRotation) = 0;
    virtual void SetAbsVelocity(Vector vecVelocity) = 0;
    virtual void SetBaseVelocity(Vector vecVelocity) = 0;
    virtual CEntitySubclassVDataBase* GetVData() = 0;
    virtual void DispatchSpawn(CEntityKeyValues* pEntityKeyValues = nullptr) = 0;
    virtual void Teleport(const Vector* pPosition, const QAngle* pAngles, const Vector* pVelocity) = 0;
    virtual void SetMoveType(MoveType_t nMoveType) = 0;
    virtual uint8 GetCollisionGroup() = 0;
    virtual void SetCollisionGroup(uint8 nCollisionGroup) = 0;
    virtual void CollisionRulesChanged() = 0;
    virtual int GetIndex() = 0;
    virtual CHandle<CBaseEntity> GetHandle() = 0;
    virtual const char* GetName() const = 0;
};

#endif // _INCLUDE_IBASEENTITY_H
