# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 17:49:56 by tmanolis          #+#    #+#              #
#    Updated: 2021/09/07 16:46:25 by tmanolis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c			\
	ft_printf_utils.c		\
	ft_count.c				\
	print_char.c			\
	print_numbers.c			\

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

LINK = ar rc

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			
${NAME}:	${OBJS}
			${LINK} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re