# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lthong <lthong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 15:28:04 by nsion             #+#    #+#              #
#    Updated: 2024/01/23 20:50:00 by lthong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	stock.c\
	check_syntax.c\
	stock_elem.c\
	check_map.c\
	check_texture.c\
	check_colors_1.c\
	check_colors_2.c\
	clean_exit.c\
	testeur.c\
	init.c\
	draw.c\
	raycast1.c\
	raycast2.c\
	handle_key.c\

OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR = src/
OBJ_DIR = obj/

RM = rm -rf

NAME = cub3D

LMLX = ./mlx/libmlx.a

LIB = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS = -I/usr/includes -Imlx -lmlx -L/usr/lib/
MLXMAC = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

all : $(LIB) $(LMLX) $(NAME) 

$(LMLX):
	@make -s -C ./mlx/ all

$(LIB) :
	@make -s -C ./libft/ all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(LIB) $(LMLX)
	@$(CC) $(CFLAGS) $(LIB) $(MLXFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[32mDone !\033[0m"

clean :
	@$(RM) $(OBJ_DIR)
	@make -s -C ./libft/ 
	@make -s -C ./mlx/ clean

fclean : clean
	@$(RM) $(NAME)
	@make -s -C ./libft/ 
	@make -s -C ./mlx/

re : fclean all

mac : $(OBJS) $(LIB) $(LMLX)
	@$(CC) $(CFLAGS) $(LIB) $(MLXMAC) $(OBJS) -o $(NAME)
	@echo "\033[32mDone !\033[0m"

debug : $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L./includes/libft -lft -o $(NAME) -g
	@echo "033[32mDone !\033[0m"

.PHONY : all clean fclean re mac
