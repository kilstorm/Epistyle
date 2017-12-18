/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**	__DESCRIPTION__
*/
#include "../include/libmy.h"
#include <string.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
	char *s = (char *)src;
	char *d = (char *)dest;

	while (n--)
		d[n] = s[n];
	return (dest);
}
