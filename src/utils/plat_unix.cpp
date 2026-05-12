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

#ifdef __linux__
	#include "dbg.h"
	#include "source2toolkit/utils/plat.h"
	#include "sys/mman.h"
	#include <dlfcn.h>
	#include <elf.h>
	#include <fcntl.h>
	#include <libgen.h>
	#include <link.h>
	#include <locale>
	#include <stdio.h>
	#include <string.h>
	#include <sys/stat.h>
	#include <sys/types.h>

	#include "tier0/memdbgon.h"

	#define PAGE_SIZE 4096
	#define PAGE_ALIGN_UP(x) ((x + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))

struct ModuleInfo
{
	const char* path; // in
	uint8_t* base;	  // out
	uint size;		  // out
};

// https://github.com/alliedmodders/sourcemod/blob/master/core/logic/MemoryUtils.cpp#L502-L587
// https://github.com/komashchenko/DynLibUtils/blob/5eb95475170becfcc64fd5d32d14ec2b76dcb6d4/module_linux.cpp#L95
static int parse_prot(const char* s)
{
	int prot = 0;

	for (; *s; s++)
	{
		switch (*s)
		{
			case '-':
				break;
			case 'r':
				prot |= PROT_READ;
				break;
			case 'w':
				prot |= PROT_WRITE;
				break;
			case 'x':
				prot |= PROT_EXEC;
				break;
			case 's':
				break;
			case 'p':
				break;
			default:
				break;
		}
	}

	return prot;
}

static int get_prot(void* pAddr, size_t nSize)
{
	FILE* f = fopen("/proc/self/maps", "r");

	uintptr_t nAddr = (uintptr_t)pAddr;

	char line[512];
	while (fgets(line, sizeof(line), f))
	{
		char start[16];
		char end[16];
		char prot[16];

		const char* src = line;

		char* dst = start;
		while (*src != '-')
			*dst++ = *src++;
		*dst = 0;

		src++; // skip "-""

		dst = end;
		while (!isspace(*src))
			*dst++ = *src++;
		*dst = 0;

		src++; // skip space

		dst = prot;
		while (!isspace(*src))
			*dst++ = *src++;
		*dst = 0;

		uintptr_t nStart = (uintptr_t)strtoul(start, nullptr, 16);
		uintptr_t nEnd = (uintptr_t)strtoul(end, nullptr, 16);

		if (nStart < nAddr && nEnd > (nAddr + nSize))
		{
			fclose(f);
			return parse_prot(prot);
		}
	}

	fclose(f);
	return 0;
}

void Plat_WriteMemory(void* pPatchAddress, uint8_t* pPatch, int iPatchSize)
{
	int old_prot = get_prot(pPatchAddress, iPatchSize);

	uintptr_t page_size = sysconf(_SC_PAGESIZE);
	uint8_t* align_addr = (uint8_t*)((uintptr_t)pPatchAddress & ~(page_size - 1));

	uint8_t* end = (uint8_t*)pPatchAddress + iPatchSize;
	uintptr_t align_size = end - align_addr;

	int result = mprotect(align_addr, align_size, PROT_READ | PROT_WRITE);

	memcpy(pPatchAddress, pPatch, iPatchSize);

	result = mprotect(align_addr, align_size, old_prot);
}
#endif