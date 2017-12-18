/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**	__DESCRIPTION__
*/
#include "../include/libmy.h"

size_t my_wstrlen(unsigned *s)
{
	size_t len = 0;

	while (*s != L'\0') {
		len += my_wcharlen(*s);
		++s;
	}
	return (len);
}
