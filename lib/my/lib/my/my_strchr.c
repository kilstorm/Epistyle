/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**	__DESCRIPTION__
*/
#include "../include/libmy.h"

char *my_strchr(const char *s, int c)
{
	return (my_memchr(s, c, my_strlen(s) + 1));
}
