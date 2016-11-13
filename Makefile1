# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 16:17:18 by ssicard           #+#    #+#              #
#    Updated: 2016/05/31 10:02:06 by tmanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEAD = ../libft/

LIB = ../libft/libft.a

SDL_TTF = -I ../SDL/SDL2_ttf.framework/Headers

SDL_IMAGE = -I ../SDL/SDL2_image.framework/Headers

SDL2 = -I ../SDL/SDL2.framework/Headers

FRAMEWORK = -F ../SDL -framework SDL2_ttf -framework SDL2 -framework SDL2_image

FRAMEWORK_RELATIVE_PATH = -rpath @executable_path/SDL

SRC =	sources/ft_check_champion.c sources/ft_stock_champion.c \
		sources/ft_memrev.c sources/ft_print_champion.c \
		sources/ft_handle.c \
		sources/main.c \
		sources/reverse_octet.c \
		sources/cpu.c sources/ocp.c sources/stock_types.c \
		sources/init_arena.c \
		sources/get_mem.c \
		sources/put_mem.c \
		sources/ft_load.c \
		sources/ft_jump.c \
		sources/ft_kill_proc.c \
		sources/ft_live.c \
		sources/ft_store.c \
		sources/ft_basic_functions.c \
		sources/ft_aff.c\
		sources/ft_fetch_next.c \
		sources/init_vm.c \
		sources/ft_init_pc.c \
		sources/ft_manage.c \
		sources/check_cycle.c \
		sources/ft_wait.c \
		sources/ft_print_operations.c \
		sources/ft_print_arena.c \
		sources/ft_print_header.c \
		sources/ft_print_core.c \
		sources/ft_display_arena.c \
		sources/ft_visu.c \
		sources/ft_texture_sdl.c \
		sources/ft_query_sdl.c \
		sources/ft_render_sdl.c \
		sources/ft_simple_sdl.c \
		sources/ft_stock_dump.c \
		sources/arguments.c \
		sources/ft_print_winner.c \
		sources/ft_l_core.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIB):
	make -C ../libft/ fclean
	make -C ../libft/

$(NAME): $(LIB) $(OBJ)
	$(CC) $(SDL2) $(SDL_TTF) $(SDL_IMAGE) $(FRAMEWORK) $(FLAGS) -o $@ $(OBJ) $(LIB) $(FRAMEWORK_RELATIVE_PATH)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEAD) -o $@ -c $<
clean:
	/bin/rm -f $(OBJ)
	make -C ../libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ../libft/ fclean

re: fclean all

.PHONY: all clean fclean re
