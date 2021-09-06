/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:39:34 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/06 17:51:32 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(const char *str);
void	ft_putchar(char c);
size_t	ft_count_decimals(int nb);
size_t	ft_count_hexa(unsigned int nb);
size_t	print_char(char c);
size_t	print_str(char *str);
size_t	print_nb(int n);
size_t	print_nb_base(unsigned int nb, char *base);


#endif