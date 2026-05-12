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

#ifndef _INCLUDE_VMIXGRAPHCOMMANDID_T_H
#define _INCLUDE_VMIXGRAPHCOMMANDID_T_H

#pragma once

#include <cstdint>

enum class VMixGraphCommandID_t : int32_t
{
    CMD_INVALID = -1,
    CMD_CONTROL_INPUT_STORE = 1,
    CMD_CONTROL_INPUT_STORE_DB = 2,
    CMD_CONTROL_TRANSIENT_INPUT_STORE = 3,
    CMD_CONTROL_TRANSIENT_INPUT_RESET = 4,
    CMD_CONTROL_OUTPUT_STORE = 5,
    CMD_CONTROL_EVALUATE_CURVE = 6,
    CMD_CONTROL_COPY = 7,
    CMD_CONTROL_COND_COPY_IF_NEGATIVE = 8,
    CMD_CONTROL_REMAP_LINEAR = 9,
    CMD_CONTROL_REMAP_SINE = 10,
    CMD_CONTROL_REMAP_LOGLINEAR = 11,
    CMD_CONTROL_MAX = 12,
    CMD_CONTROL_RESET_TIMER = 13,
    CMD_CONTROL_INCREMENT_TIMER = 14,
    CMD_CONTROL_EVAL_ENVELOPE = 15,
    CMD_CONTROL_SINE_BLEND = 16,
    CMD_PROCESSOR_SET_CONTROL_VALUE = 17,
    CMD_PROCESSOR_SET_NAME_INPUT = 18,
    CMD_PROCESSOR_SET_CONTROL_ARRAYVALUE = 19,
    CMD_PROCESSOR_STORE_CONTROL_VALUE = 20,
    CMD_PROCESSOR_SET_VSND_VALUE = 21,
    CMD_SUBMIX_PROCESS = 22,
    CMD_SUBMIX_GENERATE = 23,
    CMD_SUBMIX_GENERATE_SIDECHAIN = 24,
    CMD_SUBMIX_DEBUG = 25,
    CMD_SUBMIX_MIX2x1 = 26,
    CMD_SUBMIX_OUTPUT = 27,
    CMD_SUBMIX_OUTPUTx2 = 28,
    CMD_SUBMIX_COPY = 29,
    CMD_SUBMIX_ACCUMULATE = 30,
    CMD_SUBMIX_METER = 31,
    CMD_SUBMIX_METER_SPECTRUM = 32,
    CMD_IMPULSERESPONSE_INPUT_STORE = 33,
    CMD_PROCESSOR_SET_IMPULSERESPONSE_VALUE = 34,
    CMD_REMAP_VSND_TO_IMPULSERESPONSE = 35,
    CMD_IMPULSERESPONSE_RESET = 36,
    CMD_BLEND_VSNDS_TO_IMPULSERESPONSE = 37,
    CMD_IMPULSERESPONSE_DELAY = 38,
};

#endif // _INCLUDE_VMIXGRAPHCOMMANDID_T_H
