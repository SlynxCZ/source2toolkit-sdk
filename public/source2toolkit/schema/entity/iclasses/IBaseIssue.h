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

#ifndef _INCLUDE_IBASEISSUE_H
#define _INCLUDE_IBASEISSUE_H

#pragma once

#include <cstdint>

class CVoteController;

class IBaseIssue
{
public:
    virtual ~IBaseIssue() = default;

    virtual char* TypeString() = 0;
    virtual char* DetailsString() = 0;
    virtual int32_t& NumYesVotes() = 0;
    virtual void NumYesVotesUpdated() = 0;
    virtual int32_t& NumNoVotes() = 0;
    virtual void NumNoVotesUpdated() = 0;
    virtual int32_t& NumPotentialVotes() = 0;
    virtual void NumPotentialVotesUpdated() = 0;
    virtual CVoteController*& VoteController() = 0;
    virtual void VoteControllerUpdated() = 0;
};

#endif // _INCLUDE_IBASEISSUE_H
