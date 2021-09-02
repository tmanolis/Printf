/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:35:59 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/01 19:11:11 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_parse(const char *format, va_list args)
{
	if (*(format + 1) == 'c')
		return (print_char((char)va_arg(args, int)));
	if (*(format + 1) == 's')
		return (print_str((char *)va_arg(args, char *)));	
	// if (*(format + 1) == 'p')
	// 	// print_char((void *)va_arg(args, void *));
	if (*(format + 1) == 'd' || (*(format + 1) == 'i'))
		return (print_nb((int)va_arg(args, int)));
	if (*(format + 1) == 'u')
		return (print_char((char)va_arg(args, int)));
	if (*(format + 1) == 'x')
		return (print_char((char)va_arg(args, int)));
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
			if (returned_char != 0)
			{
				written_char = written_char + returned_char;
				format++;
			}
		}
		format++;
	}
	va_end(args);
	printf("%zu\n", written_char);
	return(written_char);
}

int	main(void)
{
	char c = 'F';
	char *str = "Test";
	int nb = 1234;
	ft_printf("coucou %c %s %d %%\n", c, str, nb);
	printf("coucou %c %s %d %%\n", c, str, nb);
}