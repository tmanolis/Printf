/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:40:28 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/01 19:01:55 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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