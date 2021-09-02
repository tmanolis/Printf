/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:39:52 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/01 19:10:05 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	print_str(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (str)
		write(1, str, len);
	return (len);
}