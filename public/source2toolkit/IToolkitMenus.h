/**
 * @file IToolkitMenus.h
 * @brief Interface and base implementation for menu system.
 *
 * Provides functionality for:
 *  * Defining menus and menu options
 *  * Handling per-player menu instances
 *  * Processing menu navigation and input
 */

#ifndef _INCLUDE_ITOOLKIT_MENUS_H
#define _INCLUDE_ITOOLKIT_MENUS_H

#pragma once
#include "eiface.h"

#include <string>
#include <vector>
#include <functional>
#include <stack>

/* =========================
Forward declarations
========================= */

class CCSPlayerController;

/* =========================
Post select behavior
========================= */

/**
 * @brief Action executed after selecting a menu option.
 */
enum class PostSelectAction
{
    /// Close menu after selection
    Close,

    /// Reset menu to first page
    Reset,

    /// Do nothing
    Nothing
};

/* =========================
Menu option
========================= */

/**
 * @brief Represents a single menu option.
 *
 * Contains display text, state and callback logic.
 */
struct ChatMenuOption
{
    /// Display text
    std::string Text;

    /// Whether option is disabled
    bool Disabled{false};

    /// Callback executed on select
    std::function<void(CCSPlayerController *, ChatMenuOption &)> OnSelect;

    /// Optional dynamic disabled evaluator
    std::function<bool()> DisabledEvaluator;
};

/* =========================
IMenu interface
========================= */

/**
 * @brief Base interface for menu definitions.
 */
class IMenu
{
public:
    virtual ~IMenu() = default;

    /**
     * @brief Gets menu title.
     *
     * @return Reference to menu title string
     */
    virtual const std::string &Title() const = 0;

    /**
     * @brief Gets menu options.
     *
     * @return Reference to options vector
     */
    virtual std::vector<ChatMenuOption> &Options() = 0;

    /**
     * @brief Gets menu options (const).
     *
     * @return Const reference to options vector
     */
    virtual const std::vector<ChatMenuOption> &Options() const = 0;

    /**
     * @brief Gets post-select behavior.
     *
     * @return PostSelectAction value
     */
    virtual PostSelectAction GetPostSelectAction() const = 0;

    /**
     * @brief Sets post-select behavior.
     *
     * @param a Behavior to apply after selection
     */
    virtual void SetPostSelectAction(PostSelectAction a) = 0;

    /**
     * @brief Gets exit button state.
     *
     * @return True if exit button is enabled
     */
    virtual bool GetExitButton() const = 0;

    /**
     * @brief Sets exit button state.
     *
     * @param v True to enable exit button
     */
    virtual void SetExitButton(bool v) = 0;
};

/* =========================
BaseMenu
========================= */

/**
 * @brief Base implementation of IMenu.
 */
class IBaseMenu : public IMenu
{
public:
    /**
     * @brief Constructs a menu.
     *
     * @param title Menu title
     */
    explicit IBaseMenu(std::string title)
        : title_(std::move(title))
    {
    }

    const std::string &Title() const override { return title_; }

    std::vector<ChatMenuOption> &Options() override { return options_; }
    const std::vector<ChatMenuOption> &Options() const override { return options_; }

    PostSelectAction GetPostSelectAction() const override { return postSelect_; }

    /**
     * @brief Sets post-select behavior.
     *
     * @param a Behavior to apply
     */
    void SetPostSelectAction(PostSelectAction a) override { postSelect_ = a; }

    bool GetExitButton() const override { return exitButton_; }

    /**
     * @brief Sets exit button state.
     *
     * @param v True to enable exit button
     */
    void SetExitButton(bool v) override { exitButton_ = v; }

    /**
     * @brief Adds a menu option.
     *
     * @param display Display text
     * @param onSelect Callback executed on selection
     * @param disabled Whether option is disabled
     *
     * @return Reference to created option
     */
    ChatMenuOption &AddMenuOption(
        std::string display,
        std::function<void(CCSPlayerController *, ChatMenuOption &)> onSelect,
        bool disabled = false)
    {
        options_.push_back(ChatMenuOption{
            .Text = std::move(display),
            .Disabled = disabled,
            .OnSelect = std::move(onSelect)
        });
        return options_.back();
    }

    /**
     * @brief Adds a menu option with cooldown support.
     *
     * @param optionText Display text
     * @param action Callback executed on selection
     * @param disabled Whether option is disabled
     * @param close Whether menu closes after select
     * @param disabledEvaluator Optional dynamic disabled evaluator
     *
     * @return Reference to created option
     */
    virtual ChatMenuOption &AddMenuOptionWithCooldown(
        std::string optionText,
        std::function<void(CCSPlayerController *, ChatMenuOption &)> action,
        bool disabled = false,
        bool close = true,
        std::function<bool()> disabledEvaluator = nullptr);

    /**
     * @brief Sets global cooldown handlers.
     *
     * @param canSelect Function that checks if player can select
     * @param onSelect Function called after selection
     */
    void SetCooldownHandlers(
        std::function<bool(CCSPlayerController *)> canSelect,
        std::function<void(CCSPlayerController *)> onSelect)
    {
        if (canSelect) s_canSelect = std::move(canSelect);
        if (onSelect) s_onSelect = std::move(onSelect);
    }

public:
    std::function<bool(CCSPlayerController *)> s_canSelect;
    std::function<void(CCSPlayerController *)> s_onSelect;

private:
    std::string title_;
    std::vector<ChatMenuOption> options_;

    PostSelectAction postSelect_{PostSelectAction::Reset};
    bool exitButton_{true};
};

/* =========================
Menu instances
========================= */

/**
 * @brief Runtime instance of a menu bound to a player.
 */
class IMenuInstance
{
public:
    virtual ~IMenuInstance() = default;

    /**
     * @brief Displays the menu.
     */
    virtual void Display() = 0;

    /**
     * @brief Handles key press input.
     *
     * @param player Player who triggered input
     * @param key Pressed key (1-9)
     */
    virtual void OnKeyPress(CCSPlayerController *player, int key) = 0;

    /**
     * @brief Resets menu state.
     */
    void Reset()
    {
        while (!prevPageOffsets_.empty()) prevPageOffsets_.pop();
        page_ = 0;
        currentOffset_ = 0;
    }

    /**
     * @brief Closes the menu.
     */
    virtual void Close();

    /**
     * @brief Gets underlying menu.
     *
     * @return Pointer to menu
     */
    IMenu *Menu() const { return menu_; }

    /**
     * @brief Gets owning player.
     *
     * @return Pointer to player
     */
    CCSPlayerController *Player() { return player_; }

protected:
    /**
     * @brief Constructs menu instance.
     *
     * @param player Owning player
     * @param menu Menu definition
     */
    IMenuInstance(CCSPlayerController *player, IMenu *menu)
        : player_(player), menu_(menu)
    {
    }

    /**
     * @brief Number of items per page.
     *
     * @return Items per page
     */
    virtual int NumPerPage() const { return 6; }

    /**
     * @brief Menu items per page.
     *
     * @return Items per page (including navigation)
     */
    virtual int MenuItemsPerPage() const { return NumPerPage(); }

    /**
     * @brief Checks if previous page exists.
     *
     * @return True if previous page exists
     */
    bool HasPrevButton() const { return page_ > 0; }

    /**
     * @brief Checks if next page exists.
     *
     * @return True if next page exists
     */
    bool HasNextButton() const
    {
        const auto &opts = menu_->Options();
        return (int) opts.size() > NumPerPage() && (currentOffset_ + NumPerPage()) < (int) opts.size();
    }

    /**
     * @brief Checks if exit button is enabled.
     *
     * @return True if enabled
     */
    bool HasExitButton() const { return menu_->GetExitButton(); }

    /**
     * @brief Advances to next page.
     */
    void NextPage()
    {
        prevPageOffsets_.push(currentOffset_);
        currentOffset_ += MenuItemsPerPage();
        ++page_;
        Display();
    }

    /**
     * @brief Goes back to previous page.
     */
    void PrevPage()
    {
        if (page_ <= 0 || prevPageOffsets_.empty()) return;
        --page_;
        currentOffset_ = prevPageOffsets_.top();
        prevPageOffsets_.pop();
        Display();
    }

protected:
    IMenu *menu_;
    CCSPlayerController *player_;

    int page_{0};
    int currentOffset_{0};

    std::stack<int> prevPageOffsets_;
};

/* =========================
Center HTML menu
========================= */

/**
 * @brief Styled center HTML menu.
 */
class CenterHtmlMenu : public IBaseMenu
{
public:
    /**
     * @brief Constructs center HTML menu.
     *
     * @param title Menu title
     */
    explicit CenterHtmlMenu(std::string title)
        : IBaseMenu(title)
    {
        SetExitButton(true);
    }

    std::string TitleColor = "yellow";
    std::string EnabledColor = "green";
    std::string DisabledColor = "grey";
    std::string PrevPageColor = "yellow";
    std::string NextPageColor = "yellow";
    std::string CloseColor = "red";
};

/* =========================
Core Toolkit Menus
========================= */

/**
 * @brief Interface for menu system management.
 */
class IToolkitMenus
{
public:
    virtual ~IToolkitMenus() = default;

    /**
     * @brief Opens a CenterHtmlMenu for a player.
     *
     * @param player Target player
     * @param menu Menu to open
     */
    virtual void OpenCenterHtmlMenu(CCSPlayerController *player, CenterHtmlMenu *menu) = 0;

    /**
     * @brief Gets active menu instance for player.
     *
     * @param player Target player
     *
     * @return Pointer to active menu instance or nullptr
     */
    virtual IMenuInstance *GetActiveMenu(CCSPlayerController *player) = 0;

    /**
     * @brief Closes active menu for player.
     *
     * @param player Target player
     */
    virtual void CloseActiveMenu(CCSPlayerController *player) = 0;

    /**
     * @brief Handles key press input.
     *
     * @param player Player who pressed key
     * @param key Pressed key (1-9)
     */
    virtual void OnKeyPress(CCSPlayerController *player, int key) = 0;
};

#endif //_INCLUDE_ITOOLKIT_MENUS_H