/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**	__DESCRIPTION__
*/
#include "../include/libmy.h"

static unsigned long long init__(unsigned long long **magic, void *cp,
	int c)
{
	unsigned long long bmagic;

	bmagic = 0xff & c;
	bmagic = (bmagic << 8) | bmagic;
	bmagic = (bmagic << 16) | bmagic;
	bmagic = ((bmagic << 16) << 16) | bmagic;
	*magic = (unsigned long long int *)cp;
	return (bmagic);
}

void *my_memset(void *mem, int c, size_t mlen)
{
	unsigned long long	bmagic;
	unsigned long long	*magic;
	unsigned char		*cp;

	magic = NULL;
	cp = (unsigned char *)mem;
	while (((unsigned long long)cp & (sizeof(bmagic) - 1)) && mlen) {
		*cp++ = c;
		--mlen;
	}
	if (mlen >= 8) {
		bmagic = init__(&magic, (void *)cp, c);
		while (mlen >= 8) {
			*magic++ = bmagic;
			mlen -= 8;
		}
	}
	cp = magic == NULL ? cp : (unsigned char *)magic;
	while (mlen--)
		*cp++ = c;
	return (mem);
}
