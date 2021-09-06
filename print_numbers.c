/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:40:28 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/06 17:51:00 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	print_nb(int n)
{
	unsigned	nb;

	if (n < 0)
	{
		nb = n * -1;
		ft_putchar('-');
	}
	else
		nb = n;
	if (nb > 9)
	{
		print_nb(nb / 10);
	}
	ft_putchar((nb % 10 + 48));
	return (ft_count_decimals(n));
}

size_t	print_nb_base(unsigned int nb, char *base)
{
	if (nb > 15)
	{
		print_nb_base(nb / 16, base);
	}
	ft_putchar(base[nb % 16]);
	return (ft_count_hexa(nb));
}