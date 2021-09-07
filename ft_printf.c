/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:35:59 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/07 15:43:09 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_parse(const char *format, va_list args)
{
	if (*(format + 1) == 'c')
		return (print_char(va_arg(args, int)));
	if (*(format + 1) == 's')
		return (print_str(va_arg(args, char *)));
	if (*(format + 1) == 'p')
		return (print_address(va_arg(args, void *)));
	if (*(format + 1) == 'd' || (*(format + 1) == 'i'))
		return (print_nb(va_arg(args, int)));
	if (*(format + 1) == 'u')
		return (print_unsigned_nb(va_arg(args, unsigned int)));
	if (*(format + 1) == 'x')
		return (print_nb_base(va_arg(args, unsigned int), "0123456789abcdef"));
	if (*(format + 1) == 'X')
		return (print_nb_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (*(format + 1) == '%')
		return (print_char('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	written_char;
	size_t	returned_char;

	va_start(args, format);
	written_char = 0;
	while (*format != '\0')
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			written_char++;
		}
		else
		{
			returned_char = ft_parse(format, args);
			written_char = written_char + returned_char;
			format++;
		}
		format++;
	}
	va_end(args);
	return (written_char);
}
