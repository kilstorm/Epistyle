/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**	__DESCRIPTION__
*/

#include "my_printf.h"

void color(t_printf *p)
{
	int len;

	p->printed = 5;
	if (!my_strncmp(p->format, "{red}", (len = 5)))
		buffer(p, PF_RED, p->printed);
	else if (!my_strncmp(p->format, "{green}", (len = 7)))
		buffer(p, PF_GREEN, p->printed);
	else if (!my_strncmp(p->format, "{yellow}", (len = 8)))
		buffer(p, PF_YELLOW, p->printed);
	else if (!my_strncmp(p->format, "{blue}", (len = 6)))
		buffer(p, PF_BLUE, p->printed);
	else if (!my_strncmp(p->format, "{purple}", (len = 8)))
		buffer(p, PF_PURPLE, p->printed);
	else if (!my_strncmp(p->format, "{cyan}", (len = 6)))
		buffer(p, PF_CYAN, p->printed);
	else if (!my_strncmp(p->format, "{eoc}", (len = 5)))
		buffer(p, PF_EOC, --p->printed);
	else if (!(len = 0))
		p->printed = 0;
	p->format += len - 1;
	p->len += p->printed;
}

static void ldtoa_fill(double n, t_printf *p, long value)
{
	int len = p->printed - 1 - p->precision;
	int accuracy = p->printed - 1 - len;
	char s[48];

	while (accuracy--) {
		s[len + accuracy + 1] = value % 10 + '0';
		value /= 10;
	}
	(p->precision > 0) ? s[len] = '.' : 0;
	value = (long)(ABS(n));
	while (++accuracy < len) {
		s[len - accuracy - 1] = value % 10 + '0';
		value /= 10;
	}
	(p->f & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0;
	(p->f & F_SPACE) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(p->f & F_PLUS && n >= 0) ? s[0] = '+' : 0;
	buffer(p, s, len + 1 + 6);
}

void my_putdouble(t_printf *p)
{
	double n = (double)va_arg(p->ap, double);
	long tmp = (long)(ABS(n));
	int len;
	double decimal;
	long value;

	(p->f & F_ZERO) ? p->precision = p->min_length : 0;
	if (!(p->f & F_APP_PRECI))
		p->precision = 6;
	len = (p->precision > 0) ? 1 : 0;
	while (tmp && ++len)
		tmp /= 10;
	(p->f & F_ZERO) ? p->precision = p->min_length : 0;
	p->printed = p->precision + len + ((n < 0) ? 1 : 0);
	decimal = ((n < 0.0f) ? -n : n);
	decimal = (decimal - (long)(((n < 0.0f) ? -n : n))) *
	my_pow(10, p->precision + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	value = (int)decimal;
	ldtoa_fill(n, p, value);
}

int my_dprintf(int fd, const char *format, ...)
{
	t_printf p;

	my_bzero(&p, sizeof(p));
	p.fd = fd;
	p.format = (char *)format;
	va_start(p.ap, format);
	while (*p.format) {
		if (*p.format == '%') {
			++p.format;
			if (!*p.format)
				break ;
			parse_optionals(&p);
		} else
			buffer(&p, p.format, 1);
		++p.format;
	}
	write(p.fd, p.buff, p.buffer_index);
	va_end(p.ap);
	return (p.len);
}
