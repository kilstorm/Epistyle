/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**	__DESCRIPTION__
*/
#include "my_printf.h"

void parse_flags(t_printf *p)
{
	while ((p->n = my_strchri("# +-0*", *p->format, -1)) > -1 && ++p->format)
		p->f |= (1 << p->n);
	((p->f & F_MINUS) && !(p->f & F_WILDCARD)) ? p->f &= ~F_ZERO : 0;
	(p->f & F_PLUS) ? p->f &= ~F_SPACE : 0;
	if (p->f & F_WILDCARD) {
		p->f &= ~F_WILDCARD;
		if ((p->n = (int)va_arg(p->ap, int)) < 0) {
			p->f |= F_MINUS;
			p->n = -p->n;
		} else
			p->f &= ~F_MINUS;
		if (!(p->f & F_APP_PRECI))
			p->min_length = p->n;
		else {
			p->precision = (!(p->f & F_MINUS)) ? p->n : 0;
			p->f = (!p->n) ? p->f | F_APP_PRECI : p->f & ~F_APP_PRECI;
		}
	}
}

void field_width_precision(t_printf *p)
{
	if (48 < *p->format && *p->format < 58) {
		p->min_length = MAX(1, my_atoi(p->format));
		while (47 < *p->format && *p->format < 58)
			++p->format;
	}
	if (*p->format == '.') {
		++p->format;
		p->precision = MAX(my_atoi(p->format), 0);
		while (47 < *p->format && *p->format < 58)
			++p->format;
		p->f |= F_APP_PRECI;
	}
}

void conversion_specifier(t_printf *p)
{
	p->c = *p->format;
	if (p->c == 's')
		(p->f & F_LONG || p->f & F_LONG2) ? my_putwstr(p) : my_putstr(p);
	else if (my_strchr("dDi", p->c))
		my_putnb(p);
	else if (p->c == 'f' || p->c == 'F')
		(p->f & F_APP_PRECI && !p->precision) ? my_putnb(p) : my_putdouble(p);
	else if (p->c == 'c' || p->c == 'C')
		my_character(p, va_arg(p->ap, unsigned));
	else if (my_strchr("oOuUbBxX", p->c))
		my_putnb_base(my_strchri_lu(".b..ou..x", p->c, -1) << 1, p);
	else if (p->c == 'S')
		my_putwstr(p);
	else if (p->c == 'p')
		print_pointer_address(p);
	else if (p->c == 'n')
		*va_arg(p->ap, int *) = p->len;
	else if (p->c == 'm')
		my_printf_putstr(STRERR(errno), p);
	else if (p->c == '{')
		color(p);
	else
		cs_not_found(p);
}

void parse_optionals(t_printf *p)
{
	p->f = 0;
	p->min_length = 0;
	p->precision = 1;
	parse_flags(p);
	field_width_precision(p);
	while (42) {
		if (*p->format == 'l')
			p->f |= (p->format[1] == 'l' && ++p->format) ? F_LONG2 : F_LONG;
		else if (*p->format == 'h')
			p->f |= (p->format[1] == 'h' && ++p->format) ? F_SHORT2 : F_SHORT;
		else if (*p->format == 'j')
			p->f |= F_INTMAX;
		else if (*p->format == 'z')
			p->f |= F_SIZE_T;
		else
			break ;
		++p->format;
	}
	parse_flags(p);
	(p->f & F_PLUS) ? p->f &= ~F_SPACE : 0;
	if (my_strchr("CDSUOBX", *p->format))
		p->f |= (*p->format != 'X') ? F_LONG : F_UPCASE;
	conversion_specifier(p);
}

void cs_not_found(t_printf *p)
{
	if ((p->padding = p->min_length - 1) > 0) {
		padding(p, 0);
		buffer(p, p->format, 1);
		padding(p, 1);
		return ;
	}
	buffer(p, p->format, 1);
}
