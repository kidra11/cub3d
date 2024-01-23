# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lthong <lthong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 15:28:04 by nsion             #+#    #+#              #
#    Updated: 2024/01/22 17:13:21 by lthong           ###   ########.fr        #
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
	ft_printf/ft_printf.c\
	ft_printf/ft_find.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c

OBJS = $(SRC:.c=.o)

RM = rm -f

NAME = cub3d

LMLX = ./includes/mlx/libmlx.a

LIB = ./includes/libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS = -I/usr/includes -Imlx -lmlx -L/usr/lib/
MLXMAC = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

all : ${LIB} ${LMLX} $(NAME) 

${LMLX}:
	make -s -C ./includes/mlx/ all

${LIB} :
	make -s -C ./includes/libft/ all

%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@

$(NAME) : $(OBJS) ${LIB} ${LMLX}
	@${CC} ${CFLAGS} $(LIB) $(MLXFLAGS) $(OBJS) -o ${NAME}
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

mac : $(OBJS)
	@${CC} ${CFLAGS} $(LIB) $(MLXMAC) $(OBJS) -o ${NAME}
	@echo "\033[32mDone !\033[0m"

debug : ${LIB} $(OBJS)
	@${CC} ${CFLAGS} $(OBJS) -L./includes/libft -lft -o $(NAME) -g
	@echo "033[32mDone !\033[0m"

.PHONY : all clean fclean re
