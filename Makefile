# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:11:28 by eozdek            #+#    #+#              #
#    Updated: 2016/11/10 11:38:35 by eozdek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= filler
FILES	= get_next_line.c main.c ft_find_place.c ft_read_map.c ft_tab.c ft_algo.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
CC		= gcc

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[95m	 ______ _ _ _           "
	@echo "\033[95m	|  ____(_) | |          "
	@echo "\033[95m	| |__   _| | | ___ _ __ "
	@echo "\033[95m	|  __| | | | |/ _ \ '__|"
	@echo "\033[95m	| |    | | | |  __/ |   "
	@echo "\033[95m	|_|    |_|_|_|\___|_|   "
	@echo "\033[96m                  by e🏀 zdek\033[97m         "
	@echo "\033[91mCompiling 😇\033[97m"
		@make -C libft
		@$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
		@echo "\033[90mDone 😎\033[97m"
.obj/%.o: src/%.c
	mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS) $(INC)

clean:
	@echo "\033[92mDeleting 💀\033[97m"
	@rm -rf .obj
	@make clean -C libft
	@echo "\033[96mClean done 😡\033[97m"

fclean: clean
	@echo "\033[92mDeleting 💀\033[97m"
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\033[96mFclean Done 👿\033[97m"

re: fclean all

.PHONY: all clean fclean re
