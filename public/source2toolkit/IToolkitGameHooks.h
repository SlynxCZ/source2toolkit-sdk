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

/**
 * @file IToolkitGameHooks.h
 * @brief Hooks on the game functions plugins reach for most often, held by
 *        the core.
 *
 * One detour per function, placed by the core from its gamedata the first
 * time a plugin asks for it and taken out again once the last listener is
 * gone -- a function nobody listens to is not hooked at all. A plugin
 * registers a handler and never touches KHook, a signature or a prototype.
 * When Valve changes one -- an argument added, the order swapped between
 * platforms, as GroundAccelerate's is -- the core's gamedata and its one call
 * site change, and the plugins keep running. Anything not in this set is
 * still a KHOOK_MEMBER / KHOOK_VIRTUAL of the plugin's own.
 *
 * Every hook hands its handler a context: the hooked object, the arguments,
 * and `result` where the function returns something. What the handler
 * returns is the usual Action:
 *
 * * Ignore    -- nothing changed.
 * * Override  -- pre: the original still runs but the function returns
 *                `ctx.result`; post: the function returns `ctx.result`
 *                instead of what the original produced.
 * * Supersede -- pre only: the original does not run, the function returns
 *                `ctx.result`. Stops the remaining pre handlers.
 *
 * Arguments passed by pointer (the damage info, the move data, the weapon)
 * can be changed in place and the original sees the change; arguments passed
 * by value (a speed, a flag) cannot -- a handler that needs that keeps a raw
 * KHOOK_MEMBER of its own. Handlers run in registration order, pre before the
 * original and post after it; in post, `result` holds what the original
 * returned.
 *
 * HookX() returns a GameHookId for UnhookX(); a plugin may have several
 * handlers on one function. The handlers are the plugin's until it unhooks
 * them or unloads, whichever comes first; nothing to undo in Unload().
 */

#ifndef _INCLUDE_ITOOLKIT_GAMEHOOKS_H
#define _INCLUDE_ITOOLKIT_GAMEHOOKS_H

#pragma once

#include <cstdint>
#include <functional>

#include "IToolkitPlugin.h"
#include "IToolkitTypes.h"

// variant_t is a typedef of a template in hl2sdk, so it cannot be forward
// declared like the rest.
#include "variant.h"

class CBaseEntity;
class CBasePlayerController;
class CBasePlayerWeapon;
class CCSPlayer_ItemServices;
class CCSPlayer_MovementServices;
class CCSPlayer_WeaponServices;
class CCSPlayerController;
class CCSPlayerLegacyJump;
class CCSPlayerModernJump;
class CCSPlayerPawn;
class CCSPlayerPawnBase;
class CEconItemView;
class CEntityIdentity;
class CEntityInstance;
class CGameTrace;
class CMoveData;
class CPlayer_MovementServices;
class CTakeDamageInfo;
class CTakeDamageResult;
class CUserCmd;
class CUtlSymbolLarge;
class Vector;

/// What CCSPlayer_ItemServices::CanAcquire answers.
enum AcquireResult : std::uint32_t
{
    Allowed = 0,
    InvalidItem,
    AlreadyOwned,
    AlreadyPurchased,
    ReachedGrenadeTypeLimit,
    ReachedGrenadeTotalLimit,
    NotAllowedByTeam,
    NotAllowedByMap,
    NotAllowedByMode,
    NotAllowedForPurchase,
    NotAllowedByProhibition,
};

/// How an item is being acquired in CCSPlayer_ItemServices::CanAcquire.
enum AcquireMethod : std::uint32_t
{
    PickUp = 0,
    Buy,
    BuyWithCtrl,
};

/* =========================
Contexts
========================= */

/// CBaseEntity::TakeDamageOld(info, result) -> int64
struct TakeDamageContext
{
    CBaseEntity* entity;
    CTakeDamageInfo* info;
    CTakeDamageResult* damageResult;
    std::int64_t result;
};

/// CCSPlayer_ItemServices::CanAcquire(item, method, unk) -> AcquireResult
struct CanAcquireContext
{
    CCSPlayer_ItemServices* services;
    CEconItemView* item;
    AcquireMethod method;
    void* unk;
    AcquireResult result;
};

/// CCSPlayerPawnBase::CanMove() -> bool; false while frozen, defusing, ...
struct CanMoveContext
{
    CCSPlayerPawnBase* pawn;
    bool result;
};

/// CCSPlayer_WeaponServices::CanUse(weapon) -> bool
struct CanUseContext
{
    CCSPlayer_WeaponServices* services;
    CBasePlayerWeapon* weapon;
    bool result;
};

/// CCSPlayerPawn::PostThink()
struct PostThinkContext
{
    CCSPlayerPawnBase* pawn;
};

/// CCSPlayerController::ProcessUserCmd(cmds, count, paused, margin) -> void*.
/// The commands are CUserCmd (a protobuf-backed type), left untyped here.
struct ProcessUsercmdsContext
{
    CCSPlayerController* controller;
    void* cmds;
    int count;
    bool paused;
    float margin;
    void* result;
};

/// CBasePlayerController::OnSimulateUserCommands()
struct SimulateUserCommandsContext
{
    CBasePlayerController* controller;
};

/// CPlayer_MovementServices::RunCommand(cmd), on CCSPlayer_MovementServices'
/// vtable; the command is a CUserCmd.
struct RunCommandContext
{
    CCSPlayer_MovementServices* services;
    void* cmd;
};

/// CEntityIdentity::AcceptInput(name, activator, caller, value, ...) -> bool
struct AcceptInputContext
{
    CEntityIdentity* identity;
    CUtlSymbolLarge* inputName;
    CEntityInstance* activator;
    CEntityInstance* caller;
    variant_t* value;
    bool result;
};

/// CBaseEntity::Touch(other), on CBaseEntity's own vtable -- an entity class
/// that overrides Touch is not seen here.
struct TouchContext
{
    CBaseEntity* entity;
    CBaseEntity* other;
};

/// CCSPlayer_WeaponServices::DropWeapon(weapon, target, velocity)
struct DropWeaponContext
{
    CCSPlayer_WeaponServices* services;
    CBasePlayerWeapon* weapon;
    Vector* target;
    Vector* velocity;
};

/// The CCSPlayer_MovementServices functions that take the move data alone:
/// AirMove, CheckFalling, CheckParameters, Duck, Friction, PlayerMove,
/// ProcessMovement, WalkMove, WaterMove (void), and CanUnduck, CheckWater,
/// LadderMove, MoveInit (bool, in `result`).
struct MovementContext
{
    CCSPlayer_MovementServices* services;
    CMoveData* moveData;
    bool result;
};

/// CCSPlayer_MovementServices::AirAccelerate(move, wishDirection, wishSpeed, acceleration)
struct AirAccelerateContext
{
    CCSPlayer_MovementServices* services;
    CMoveData* moveData;
    Vector* wishDirection;
    float wishSpeed;
    float acceleration;
};

/// CCSPlayer_MovementServices::GroundAccelerate(move, wishDirection, frameTime, wishSpeed, acceleration).
/// The engine's argument order differs between Linux and Windows; here it is
/// always this one.
struct GroundAccelerateContext
{
    CCSPlayer_MovementServices* services;
    CMoveData* moveData;
    Vector* wishDirection;
    float frameTime;
    float wishSpeed;
    float acceleration;
};

/// CCSPlayer_MovementServices::CategorizePosition(move, stayOnGround)
struct CategorizePositionContext
{
    CCSPlayer_MovementServices* services;
    CMoveData* moveData;
    bool stayOnGround;
};

/// CCSPlayer_MovementServices::CheckVelocity(move, unk)
struct CheckVelocityContext
{
    CCSPlayer_MovementServices* services;
    CMoveData* moveData;
    void* unk;
};

/// CCSPlayer_MovementServices::FullWalkMove(move, onGround)
struct FullWalkMoveContext
{
    CCSPlayer_MovementServices* services;
    CMoveData* moveData;
    bool onGround;
};

/// CCSPlayer_MovementServices::SetupMove(cmd, move); the command is a CUserCmd.
struct SetupMoveContext
{
    CCSPlayer_MovementServices* services;
    CUserCmd* cmd;
    CMoveData* moveData;
};

/// CCSPlayer_MovementServices::TryPlayerMove(move, firstDest, firstTrace, isSurfing)
struct TryPlayerMoveContext
{
    CCSPlayer_MovementServices* services;
    CMoveData* moveData;
    Vector* firstDest;
    CGameTrace* firstTrace;
    bool* isSurfing;
};

/// CCSPlayerLegacyJump::OnJump / CheckJumpButton(move)
struct LegacyJumpContext
{
    CCSPlayerLegacyJump* jump;
    CMoveData* moveData;
};

/// CCSPlayerModernJump::OnJump / CheckJumpButton(move)
struct ModernJumpContext
{
    CCSPlayerModernJump* jump;
    CMoveData* moveData;
};

/// A handler: the context, and whether this is the post pass.
template <typename CONTEXT>
using GameHookHandler = std::function<Action(CONTEXT& ctx, bool post)>;

/// What HookX() returns and UnhookX() takes: one registered handler. A plugin
/// may register several handlers on the same function and drop any one of
/// them; whatever it still holds at unload the core drops for it.
using GameHookId = int;

/// The hooks, for IsAvailable().
enum class GameHook : int
{
    TakeDamage,
    CanAcquire,
    CanMove,
    CanUse,
    PostThink,
    ProcessUsercmds,
    SimulateUserCommands,
    RunCommand,
    AcceptInput,
    Touch,
    DropWeapon,
    AirAccelerate,
    AirMove,
    CanUnduck,
    CategorizePosition,
    CheckFalling,
    CheckParameters,
    CheckVelocity,
    CheckWater,
    Duck,
    Friction,
    FullWalkMove,
    GroundAccelerate,
    LadderMove,
    MoveInit,
    PlayerMove,
    ProcessMovement,
    SetupMove,
    TryPlayerMove,
    WalkMove,
    WaterMove,
    OnJumpLegacy,
    OnJumpModern,
    CheckJumpButtonLegacy,
    CheckJumpButtonModern,

    Count
};

/* =========================
Interface
========================= */

class IToolkitGameHooks
{
public:
    virtual ~IToolkitGameHooks() = default;

    virtual GameHookId HookTakeDamage(PluginId owner, GameHookHandler<TakeDamageContext> handler, bool post) = 0;
    virtual GameHookId HookCanAcquire(PluginId owner, GameHookHandler<CanAcquireContext> handler, bool post) = 0;
    virtual GameHookId HookCanMove(PluginId owner, GameHookHandler<CanMoveContext> handler, bool post) = 0;
    virtual GameHookId HookCanUse(PluginId owner, GameHookHandler<CanUseContext> handler, bool post) = 0;
    virtual GameHookId HookPostThink(PluginId owner, GameHookHandler<PostThinkContext> handler, bool post) = 0;
    virtual GameHookId HookProcessUsercmds(PluginId owner, GameHookHandler<ProcessUsercmdsContext> handler, bool post) = 0;
    virtual GameHookId HookSimulateUserCommands(PluginId owner, GameHookHandler<SimulateUserCommandsContext> handler, bool post) = 0;
    virtual GameHookId HookRunCommand(PluginId owner, GameHookHandler<RunCommandContext> handler, bool post) = 0;
    virtual GameHookId HookAcceptInput(PluginId owner, GameHookHandler<AcceptInputContext> handler, bool post) = 0;
    virtual GameHookId HookTouch(PluginId owner, GameHookHandler<TouchContext> handler, bool post) = 0;
    virtual GameHookId HookDropWeapon(PluginId owner, GameHookHandler<DropWeaponContext> handler, bool post) = 0;
    virtual GameHookId HookAirAccelerate(PluginId owner, GameHookHandler<AirAccelerateContext> handler, bool post) = 0;
    virtual GameHookId HookAirMove(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookCanUnduck(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookCategorizePosition(PluginId owner, GameHookHandler<CategorizePositionContext> handler, bool post) = 0;
    virtual GameHookId HookCheckFalling(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookCheckParameters(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookCheckVelocity(PluginId owner, GameHookHandler<CheckVelocityContext> handler, bool post) = 0;
    virtual GameHookId HookCheckWater(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookDuck(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookFriction(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookFullWalkMove(PluginId owner, GameHookHandler<FullWalkMoveContext> handler, bool post) = 0;
    virtual GameHookId HookGroundAccelerate(PluginId owner, GameHookHandler<GroundAccelerateContext> handler, bool post) = 0;
    virtual GameHookId HookLadderMove(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookMoveInit(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookPlayerMove(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookProcessMovement(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookSetupMove(PluginId owner, GameHookHandler<SetupMoveContext> handler, bool post) = 0;
    virtual GameHookId HookTryPlayerMove(PluginId owner, GameHookHandler<TryPlayerMoveContext> handler, bool post) = 0;
    virtual GameHookId HookWalkMove(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookWaterMove(PluginId owner, GameHookHandler<MovementContext> handler, bool post) = 0;
    virtual GameHookId HookOnJumpLegacy(PluginId owner, GameHookHandler<LegacyJumpContext> handler, bool post) = 0;
    virtual GameHookId HookOnJumpModern(PluginId owner, GameHookHandler<ModernJumpContext> handler, bool post) = 0;
    virtual GameHookId HookCheckJumpButtonLegacy(PluginId owner, GameHookHandler<LegacyJumpContext> handler, bool post) = 0;
    virtual GameHookId HookCheckJumpButtonModern(PluginId owner, GameHookHandler<ModernJumpContext> handler, bool post) = 0;

    /// Drops the one handler HookX() returned that id for.
    virtual void UnhookTakeDamage(GameHookId id) = 0;
    virtual void UnhookCanAcquire(GameHookId id) = 0;
    virtual void UnhookCanMove(GameHookId id) = 0;
    virtual void UnhookCanUse(GameHookId id) = 0;
    virtual void UnhookPostThink(GameHookId id) = 0;
    virtual void UnhookProcessUsercmds(GameHookId id) = 0;
    virtual void UnhookSimulateUserCommands(GameHookId id) = 0;
    virtual void UnhookRunCommand(GameHookId id) = 0;
    virtual void UnhookAcceptInput(GameHookId id) = 0;
    virtual void UnhookTouch(GameHookId id) = 0;
    virtual void UnhookDropWeapon(GameHookId id) = 0;
    virtual void UnhookAirAccelerate(GameHookId id) = 0;
    virtual void UnhookAirMove(GameHookId id) = 0;
    virtual void UnhookCanUnduck(GameHookId id) = 0;
    virtual void UnhookCategorizePosition(GameHookId id) = 0;
    virtual void UnhookCheckFalling(GameHookId id) = 0;
    virtual void UnhookCheckParameters(GameHookId id) = 0;
    virtual void UnhookCheckVelocity(GameHookId id) = 0;
    virtual void UnhookCheckWater(GameHookId id) = 0;
    virtual void UnhookDuck(GameHookId id) = 0;
    virtual void UnhookFriction(GameHookId id) = 0;
    virtual void UnhookFullWalkMove(GameHookId id) = 0;
    virtual void UnhookGroundAccelerate(GameHookId id) = 0;
    virtual void UnhookLadderMove(GameHookId id) = 0;
    virtual void UnhookMoveInit(GameHookId id) = 0;
    virtual void UnhookPlayerMove(GameHookId id) = 0;
    virtual void UnhookProcessMovement(GameHookId id) = 0;
    virtual void UnhookSetupMove(GameHookId id) = 0;
    virtual void UnhookTryPlayerMove(GameHookId id) = 0;
    virtual void UnhookWalkMove(GameHookId id) = 0;
    virtual void UnhookWaterMove(GameHookId id) = 0;
    virtual void UnhookOnJumpLegacy(GameHookId id) = 0;
    virtual void UnhookOnJumpModern(GameHookId id) = 0;
    virtual void UnhookCheckJumpButtonLegacy(GameHookId id) = 0;
    virtual void UnhookCheckJumpButtonModern(GameHookId id) = 0;

    /// False when the core's gamedata has no entry for the function on this
    /// platform -- handlers can still be registered, they just never run.
    virtual bool IsAvailable(GameHook hook) = 0;
};

#endif //_INCLUDE_ITOOLKIT_GAMEHOOKS_H
