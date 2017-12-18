/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**	__DESCRIPTION__
*/
#include "../include/libmy.h"

double my_pow(double n, int pow)
{
	return (pow ? n * my_pow(n, pow - 1) : 1);
}
