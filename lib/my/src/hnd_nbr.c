/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**	__DESCRIPTION__
*/


#include "my_printf.h"

void my_putnb(t_printf *p)
{
	int64_t	n;

	if (p->f & F_LONG || p->f & F_LONG2)
		n = (p->f & F_LONG2) ? ((int64_t)va_arg(p->ap, int64_t)) :
			((int64_t)va_arg(p->ap, long));
	else if (p->f & F_SHORT || p->f & F_SHORT2)
		n = (p->f & F_SHORT2) ? (int64_t)((char)va_arg(p->ap, int32_t)) :
			(int64_t)((int16_t)va_arg(p->ap, int32_t));
	else if (p->f & F_INTMAX)
		n = (va_arg(p->ap, int64_t));
	else if (p->f & F_SIZE_T)
		n = ((int64_t)va_arg(p->ap, ssize_t));
	else
		n = ((int64_t)va_arg(p->ap, int32_t));
	(p->f & F_ZERO) ? p->precision = p->min_length : 0;
	itoa_printf(n, p, 0);
}

void my_putnb_base(int base, t_printf *p)
{
	u_int64_t n;

	if (p->f & F_LONG || p->f & F_LONG2)
		n = (p->f & F_LONG2) ? ((int64_t)va_arg(p->ap, u_int64_t)) :
			((int64_t)va_arg(p->ap, unsigned long));
	else if (p->f & F_SHORT || p->f & F_SHORT2)
		n = (p->f & F_SHORT2) ? (u_int64_t)((wchar_t)va_arg(p->ap, int32_t))
			: (u_int64_t)((u_int16_t)va_arg(p->ap, int32_t));
	else if (p->f & F_INTMAX)
		n = (va_arg(p->ap, u_int64_t));
	else if (p->f & F_SIZE_T)
		n = ((u_int64_t)va_arg(p->ap, size_t));
	else
		n = (u_int64_t)va_arg(p->ap, u_int32_t);
	itoa_base_printf(n, base, p);
}

void itoa_printf(int64_t n, t_printf *p, int len)
{
	char		s[21];
	u_int64_t	tmp;

	tmp = ABS(n);
	while (tmp)
	{
		tmp /= 10;
		++len;
	}
	if ((n < 0 || p->f & F_PLUS || p->f & F_SPACE) && p->f & F_ZERO)
		--p->precision;
	p->printed = MAX(len, p->precision);
	if (n < 0 || p->f & F_PLUS || p->f & F_SPACE)
		++p->printed;
	p->padding = (p->printed > p->min_length) ? 0 : p->min_length - p->printed;
	padding(p, 0);
	tmp = ABS(n);
	itoa_base_fill(tmp, 10, s, p);
	(p->f & F_SPACE) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(p->f & F_PLUS && n >= 0) ? s[0] = '+' : 0;
	buffer(p, s, p->printed);
	padding(p, 1);
}

int itoa_base_printf_precision(t_printf *p, u_int64_t tmp, int b)
{
	p->printed = 0;
	while (tmp && ++p->printed)
		tmp /= b;
	(p->f & F_ZERO) ? p->precision = p->min_length : 0;
	return ((p->printed >= p->precision) ? 0 : 1);
}

void itoa_base_printf(u_int64_t n, int b, t_printf *p)
{
	char s[21];
	int ext = itoa_base_printf_precision(p, n, b);

	p->printed = MAX(p->precision, p->printed);
	((p->f & F_SHARP) && b == 8 && !ext) ? --p->min_length : 0;
	((p->f & F_SHARP) && b == 8 && !n && (p->f & F_APP_PRECI)) ?
	++p->printed : 0;
	((p->f & F_SHARP) && b == 16 && !(p->f & F_ZERO)) ? p->min_length -= 2 : 0;
	p->padding = MAX(0, (p->min_length - p->printed));
	padding(p, 0);
	if ((n || (p->f & F_POINTER))
		&& (p->f & F_SHARP) && ((b == 8 && !ext) || (b == 16)))
		buffer(p, "0", 1);
	if ((n || (p->f & F_POINTER)) && (p->f & F_SHARP) && b == 16)
		buffer(p, (p->f & F_UPCASE) ? "X" : "x", 1);
	itoa_base_fill(n, b, s, p);
	buffer(p, s, p->printed);
	padding(p, 1);
}

void itoa_base_fill(u_int64_t tmp, int b, char s[PF_BUF_SIZE], t_printf *p)
{
	int len;

	if (tmp && !(p->f & F_POINTER) && (p->f & F_ZERO) && (p->f & F_SHARP) &&
	b == 16 && !(p->f & F_LONG2) && p->printed > 3)
		p->printed -= 2;
	len = p->printed;
	p->c = 'a' - 10 - ((p->f & F_UPCASE) >> 1);
	while (len--) {
		s[len] = tmp % b + ((tmp % b < 10) ? '0' : p->c);
		tmp /= b;
	}
	(p->f & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0;
}
