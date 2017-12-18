/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**	__DESCRIPTION__
*/
#include "../include/libmy.h"

void my_bzero(void *s, size_t n)
{
	if (n)
		my_memset(s, 0, n);
}
