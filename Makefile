# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 14:36:07 by vopekdas          #+#    #+#              #
#    Updated: 2024/01/21 17:10:29 by vopekdas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIGHT_RED=\033[1;31m
LIGHT_GREEN=\033[1;32m
LIGHT_YELLOW=\033[1;33m
LIGHT_BLUE=\033[1;34m
LIGHT_MAGENTA=\033[1;35m
LIGHT_CYAN=\033[1;36m
WHITE=\033[1;37m
LIGHT_GRAY=\033[0;37m
DARK_GRAY=\033[1;30m
LIGHT_PURPLE=\033[1;35m

NAME = pipex

SOURCES = main.c \
		path_utils.c \
		checking_errors.c \
		exec_cmd_utils.c \

LIBFT_PATH = Libft

FT_PRINTF_PATH = ft_printf

OBJECTS = $(SOURCES:.c=.o)

CC=cc

CFLAGS=-Wall -Wextra -Werror -g3 -Iinclude

RM = rm -f

.PHONY: all clean fclean re libft ft_printf

all: libft ft_printf $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -LLibft -lft -Lft_printf -lftprintf

libft: 
	@printf "$(LIGHT_BLUE)Starting compilation...\n\033[0m"
	@printf "$(LIGHT_RED)  _      _____ _      __ _   \n"
	@printf "$(LIGHT_YELLOW) | |    |_   _| |    / _| |  \n"
	@printf "$(LIGHT_GREEN) | |      | | | |__ | |_| |_ \n"
	@printf "$(LIGHT_BLUE) | |      | | | '_ \|  _| __|\n"
	@printf "$(LIGHT_MAGENTA) | |____ _| |_| |_) | | | |_ \n"
	@printf "$(LIGHT_CYAN) |______|_____|_.__/|_|  \__|\n\033[0m"
	@echo "$(LIGHT_CYAN)"
	$(MAKE) -C $(LIBFT_PATH)
	@printf "$(LIGHT_GREEN)Compilation completed successfully.\n\033[0m"

ft_printf: 
	@printf "$(LIGHT_BLUE)Starting compilation...\n\033[0m"
	@printf "$(LIGHT_RED)   __ _                  _       _    __ \n"
	@printf "$(LIGHT_YELLOW)  / _| |                (_)     | |  / _|\n"
	@printf "$(LIGHT_GREEN) | |_| |_     _ __  _ __ _ _ __ | |_| |_ \n"
	@printf "$(LIGHT_BLUE) |  _| __|   | '_ \| '__| | '_ \| __|  _|\n"
	@printf "$(LIGHT_MAGENTA) | | | |_    | |_) | |  | | | | | |_| |  \n"
	@printf "$(LIGHT_CYAN) |_|  \__|   | .__/|_|  |_|_| |_|\__|_|  \n"
	@printf "$(WHITE)       ______| |                         \n"
	@printf "$(DARK_GRAY)      |______|_|                         \n\033[0m"
	@echo "$(LIGHT_CYAN)"
	$(MAKE) -C $(FT_PRINTF_PATH)
	@printf "$(LIGHT_GREEN)Compilation completed successfully.\n\033[0m"


clean:
	@echo "$(LIGHT_PURPLE)"
	$(RM) $(OBJECTS)
	cd $(LIBFT_PATH) && make clean
	cd $(FT_PRINTF_PATH) && make clean
	@printf "$(LIGHT_RED)Cleaned all object files.\n\033[0m"

fclean: clean
	@echo "$(LIGHT_PURPLE)"
	$(RM) $(NAME)
	cd $(LIBFT_PATH) && make fclean
	cd $(FT_PRINTF_PATH) && make fclean
	@printf "$(LIGHT_RED)Cleaned all object files.\n\033[0m"

re: fclean all