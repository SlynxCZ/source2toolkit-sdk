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
 * @file IToolkitHud.h
 * @brief On-screen text and interaction prompts on the Panorama HUD.
 *
 * Text a plugin puts on a player's screen used to be a point_worldtext parented
 * to the pawn or a center HTML print redrawn every tick. This interface draws
 * it with a `custom_hud_layout` instead: crisp, positioned by the stylesheet,
 * per player, and gone when its time is up. The core owns the one layout
 * entity (created on first use, per map) and the per-player state; a plugin
 * calls ShowText() and forgets about it.
 *
 * What the client needs: the layout named by `HudTextLayout` in core.json
 * (default "s2t_hud"), compiled into an addon the players have -- see
 * panorama/README.md in the toolkit repository, which ships the reference
 * layout and stylesheet. The layout has to follow the id contract below; the
 * stylesheet is free.
 *
 * Layout contract (panel ids the core addresses):
 *
 *   hud_top, hud_topleft, hud_topright, hud_left, hud_right, hud_center,
 *   hud_bottom, hud_panel        one Panel per HudSlot; the core toggles
 *                                the class `show` and one colour class
 *                                (c-white .. c-grey, see HudColor) and one
 *                                size class (s-small .. s-huge, HudSize)
 *   <slot>_text                  a Label inside it with text="{s:text}"
 *   hud_prompt                   the interaction prompt Panel (`show`)
 *   hud_prompt_key               Label text="{s:text}": the key, e.g. "E"
 *   hud_prompt_text              Label text="{s:text}": what the key does
 *   hud_prompt_barwrap           Panel shown (`show`) while a progress is given
 *   hud_prompt_bar               Panel that gets one of w0 .. w20 (5 % steps)
 *
 * Everything is per player: what one player sees, nobody else does.
 */

#ifndef _INCLUDE_ITOOLKIT_HUD_H
#define _INCLUDE_ITOOLKIT_HUD_H

#pragma once
#include "IToolkitPlugin.h"

class CCSPlayerController;

/// Where on the screen a text goes. Each is a panel of the layout; the
/// stylesheet decides where that panel is.
enum class HudSlot : int
{
    Top = 0,     ///< top centre -- announcements
    TopLeft,
    TopRight,
    Left,        ///< left of the crosshair
    Right,       ///< right of the crosshair
    Center,      ///< over the crosshair -- countdowns, "START"
    Bottom,      ///< above the weapon HUD
    Panel,       ///< a boxed multi-line panel (quests, info)

    Count
};

/// The colour classes the stylesheet defines (c-white, c-red, ...).
enum class HudColor : int
{
    White = 0,
    Red,
    Green,
    Blue,
    Yellow,
    Orange,
    Purple,
    Cyan,
    Grey,

    Count
};

/// The size classes the stylesheet defines (s-small, s-normal, ...).
enum class HudSize : int
{
    Small = 0,
    Normal,
    Large,
    Huge,

    Count
};

struct HudTextStyle
{
    HudColor color = HudColor::White;
    HudSize size = HudSize::Normal;
};

#define TOOLKIT_HUD_INTERFACE "IToolkitHud001"

class IToolkitHud
{
public:
    virtual ~IToolkitHud() = default;

    /**
     * @brief Whether the text layout exists for the running map.
     *
     * False before the first map, after the entity failed to spawn (logged
     * once), or when the client would draw nothing anyway is not something
     * the server can tell -- a player without the addon simply sees no text.
     */
    virtual bool IsAvailable() = 0;

    /**
     * @brief Shows a text in a slot for one player, replacing what was there.
     *
     * @param player  Who sees it
     * @param slot    Where
     * @param text    Plain text; "\n" starts a new line, there is no markup
     * @param seconds How long, 0 or less: until HideText()
     * @param style   Colour and size
     */
    virtual void ShowText(CCSPlayerController* player, HudSlot slot, const char* text, float seconds, HudTextStyle style = {}) = 0;

    /// Clears one slot for one player.
    virtual void HideText(CCSPlayerController* player, HudSlot slot) = 0;

    /**
     * @brief Shows the interaction prompt: a key cap and what it does.
     *
     * @param player   Who sees it
     * @param key      The key, e.g. "E"
     * @param text     e.g. "Steal the weapon"
     * @param progress 0..1 draws a progress bar; below 0 hides the bar
     */
    virtual void ShowPrompt(CCSPlayerController* player, const char* key, const char* text, float progress = -1.0f) = 0;

    virtual void HidePrompt(CCSPlayerController* player) = 0;

    /// Every slot and the prompt, for one player.
    virtual void HideAll(CCSPlayerController* player) = 0;

    /// The layout name the core uses (HudTextLayout in core.json).
    virtual const char* LayoutName() = 0;
};

#endif //_INCLUDE_ITOOLKIT_HUD_H
