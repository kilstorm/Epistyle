//
// EPITECH PROJECT, 2017
// my_printf
// File description:
//	__DESCRIPTION__
//


#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include "../lib/include/libmy.h"
#include <stdarg.h>
#include <errno.h>
#include <stdio.h>

/*
** -------------------------- Macros Definition --------------------------------
*/

#define MAX(a, b)		b & ((a - b) >> 31) || a & (~(a - b) >> 31)
#define MIN(a, b)		a & ((a - b) >> 31) || b & (~(a - b) >> 31)
#define ABS(a)			(a < 0) ? -a : a
#define DABS(a)			(a < 0.0f) ? -a : a
#define STRERR			strerror

/*
** -------------------------- Colors Definition --------------------------------
*/

# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[0m"

/*
** --------------------------- Masks Definition --------------------------------
*/

#define F_SHARP (1 << 0)
#define F_SPACE (1 << 1)
#define F_PLUS (1 << 2)
#define F_MINUS (1 << 3)
#define F_ZERO (1 << 4)
#define F_WILDCARD (1 << 5)
#define F_UPCASE (1 << 6)
#define F_SHORT (1 << 7)
#define F_SHORT2 (1 << 8)
#define F_LONG (1 << 9)
#define F_LONG2 (1 << 10)
#define F_INTMAX (1 << 11)
#define F_SIZE_T (1 << 12)
#define F_MIN_LEN (1 << 13)
#define F_APP_PRECI (1 << 14)
#define F_POINTER (1 << 15)
#define PF_BUF_SIZE 64

typedef struct s_printf {
	int len;
	short f;
	short n;
	int min_length;
	int precision;
	int padding;
	int printed;
	int fd;
	int buffer_index;
	char buff[PF_BUF_SIZE];
	va_list ap;
	char *format;
	unsigned c;
} t_printf;

int my_printf(const char *format, ...);
int my_dprintf(int fd, const char *format, ...);
void parse_optionals(t_printf *p);
void cs_not_found(t_printf *p);
void my_putnb(t_printf *p);
void my_putnb_base(int base, t_printf *p);
void itoa_printf(int64_t d, t_printf *p, int len);
void itoa_base_printf(u_int64_t d, int b, t_printf *p);
void itoa_base_fill(u_int64_t tmp, int base, char *str,
	t_printf *p);
void my_putstr(t_printf *p);
void my_putwstr(t_printf *p);
void my_character(t_printf *p, unsigned c);
void my_printf_putstr(char *s, t_printf *p);
void my_putwchar(t_printf *p, unsigned int w, int wl, int n);
void print_pointer_address(t_printf *p);
void color(t_printf *p);
void my_putdouble(t_printf *p);
void buffer(t_printf *p, void *new_elem, size_t size);
void buffer_flush(t_printf *p);
void padding(t_printf *p, int n);

#endif
