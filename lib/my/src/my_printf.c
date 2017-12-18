/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**	__DESCRIPTION__
*/
#include "my_printf.h"

int my_printf(const char *format, ...)
{
	t_printf print;

	my_bzero(&print, sizeof(print));
	print.fd = 1;
	print.format = (char*)format;
	va_start(print.ap, format);
	while (*print.format){
		if (*print.format == '%'){
			++print.format;
			if (*print.format == '\0')
				break;
			parse_optionals(&print);
		} else
			buffer(&print, print.format, 1);
		++print.format;
	}
	write(print.fd, print.buff, print.buffer_index);
	va_end(print.ap);
	return (print.len);
}

void buffer(t_printf *print, void *new, size_t size)
{
	int diff;
	int64_t new_i = 0;

	while (PF_BUF_SIZE - print->buffer_index < (int)size) {
		diff = PF_BUF_SIZE - print->buffer_index;
		my_memcpy(&(print->buff[print->buffer_index]), &(new[new_i]), diff);
		size -= diff;
		new_i += diff;
		print->buffer_index += diff;
		print->len += diff;
		write(print->fd, print->buff, print->buffer_index);
		print->buffer_index = 0;
	}
	my_memcpy(&(print->buff[print->buffer_index]), &(new[new_i]), size);
	print->buffer_index += size;
	print->len += size;
}

void print_pointer_address(t_printf *print)
{
	void	*pointer;

	pointer = va_arg(print->ap, void *);
	print->f &= ~F_SHARP;
	print->min_length -= (print->f & F_ZERO ? 2 : 0);
	print->padding = (print->printed > print->min_length - 3) ? 0 :
		print->min_length - 3 - print->printed;
	print->f |= F_SHARP;
	print->f |= F_POINTER;
	itoa_base_printf((u_int64_t)pointer, 16, print);
}

void padding(t_printf *print, int n)
{
	if (!print->padding)
		return ;
	print->c = 32 | (print->f & F_ZERO);
	if (!n && !(print->f & F_MINUS))
		while (print->padding--)
			buffer(print, &print->c, 1);
	else if (n && (print->f & F_MINUS))
		while (print->padding--)
			buffer(print, &print->c, 1);
}
