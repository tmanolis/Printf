/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:09:28 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/06 17:50:38 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t		ft_count_decimals(int nb)
{
	size_t count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

size_t		ft_count_hexa(unsigned int nb)
{
	size_t count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (8);
	while (nb != 0)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}