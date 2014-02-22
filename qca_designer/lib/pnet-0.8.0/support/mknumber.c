/*
 * mknumber.c - Make the Unicode numeric value table from UnicodeData.txt.
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdio.h>
#include <stdlib.h>
#include "il_system.h"
#include "il_utils.h"

#ifdef	__cplusplus
extern	"C" {
#endif

#if defined(__palmos__)

int main(int argc, char *argv[])
{
	return 0;
}

#else

/*
 * Full category table.
 */
static double value[65536];

int main(int argc, char *argv[])
{
	char buffer[BUFSIZ];
	unsigned long startch;
	unsigned long ch;
	char *ptr;
	char *catName;
	char *numValue;
	int outIfDef;
	int hasSlash;

	/* Initialize the value table to all unassigned */
	for(ch = 0; ch < 65536; ++ch)
	{
		value[ch] = (double)(-1.0);
	}

	/* Process UnicodeData.txt to get the category information */
	startch = 0;
	while(fgets(buffer, sizeof(buffer), stdin))
	{
		ptr = buffer;

		/* Parse the character value */
		ch = 0;
		while(*ptr != '\0' && *ptr != ';')
		{
			if(*ptr >= '0' && *ptr <= '9')
			{
				ch = (ch * 16) + (*ptr - '0');
			}
			else if(*ptr >= 'A' && *ptr <= 'F')
			{
				ch = (ch * 16) + (*ptr - 'A' + 10);
			}
			else if(*ptr >= 'a' && *ptr <= 'f')
			{
				ch = (ch * 16) + (*ptr - 'a' + 10);
			}
			else
			{
				fprintf(stderr, "Bad character value in input\n");
				return 1;
			}
			++ptr;
		}
		if(*ptr != ';')
		{
			continue;
		}

		/* Skip the character if not within the 16-bit range */
		if(ch >= 0x10000)
		{
			startch = ch + 1;
			continue;
		}

		/* Find the category name */
		++ptr;
		while(*ptr != '\0' && *ptr != ';')
		{
			++ptr;
		}
		if(*ptr == ';')
		{
			++ptr;
		}
		catName = ptr;
		while(*ptr != '\0' && *ptr != ';')
		{
			++ptr;
		}
		if(*ptr == ';')
		{
			++ptr;
		}

		/* Skip if not a numeric category */
		if(catName[0] != 'N')
		{
			continue;
		}

		/* If the character name ended in ", Last>", then ignore
		   the character range */
		if((catName - buffer) > 8 && !strncmp(catName - 8, ", Last>", 7))
		{
			continue;
		}

		/* Find the numeric value field */
		while(*ptr != '\0' && *ptr != ';')
		{
			++ptr;
		}
		if(*ptr == ';')
		{
			++ptr;
		}
		while(*ptr != '\0' && *ptr != ';')
		{
			++ptr;
		}
		if(*ptr == ';')
		{
			++ptr;
		}
		while(*ptr != '\0' && *ptr != ';')
		{
			++ptr;
		}
		if(*ptr == ';')
		{
			++ptr;
		}
		while(*ptr != '\0' && *ptr != ';')
		{
			++ptr;
		}
		if(*ptr == ';')
		{
			++ptr;
		}
		while(*ptr != '\0' && *ptr != ';')
		{
			++ptr;
		}
		if(*ptr == ';')
		{
			++ptr;
		}
		numValue = ptr;
		hasSlash = 0;
		while(*ptr != '\0' && *ptr != ';')
		{
			if(*ptr == '/')
			{
				hasSlash = (int)(ptr + 1 - numValue);
			}
			++ptr;
		}
		ptr[0] = '\0';
		if(numValue[0] == '\0')
		{
			continue;
		}

		/* Set the numeric value */
		if(hasSlash)
		{
			/* This is a fractional value */
			numValue[hasSlash - 1] = '\0';
			value[ch] = (double)(atoi(numValue)) /
						(double)(atoi(numValue + hasSlash));
		}
		else
		{
			/* This is a regular value */
			value[ch] = (double)(atoi(numValue));
		}
	}

	/* Write out the value details */
	printf("/* This file is automatically generated - do not edit */\n");
	printf("struct ILUniNumInfo\n");
	printf("{\n");
	printf("\tunsigned ch;\n");
	printf("\tdouble   value;\n");
	printf("};\n");
	printf("static struct ILUniNumInfo const charValues[] = {\n");
	outIfDef = 0;
	for(ch = 0; ch < 65536; ++ch)
	{
		if(value[ch] == (double)(-1.0))
		{
			continue;
		}
		if(!outIfDef && ch >= 0x100)
		{
			printf("#ifndef SMALL_UNICODE_TABLE\n");
			outIfDef = 1;
		}
		printf("\t{0x%04X, %.15g},\n", (unsigned)ch, (double)(value[ch]));
	}
	printf("#endif\n");
	printf("};\n");

	/* Done */
	return 0;
}

#endif

#ifdef	__cplusplus
};
#endif
