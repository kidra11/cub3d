# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsion <nsion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 15:28:04 by nsion             #+#    #+#              #
#    Updated: 2024/01/23 11:21:38 by nsion            ###   ########.fr        #
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
	raycast.c\
	handle_key.c\

OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR = src/
OBJ_DIR = obj/

RM = rm -f

NAME = cub3D

LMLX = ./includes/mlx/libmlx.a

LIB = ./includes/libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

all : ${LIB} ${LMLX} $(NAME) 

${LMLX}:
	make -s -C ./includes/mlx/ all

${LIB} :
	make -s -C ./includes/libft/ all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@${CC} ${CFLAGS} -I/usr/includes -Imlx -O3 -c $< -o $@

$(NAME) : $(OBJS) ${LIB} ${LMLX}
	@${CC} ${CFLAGS} $(OBJS) $(LIB) -L./includes/mlx/ -lmlx -L/usr/lib/ -I./mlx/ -lXext -lX11 -lm -o ${NAME}
	@echo "\033[32mDone !\033[0m"

clean :
	@${RM} ${OBJS}
	@make -s -C ./includes/libft/ 
	make -C ./includes/mlx/ clean

fclean : clean
	@${RM} $(NAME)
	@make -s -C ./includes/libft/ 
	make -C ./includes/mlx/

re : fclean all

debug : ${LIB} $(OBJS)
	@${CC} ${CFLAGS} $(OBJS) -L./includes/libft -lft -o $(NAME) -g
	@echo "033[32mDone !\033[0m"

.PHONY : all clean fclean re
