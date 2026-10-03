/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl.
 * All rights reserved.
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
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 * gives you permission to link the code of this program
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
 *
 * Project: Source2Toolkit
 */

/**

* @file IToolkitPermissions.h
* @brief Admins, groups and permissions, and the commands they gate.
*
* A permission is a lower-case dotted string a plugin makes up for itself:
* "funplay.admin.kick", "vip.trail". What a player holds may end in ".*",
* which covers that node and everything below it ("funplay.admin.*" covers
* "funplay.admin" and "funplay.admin.kick", not "funplay.adminx"), and "*"
* covers everything -- the root permission.
*
* A group is a name with permissions, an immunity and groups it inherits
* from. The group "default" applies to every player, also to one whose
* SteamID is not known yet.
*
* Players are looked up by SteamID64, so a SteamID can be granted things
* before its player connects. Which SteamID a connected player is checked
* under depends on SteamAuthMode in core.json:
*
* * "auto"     -- the SteamID the client claimed, right away, when the server
*                 does not validate Steam tickets (-insecure, sv_lan 1, no
*                 Steam connection); otherwise only once Steam validated it.
* * "flexible" -- always the claimed SteamID right away.
* * "strict"   -- always only once Steam validated it.
*
* Until then the player has the "default" group and nothing else.
* IToolkitListener::OnClientAuthorized() says when the validated one arrives.
*
* What a player holds comes in layers: configs/permissions.json (admins,
* groups and command overrides an owner writes by hand), and one layer per
* plugin that grants something at runtime. A player has the union of every
* layer. A plugin's layer is dropped when it unloads, and
* "toolkit admins reload" re-reads the file without touching the plugins'
* layers -- a plugin that loads admins from a database grants them again
* from its Load() and keeps them current itself.
  */

#ifndef _INCLUDE_ITOOLKIT_PERMISSIONS_H
#define _INCLUDE_ITOOLKIT_PERMISSIONS_H

#pragma once
#include "IToolkitPlugin.h"

// IToolkitCommands.h may be the header that pulled this one in (through
// IToolkitPlugin.h) before it got to these, so they are only declared here;
// a reference to them is all the handler type needs.
class ToolkitCommandContext;
class ToolkitCommandArgs;

/**
 * @brief What runs when a player is refused a command.
 *
 * @param ctx        The command's context: who ran it and from where, so
 *                   ReplyToCommand() lands where they typed it.
 * @param args       The command as typed.
 * @param permission The permission the command needs.
 */
using AccessDeniedHandler = ToolkitCallback<void(const ToolkitCommandContext& ctx, const ToolkitCommandArgs& args, const char* permission)>;

#define TOOLKIT_PERMISSIONS_INTERFACE "IToolkitPermissions001"

class IToolkitPermissions
{
public:
    virtual ~IToolkitPermissions() = default;

    /* =========================
    Checks
    ========================= */

    /**
     * @brief Whether this SteamID64 holds the permission, through any layer,
     * group or wildcard. 0 (an unknown player) has the "default" group only.
     */
    virtual bool HasPermission(uint64 steamId, const char* permission) = 0;

    /**
     * @brief Whether the player in this slot holds the permission, under the
     * SteamID they are checked by (see GetPlayerSteamID()). The server
     * console -- an invalid slot -- holds everything.
     */
    virtual bool PlayerHasPermission(CPlayerSlot slot, const char* permission) = 0;

    /**
     * @brief SourceMod's CheckCommandAccess: a feature gate the owner can
     * re-assign in permissions.json.
     *
     * The permission checked is the "Overrides" entry for `name` when there
     * is one, otherwise `defaultPermission`. An empty permission lets
     * everybody through.
     */
    virtual bool CheckAccess(CPlayerSlot slot, const char* name, const char* defaultPermission) = 0;

    /// Whether this SteamID64 is in the group, directly or by inheritance.
    virtual bool InGroup(uint64 steamId, const char* group) = 0;

    /// The highest immunity among the player's own and their groups'.
    virtual int GetImmunity(uint64 steamId) = 0;

    /**
     * @brief Whether `caller` may act on `target`: the server console and a
     * root ("*") caller always may, anybody may act on themselves, and
     * otherwise the caller's immunity has to be at least the target's.
     */
    virtual bool CanTarget(CPlayerSlot caller, CPlayerSlot target) = 0;

    /**
     * @brief The SteamID64 the player in this slot is checked under: 0 for
     * an empty slot, a bot, or a player Steam has not validated yet while
     * SteamAuthMode wants it to.
     */
    virtual uint64 GetPlayerSteamID(CPlayerSlot slot) = 0;

    /// Whether Steam validated the player in this slot.
    virtual bool IsPlayerAuthorized(CPlayerSlot slot) = 0;

    /* =========================
    Players -- in the caller's layer
    ========================= */

    /**
     * @brief Grants a permission (wildcards allowed) to a SteamID64, in the
     * owner's layer. Gone when the owner unloads, or by RevokePermission().
     */
    virtual void GrantPermission(PluginId owner, uint64 steamId, const char* permission) = 0;

    /// Takes back what GrantPermission() gave in the owner's layer; other
    /// layers are untouched.
    virtual void RevokePermission(PluginId owner, uint64 steamId, const char* permission) = 0;

    /// Puts a SteamID64 in a group, in the owner's layer.
    virtual void AddToGroup(PluginId owner, uint64 steamId, const char* group) = 0;

    /// Takes a SteamID64 out of a group in the owner's layer.
    virtual void RemoveFromGroup(PluginId owner, uint64 steamId, const char* group) = 0;

    /// The player's own immunity in the owner's layer; the highest of all
    /// layers and groups counts.
    virtual void SetImmunity(PluginId owner, uint64 steamId, int immunity) = 0;

    /// Drops everything the owner's layer holds for this SteamID64.
    virtual void ClearPlayer(PluginId owner, uint64 steamId) = 0;

    /* =========================
    Groups -- in the caller's layer
    ========================= */

    /**
     * @brief Defines a group in the owner's layer, or sets its immunity when
     * it is already there. A group defined in several layers (the file and a
     * plugin, two plugins) has all of their permissions and parents and the
     * highest immunity.
     */
    virtual void CreateGroup(PluginId owner, const char* group, int immunity) = 0;

    /// Drops the owner's definition of the group; other layers' stay.
    virtual void DeleteGroup(PluginId owner, const char* group) = 0;

    /// Adds a permission to the owner's definition of the group (made if missing).
    virtual void AddGroupPermission(PluginId owner, const char* group, const char* permission) = 0;

    /// Takes a permission back out of the owner's definition of the group.
    virtual void RemoveGroupPermission(PluginId owner, const char* group, const char* permission) = 0;

    /// Makes the group inherit everything `parent` has (made if missing).
    virtual void AddGroupParent(PluginId owner, const char* group, const char* parent) = 0;

    /// Undoes AddGroupParent() in the owner's layer.
    virtual void RemoveGroupParent(PluginId owner, const char* group, const char* parent) = 0;

    /* =========================
    Refused commands
    ========================= */

    /**
     * @brief Replaces what a player sees when they are refused a command.
     *
     * The core answers "You do not have access to this command." (the
     * AccessDeniedMessage of core.json) through ReplyToCommand() -- to chat
     * when they typed it in chat, to their console otherwise. A plugin that
     * wants its own wording (a translation, a prefix) sets a handler; the
     * one set last is used, and when its plugin unloads the one before it
     * takes over again.
     *
     * @return The id ClearAccessDeniedHandler() takes
     */
    virtual ToolkitHookId SetAccessDeniedHandler(AccessDeniedHandler handler) = 0;

    /// Drops a handler SetAccessDeniedHandler() returned the id for.
    virtual bool ClearAccessDeniedHandler(ToolkitHookId id) = 0;
};

#define PERMISSIONS_HAS(steamId, permission)              g_pToolkitPermissions->HasPermission(steamId, permission)
#define PERMISSIONS_PLAYER_HAS(slot, permission)          g_pToolkitPermissions->PlayerHasPermission(slot, permission)
#define PERMISSIONS_CHECK_ACCESS(slot, name, permission)  g_pToolkitPermissions->CheckAccess(slot, name, permission)
#define PERMISSIONS_GRANT(steamId, permission)            g_pToolkitPermissions->GrantPermission(g_PluginID, steamId, permission)
#define PERMISSIONS_REVOKE(steamId, permission)           g_pToolkitPermissions->RevokePermission(g_PluginID, steamId, permission)
#define PERMISSIONS_ADD_TO_GROUP(steamId, group)          g_pToolkitPermissions->AddToGroup(g_PluginID, steamId, group)
#define PERMISSIONS_REMOVE_FROM_GROUP(steamId, group)     g_pToolkitPermissions->RemoveFromGroup(g_PluginID, steamId, group)

#endif //_INCLUDE_ITOOLKIT_PERMISSIONS_H
