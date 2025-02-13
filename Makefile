# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 13:11:58 by ggomes-v          #+#    #+#              #
#    Updated: 2025/02/11 14:31:04 by ggomes-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
MAKEFILES := $(wildcard */Makefile)  # Encontra os Makefiles nos subdiretórios
SRCS = pipex.c utils.c
LIBFTPRINTF = ft_printf/libftprintf.a  # Caminho para a biblioteca ft_printf
LIBFT = libft/libft.a

NAME = pipex
RM = rm -rf 
OBJS = $(SRCS:.c=.o)

all: $(NAME) $(LIBFTPRINTF) $(LIBFT) # Agora compila pipex e ft_printf

$(NAME): $(OBJS) $(LIBFTPRINTF) $(LIBFT) # Agora linkamos a biblioteca ft_printf
	@${CC} ${CFLAGS} ${OBJS} $(LIBFTPRINTF) $(LIBFT) -o ${NAME}
	@echo "	╔═════════════════════════════════════╗"
	@echo "	║ ✅ |${GREEN}All Files Compiled${RESET}     ║"
	@echo "	╚═════════════════════════════════════╝"

# Compilar os arquivos .c
%.o: %.c
	@echo "${GREEN}${BOLD}✅ | Compiling $<...${RESET}"
	@${CC} ${CFLAGS} -c $< -o $@

$(LIBFT): libft/Makefile
	@$(MAKE) -C libft
# Compila a biblioteca ft_printf se necessário
$(LIBFTPRINTF): ft_printf/Makefile
	@$(MAKE) -C ft_printf

# Executar os Makefiles nos subdiretórios (caso tenha mais)
$(MAKEFILES):
	@$(MAKE) -C $(dir $@)

clean:
	@${RM} ${OBJS} 
	@$(MAKE) -C ft_printf clean
	@echo "	╔═════════════════════════════════════╗"
	@echo "	║ 🗑️  |${BOLD}Cleaned Successfully!${RESET}   ║"
	@echo "	╚═════════════════════════════════════╝"

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C ft_printf fclean
	@$(MAKE) -C libft fclean
	@echo "	╔═════════════════════════════════════╗"
	@echo "	║ 🗑️  |${CYAN}Full Clean Done!${RESET}    ║"
	@echo "	╚═════════════════════════════════════╝"

re: fclean all

.PHONY: all clean fclean re

RESET = \033[0m      
BOLD = \033[1m  
RED = \033[31m      
GREEN = \033[32m   
YELLOW = \033[33m  
BLUE = \033[34m     
MAGENTA = \033[35m   
CYAN = \033[36m      
WHITE = \033[37m
