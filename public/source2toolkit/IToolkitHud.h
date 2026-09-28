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
 * @brief On-screen text, prompts, toasts, announcements, countdowns, status
 *        chips, progress bars, hit feedback, an event feed and overlays on
 *        the Panorama HUD.
 *
 * Text a plugin puts on a player's screen used to be a point_worldtext parented
 * to the pawn or a center HTML print redrawn every tick. This interface draws
 * it with a `custom_hud_layout` instead: crisp, positioned by the stylesheet,
 * per player, and gone when its time is up. The layout entities (created on
 * first use, per map) and the per-player state belong to the interface; a
 * plugin calls ShowText() and forgets about it.
 *
 * Served by the CustomhudManager_s2t plugin (customhud_manager.stx), not the core: it is not filled by
 * TOOLKIT_SAVEVARS(). Fetch it once every plugin is loaded:
 *
 *   void MyPlugin::OnAllToolkitPluginsLoaded()
 *   {
 *       int ret;
 *       GET_TOOLKIT_IFACE(g_pToolkitHud, IToolkitHud, TOOLKIT_HUD_INTERFACE, ret);
 *   }
 *
 * and treat a null g_pToolkitHud as "no HUD" (the plugin is not installed,
 * or it is older than this header). The HudMenu below is a menu drawn by the
 * same plugin through the core's menu system (IToolkitMenus::OpenMenu).
 *
 * What the client needs: the layouts "s2t_hud" (texts) and "s2t_menu"
 * (menus), compiled into an addon the players have -- see panorama/README.md
 * in the toolkit repository, which ships the reference layouts and
 * stylesheets. A layout has to follow the id contract below; the stylesheet
 * is free.
 *
 * Layout contract (panel ids the plugin addresses):
 *
 *   hud_top, hud_topleft, hud_topright, hud_left, hud_right, hud_center,
 *   hud_bottom, hud_panel        one Panel per HudSlot; the core toggles
 *                                the class `show` and one colour class
 *                                (c-white .. c-grey, see HudColor) and one
 *                                size class (s-small .. s-huge, HudSize)
 *                                and the offset classes xm10 .. xp10 and
 *                                ym10 .. yp10 (HudTextStyle::offsetX/Y)
 *   <slot>_text                  a Label inside it with text="{s:text}"
 *   hud_prompt                   the interaction prompt Panel (`show`)
 *   hud_prompt_key               Label text="{s:text}": the key, e.g. "E"
 *   hud_prompt_text              Label text="{s:text}": what the key does
 *   hud_prompt_barwrap           Panel shown (`show`) while a progress is given
 *   hud_prompt_bar               Panel that gets one of w0 .. w20 (5 % steps)
 *   hud_toast_0 .. hud_toast_3   toast cards, newest first (`show`, t-* of
 *                                HudToastStyle, in-a / in-b to restart the entrance)
 *   hud_toast_N_title, _text     Labels text="{s:text}"
 *   hud_announce                 the announcement (`show`, c-*, in-a / in-b)
 *   hud_announce_title, _sub     Labels text="{s:text}"
 *   hud_countdown                the countdown (`show`, c-*, pop-a / pop-b per tick)
 *   hud_countdown_text           Label text="{s:text}"
 *   hud_status                   the chip row (`show`)
 *   hud_status_0 .. hud_status_3 chips (`show`, c-*)
 *   hud_status_N_label, _value   Labels text="{s:text}"
 *   hud_progress                 the bar (`show`, c-*)
 *   hud_progress_label, _value   Labels text="{s:text}"
 *   hud_progress_bar             Panel with w0 .. w20
 *   hud_hitmarker                crosshair flash (`show`, hit-a / hit-b, headshot, kill)
 *   hud_damage                   the number next to it (`show`, dmg-a / dmg-b, headshot, kill)
 *   hud_damage_text              Label text="{s:text}"
 *   hud_feed                     the feed (`show`)
 *   hud_feed_0 .. hud_feed_4     rows, newest first (`show`, t-*)
 *   hud_feed_N_time, _text       Labels text="{s:text}"
 *   hud_overlay                  full-screen tint (`show`, o-* of HudOverlay)
 *   hud_overlay_text             Label text="{s:text}"
 *   hud_timer                    the big timer (`show`, c-*, tick-a / tick-b per call)
 *   hud_timer_tag, _num, _sub    Labels text="{s:text}": the pill, the time, the line under it
 *   hud_card                     the corner card (`show`, c-*)
 *   hud_card_tag, _title, _sub   Labels text="{s:text}"
 *
 * Everything is per player: what one player sees, nobody else does.
 */

#ifndef _INCLUDE_ITOOLKIT_HUD_H
#define _INCLUDE_ITOOLKIT_HUD_H

#pragma once
#include "IToolkitPlugin.h"
#include "IToolkitMenus.h"

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

    /// Where the slot sits, relative to the place the stylesheet gives it:
    /// steps of 40 px on a 1080p reference, -10..10, positive is right and
    /// down. Classes xm10..xp10 / ym10..yp10 on the slot panel; a value
    /// outside the range is clamped.
    int offsetX = 0;
    int offsetY = 0;
};

/// The toast and feed styles (t-info, t-success, ...).
enum class HudToastStyle : int
{
    Info = 0,
    Success,
    Warning,
    Danger,
    Neutral,

    Count
};

/// The full-screen overlays (o-poison, o-burn, ...).
enum class HudOverlay : int
{
    Poison = 0,
    Burn,
    Freeze,
    Heal,
    Blind,      ///< white-out
    Black,      ///< fade to black, with an optional label

    Count
};

/* =========================
Panorama HUD menu
========================= */

/// Where on the screen a HudMenu is drawn; a class on the layout's menu_root.
enum class HudMenuPosition : int
{
    Left = 0,
    Center,
    Right,
};

/**
 * @brief A menu drawn with a custom_hud_layout (IToolkitHud::OpenMenu).
 *
 * The same options and handlers as CenterHtmlMenu; only the screen differs.
 * The player clicks the rows or presses 1-6 (the options of the page), 7
 * (previous page), 8 (next page), 9 (close), so the chat triggers keep
 * working. The navigation texts are the plugin's, which is how they get to
 * be in the player's language.
 *
 * Needs the menu layout ("s2t_menu"; the reference layout is
 * panorama/layout/custom_game/s2t_menu.xml in the toolkit repository) in an
 * addon the player has. A player without it sees nothing.
 */
class HudMenu : public IBaseMenu
{
public:
    explicit HudMenu(std::string title)
        : IBaseMenu(std::move(title))
    {
        SetExitButton(true);
    }

    std::string PrevText = "Prev";
    std::string NextText = "Next";
    std::string CloseText = "Close";

    /// Dims the screen behind the menu.
    bool DimBackground = true;

    /// With input capture the player gets a cursor and can click the rows,
    /// but cannot move or aim while the menu is open. Without it the menu is
    /// display-only: the number keys (binds, chat triggers) pick the options
    /// and the player keeps playing. Per menu, so a plugin can make it the
    /// player's choice.
    bool CaptureInput = true;

    /// A dead player cannot use the slot binds (they do nothing without a
    /// pawn), so a menu without CaptureInput takes the mouse for as long as
    /// the player is dead and lets go on respawn. The keys and the chat
    /// triggers keep working meanwhile; the clicks are added, not swapped in.
    bool CaptureWhenDead = true;

    /// Where the window sits: one of the classes pos-left, pos-center,
    /// pos-right goes on menu_root and the stylesheet places it.
    HudMenuPosition Position = HudMenuPosition::Left;
};

#define TOOLKIT_HUD_INTERFACE "IToolkitHud004"

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
     * @param style   Colour, size and the offset from the slot's place
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

    /// Every slot, the prompt and everything below, for one player.
    virtual void HideAll(CCSPlayerController* player) = 0;

    /// The layout name the core uses (HudTextLayout in core.json).
    virtual const char* LayoutName() = 0;

    /* =========================
    IToolkitHud002
    ========================= */

    /**
     * @brief A toast: a card in the stack at the top right, newest first.
     *
     * Four are kept; a fifth pushes the oldest out. Each goes away after
     * its own time.
     *
     * @param player  Who sees it
     * @param style   Its colour and the edge (HudToastStyle)
     * @param title   One line, bold
     * @param text    The message under it, may wrap; "" for none
     * @param seconds How long, 0 or less: until ClearToasts() or pushed out
     */
    virtual void ShowToast(CCSPlayerController* player, HudToastStyle style, const char* title, const char* text, float seconds) = 0;

    virtual void ClearToasts(CCSPlayerController* player) = 0;

    /**
     * @brief The big announcement in the upper centre: a title and a line
     *        under it, with an entrance animation each time.
     *
     * @param seconds How long, 0 or less: until HideAnnounce()
     */
    virtual void ShowAnnounce(CCSPlayerController* player, const char* title, const char* subtitle, float seconds, HudColor color = HudColor::White) = 0;

    virtual void HideAnnounce(CCSPlayerController* player) = 0;

    /**
     * @brief The giant centre number or word: "3", "2", "1", "GO". Each call
     *        pops it again, so a countdown is one call a second.
     *
     * @param seconds How long this text stays, 0 or less: until HideCountdown()
     */
    virtual void ShowCountdown(CCSPlayerController* player, const char* text, float seconds, HudColor color = HudColor::White) = 0;

    virtual void HideCountdown(CCSPlayerController* player) = 0;

    /**
     * @brief A status chip in the row under the round timer: a small label
     *        and a value. Stays until hidden.
     *
     * @param chip 0 .. 3, left to right
     */
    virtual void ShowStatus(CCSPlayerController* player, int chip, const char* label, const char* value, HudColor color = HudColor::White) = 0;

    /// One chip, or every chip with a negative index.
    virtual void HideStatus(CCSPlayerController* player, int chip) = 0;

    /**
     * @brief A labelled progress bar under the crosshair. Stays until
     *        hidden; call again to move the bar.
     *
     * @param value    Text at the right end of the label row, e.g. "7 s"; "" for none
     * @param progress 0..1
     */
    virtual void ShowProgress(CCSPlayerController* player, const char* label, const char* value, float progress, HudColor color = HudColor::White) = 0;

    virtual void HideProgress(CCSPlayerController* player) = 0;

    /**
     * @brief Hit feedback: the crosshair flashes and the damage drifts up
     *        next to it, gold on a headshot, red on a kill. Gone by itself.
     *
     * @param damage 0 or less: the flash alone
     */
    virtual void ShowHit(CCSPlayerController* player, int damage, bool headshot, bool kill) = 0;

    /**
     * @brief A row in the event feed at the top left, newest first. Five are
     *        kept; a sixth pushes the oldest out.
     *
     * @param time    The short text at the left, e.g. "12:04" or "R3"; "" for none
     * @param seconds How long the row stays, 0 or less: until ClearFeed() or pushed out
     */
    virtual void AddFeed(CCSPlayerController* player, HudToastStyle style, const char* time, const char* text, float seconds) = 0;

    virtual void ClearFeed(CCSPlayerController* player) = 0;

    /**
     * @brief A full-screen tint: poison, burn, freeze, heal, a white-out or
     *        a fade to black, with an optional centred label.
     *
     * @param seconds How long, 0 or less: until HideOverlay()
     */
    virtual void ShowOverlay(CCSPlayerController* player, HudOverlay overlay, const char* text, float seconds) = 0;

    virtual void HideOverlay(CCSPlayerController* player) = 0;

    /* =========================
    IToolkitHud004
    ========================= */

    /**
     * @brief Opens a HudMenu for a player, on the Panorama HUD.
     *
     * Goes through the core's menu system (IToolkitMenus::OpenMenu), so it
     * closes the player's other menu, takes the number keys and the clicks,
     * and is closed for you when `owner` unloads. Draws nothing for a
     * player without the layout; where that cannot be assumed, a
     * CenterHtmlMenu is the fallback.
     *
     * @param owner  Plugin the menu belongs to
     * @param player Target player
     * @param menu   The menu; must outlive the time it is open
     */
    virtual void OpenMenu(PluginId owner, CCSPlayerController* player, HudMenu* menu) = 0;

    /**
     * @brief The big timer: a tag pill, a large time and a line under it,
     *        with a halo in the colour; each call pulses the number.
     *
     * A countdown is one call a second with the new time; the caller keeps
     * the clock. Stays until HideTimer().
     *
     * @param player Who sees it
     * @param tag    The pill above the number, e.g. "FREE DAY"; "" for none
     * @param time   The number, e.g. "2:45"
     * @param sub    The line under it; "" for none
     * @param color  The halo and the number
     */
    virtual void ShowTimer(CCSPlayerController* player, const char* tag, const char* time, const char* sub, HudColor color) = 0;

    virtual void HideTimer(CCSPlayerController* player) = 0;

    /**
     * @brief The corner card: a tag, a title and a subtitle in a box at the
     *        top left -- the day of a jail, the role of a player, the mode.
     *
     * Stays until HideCard(); a new call replaces the texts in place.
     *
     * @param player Who sees it
     * @param tag    Small line above the title, e.g. "DAY 3"; "" for none
     * @param title  The big line
     * @param sub    The line under it; "" for none
     * @param color  The edge and the tag
     */
    virtual void ShowCard(CCSPlayerController* player, const char* tag, const char* title, const char* sub, HudColor color) = 0;

    virtual void HideCard(CCSPlayerController* player) = 0;
};

#define OPEN_HUD_MENU(player, menu)  g_pToolkitHud->OpenMenu(g_PluginID, player, menu)

#endif //_INCLUDE_ITOOLKIT_HUD_H
