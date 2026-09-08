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

* @file IToolkitTypes.h
* @brief Types shared by every toolkit callback.
*
* Defines:
* * Action -- what a callback tells the toolkit to do with the original
  */

#ifndef _INCLUDE_ITOOLKIT_TYPES_H
#define _INCLUDE_ITOOLKIT_TYPES_H

#pragma once
#include <cstdint>
#include <type_traits>

/* =========================
Hook control
========================= */

/**

* @brief What a toolkit callback (command listener, game event hook, net
* message hook, entity output listener) did about the original.
*
* The values line up with KHook::Action, so a KHook handler can hand a
* toolkit Action straight through with a static_cast.
  */
enum class Action : std::uint8_t
{
    /// Did nothing; the original runs as it would have.
    Ignore = 0,

    /// Changed something (the event, the return value) but the original still
    /// runs. Pre only.
    Override,

    /// Block the original entirely. Pre only.
    Supersede
};


// A KHook hook carries the hooked member function and the callbacks in its
// type. CTAD would derive that from the constructor arguments, but MSVC cannot,
// so this takes it from the member the hook is stored in instead -- for a
// constructor's initialiser list:
//
//     KHOOK_NEW(m_hGameFrame, &ISource2Server::GameFrame, this, nullptr, &Plugin::Hook_GameFrame)
//
#define KHOOK_NEW(member, ...) member(new std::remove_pointer_t<decltype(member)>(__VA_ARGS__))

#endif //_INCLUDE_ITOOLKIT_TYPES_H
