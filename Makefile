# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsion <nsion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 15:28:04 by nsion             #+#    #+#              #
#    Updated: 2024/01/30 18:31:54 by nsion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	check_colors_1.c\
	check_colors_2.c\
	check_map_1.c\
	check_map_2.c\
	check_syntax.c\
	check_texture.c\
	clean_exit.c\
	draw.c\
	handle_key.c\
	init.c\
	stock.c\
	new_map.c\
	raycast1.c\
	raycast2.c\
	stock_elem.c\
	render.c\
	testeur.c\

OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR = src/
OBJ_DIR = obj/

RM = rm -f

NAME = cub3D

LMLX = ./mlx/libmlx.a

LIB = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

all : ${LIB} ${LMLX} $(NAME) 

${LMLX}:
	make -s -C ./mlx/ all

${LIB} :
	make -s -C ./libft/ all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@${CC} ${CFLAGS} -I/usr -Imlx -O3 -c $< -o $@

$(NAME) : $(OBJS) ${LIB} ${LMLX}
	@${CC} ${CFLAGS} $(OBJS) $(LIB) -L./mlx/ -lmlx -L/usr/lib/ -I./mlx/ -lXext -lX11 -lm -o ${NAME}
	@echo "\033[32mDone !\033[0m"

clean :
	@${RM} ${OBJS}
	@make -s -C ./libft/ 
	make -C ./mlx/ clean

fclean : clean
	@${RM} $(NAME)
	@make -s -C ./libft/ 
	make -C ./mlx/

re : fclean all

debug : ${LIB} $(OBJS)
	@${CC} ${CFLAGS} $(OBJS) -L./libft -lft -o $(NAME) -g
	@echo "033[32mDone !\033[0m"

.PHONY : all clean fclean re