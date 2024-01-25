# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 14:36:07 by vopekdas          #+#    #+#              #
#    Updated: 2024/01/25 14:56:08 by vopekdas         ###   ########.fr        #
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
		exec_cmd_utils.c \
		free_functions.c \
		error_message.c \
		handle_here_doc.c \

BONUS_SOURCES = path_utils.c \
		exec_cmd_utils.c \
		free_functions.c \
		error_message.c \
		handle_here_doc.c \
		main_bonus.c \

LIBFT_PATH = Libft

FT_PRINTF_PATH = ft_printf

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CC=cc

CFLAGS=-Wall -Wextra -Werror -g3

RM = rm -f

.PHONY: all clean fclean re libft ft_printf

all: libft ft_printf $(NAME)
	@echo "$(LIGHT_CYAN)"
	@printf "$(LIGHT_CYAN)██████╗ $(LIGHT_BLUE)██╗$(LIGHT_CYAN)██████╗ $(LIGHT_BLUE)███████╗$(LIGHT_CYAN)██╗  ██╗\n"
	@printf "$(LIGHT_CYAN)██╔══██╗$(LIGHT_BLUE)██║$(LIGHT_CYAN)██╔══██╗$(LIGHT_BLUE)██╔════╝$(LIGHT_CYAN)╚██╗██╔╝\n"
	@printf "$(LIGHT_CYAN)██████╔╝$(LIGHT_BLUE)██║$(LIGHT_CYAN)██████╔╝$(LIGHT_BLUE)█████╗  $(LIGHT_CYAN) ╚███╔╝ \n"
	@printf "$(LIGHT_CYAN)██╔═══╝ $(LIGHT_BLUE)██║$(LIGHT_CYAN)██╔═══╝ $(LIGHT_BLUE)██╔══╝  $(LIGHT_CYAN) ██╔██╗ \n"
	@printf "$(LIGHT_CYAN)██║     $(LIGHT_BLUE)██║$(LIGHT_CYAN)██║     $(LIGHT_BLUE)███████╗$(LIGHT_CYAN)██╔╝ ██╗\n"
	@printf "$(LIGHT_CYAN)╚═╝     $(LIGHT_BLUE)╚═╝$(LIGHT_CYAN)╚═╝     $(LIGHT_BLUE)╚══════╝$(LIGHT_CYAN)╚═╝  ╚═╝\n"
	@printf "$(LIGHT_GREEN)Compilation completed successfully.\n\033[0m"

$(NAME): $(OBJECTS)
	@printf "$(LIGHT_BLUE)Starting compilation...\n\033[0m"
	@echo "$(LIGHT_CYAN)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -LLibft -lft -Lft_printf -lftprintf

libft: 
	@printf "$(LIGHT_BLUE)Starting compilation...\n\033[0m"
	@echo "$(LIGHT_CYAN)"
	@printf "$(LIGHT_CYAN)██╗     $(LIGHT_BLUE)██╗$(LIGHT_CYAN)██████╗ $(LIGHT_BLUE)███████╗$(LIGHT_CYAN)████████╗\n"
	@printf "$(LIGHT_CYAN)██║     $(LIGHT_BLUE)██║$(LIGHT_CYAN)██╔══██╗$(LIGHT_BLUE)██╔════╝$(LIGHT_CYAN)╚══██╔══╝\n"
	@printf "$(LIGHT_CYAN)██║     $(LIGHT_BLUE)██║$(LIGHT_CYAN)██████╔╝$(LIGHT_BLUE)█████╗  $(LIGHT_CYAN)   ██║   \n"
	@printf "$(LIGHT_CYAN)██║     $(LIGHT_BLUE)██║$(LIGHT_CYAN)██╔══██╗$(LIGHT_BLUE)██╔══╝  $(LIGHT_CYAN)   ██║   \n"
	@printf "$(LIGHT_CYAN)███████╗$(LIGHT_BLUE)██║$(LIGHT_CYAN)██████╔╝$(LIGHT_BLUE)██║     $(LIGHT_CYAN)   ██║   \n"
	@printf "$(LIGHT_CYAN)╚══════╝$(LIGHT_BLUE)╚═╝$(LIGHT_CYAN)╚═════╝ $(LIGHT_BLUE)╚═╝     $(LIGHT_CYAN)   ╚═╝   \n"
	$(MAKE) -C $(LIBFT_PATH)
	@printf "$(LIGHT_GREEN)Compilation completed successfully.\n\033[0m"

ft_printf: 
	@printf "$(LIGHT_BLUE)Starting compilation...\n\033[0m"
	@printf "$(LIGHT_BLUE)███████╗$(LIGHT_CYAN)████████╗$(LIGHT_BLUE)     $(LIGHT_CYAN)██████╗ $(LIGHT_BLUE)██████╗ $(LIGHT_CYAN)██╗$(LIGHT_BLUE)███╗   ██╗$(LIGHT_CYAN)████████╗$(LIGHT_BLUE)███████╗\n"
	@printf "$(LIGHT_BLUE)██╔════╝$(LIGHT_CYAN)╚══██╔══╝$(LIGHT_BLUE)     $(LIGHT_CYAN)██╔══██╗$(LIGHT_BLUE)██╔══██╗$(LIGHT_CYAN)██║$(LIGHT_BLUE)████╗  ██║$(LIGHT_CYAN)╚══██╔══╝$(LIGHT_BLUE)██╔════╝\n"
	@printf "$(LIGHT_BLUE)█████╗  $(LIGHT_CYAN)   ██║   $(LIGHT_BLUE)     $(LIGHT_CYAN)██████╔╝$(LIGHT_BLUE)██████╔╝$(LIGHT_CYAN)██║$(LIGHT_BLUE)██╔██╗ ██║$(LIGHT_CYAN)   ██║   $(LIGHT_BLUE)█████╗  \n"
	@printf "$(LIGHT_BLUE)██╔══╝  $(LIGHT_CYAN)   ██║   $(LIGHT_BLUE)     $(LIGHT_CYAN)██╔═══╝ $(LIGHT_BLUE)██╔══██╗$(LIGHT_CYAN)██║$(LIGHT_BLUE)██║╚██╗██║$(LIGHT_CYAN)   ██║   $(LIGHT_BLUE)██╔══╝  \n"
	@printf "$(LIGHT_BLUE)██║     $(LIGHT_CYAN)   ██║███$(LIGHT_BLUE)████╗$(LIGHT_CYAN)██║     $(LIGHT_BLUE)██║  ██║$(LIGHT_CYAN)██║$(LIGHT_BLUE)██║ ╚████║$(LIGHT_CYAN)   ██║   $(LIGHT_BLUE)██║     \n"
	@printf "$(LIGHT_BLUE)╚═╝     $(LIGHT_CYAN)   ╚═╝╚══$(LIGHT_BLUE)════╝$(LIGHT_CYAN)╚═╝     $(LIGHT_BLUE)╚═╝  ╚═╝$(LIGHT_CYAN)╚═╝$(LIGHT_BLUE)╚═╝  ╚═══╝$(LIGHT_CYAN)   ╚═╝   $(LIGHT_BLUE)╚═╝     \n"
	@echo "$(LIGHT_CYAN)"
	$(MAKE) -C $(FT_PRINTF_PATH)
	@printf "$(LIGHT_GREEN)Compilation completed successfully.\n\033[0m"

bonus: $(BONUS_OBJECTS) libft ft_printf
	@printf "$(LIGHT_BLUE)Starting compilation...\n\033[0m"
	@printf "$(LIGHT_PURPLE)██████╗ $(LIGHT_CYAN) ██████╗ $(LIGHT_PURPLE)███╗   ██╗$(LIGHT_CYAN)██╗   ██╗$(LIGHT_PURPLE)███████╗\n"
	@printf "$(LIGHT_PURPLE)██╔══██╗$(LIGHT_CYAN)██╔═══██╗$(LIGHT_PURPLE)████╗  ██║$(LIGHT_CYAN)██║   ██║$(LIGHT_PURPLE)██╔════╝\n"
	@printf "$(LIGHT_PURPLE)██████╔╝$(LIGHT_CYAN)██║   ██║$(LIGHT_PURPLE)██╔██╗ ██║$(LIGHT_CYAN)██║   ██║$(LIGHT_PURPLE)███████╗\n"
	@printf "$(LIGHT_PURPLE)██╔══██╗$(LIGHT_CYAN)██║   ██║$(LIGHT_PURPLE)██║╚██╗██║$(LIGHT_CYAN)██║   ██║$(LIGHT_PURPLE)╚════██║\n"
	@printf "$(LIGHT_PURPLE)██████╔╝$(LIGHT_CYAN)╚██████╔╝$(LIGHT_PURPLE)██║ ╚████║$(LIGHT_CYAN)╚██████╔╝$(LIGHT_PURPLE)███████║\n"
	@printf "$(LIGHT_PURPLE)╚═════╝ $(LIGHT_CYAN) ╚═════╝ $(LIGHT_PURPLE)╚═╝  ╚═══╝$(LIGHT_CYAN) ╚═════╝ $(LIGHT_PURPLE)╚══════╝\n"                                            
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJECTS) -LLibft -lft -Lft_printf -lftprintf 
	@printf "$(LIGHT_GREEN)Compilation completed successfully.\n\033[0m"

clean:
	@echo "$(LIGHT_PURPLE)"
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
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