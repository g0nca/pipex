# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 14:10:40 by ggomes-v          #+#    #+#              #
#    Updated: 2024/11/12 15:59:52 by ggomes-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_hexadecimal.c ft_unsigned_int.c ft_putnbr.c ft_pointeraddress.c

NAME = libftprintf.a
PRIC = ar rcs
RM = rm -f 
OBJS = $(SRCS:.c=.o)
${NAME}:${OBJS}
		${PRIC} ${NAME} ${OBJS}
%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@
	
all:${NAME}
clean:
		${RM} ${OBJS}
fclean: clean
		${RM} ${NAME}
re: fclean all
.PHONY : all clean fclean re