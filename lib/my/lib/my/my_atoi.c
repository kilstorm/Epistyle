/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**	__DESCRIPTION__
*/
#include "../include/libmy.h"

int my_atoi(char *s)
{
	long r = 0;
	int sign = 1;
	
	if (*s == '-' || *s == '+')
		sign = 44 - *s++;
	while (*s >= '0' && *s <= '9')
		r = r * 10 + *s++ - '0';
	return (sign * (int)r);
}
