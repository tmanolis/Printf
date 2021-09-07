/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:40:28 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/07 16:38:15 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_nb(int n)
{
	unsigned int	nb;

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

size_t	print_unsigned_nb(unsigned int nb)
{
	unsigned int	n;

	n = nb;
	if (nb > 9)
	{
		print_nb(nb / 10);
	}
	ft_putchar((nb % 10 + 48));
	return (ft_count_decimals_unsigned((unsigned int)nb));
}

size_t	print_nb_base(unsigned long int nb, char *base)
{
	if (nb > 15)
	{
		print_nb_base(nb / 16, base);
	}
	ft_putchar(base[nb % 16]);
	return (ft_count_hexa(nb));
}

size_t	print_address(void *ptr)
{
	uintptr_t	nb;
	size_t		count;	

	nb = (uintptr_t)ptr;
	write(1, "0x", 2);
	count = 2 + print_nb_base(nb, "0123456789abcdef");
	return (count);
}
