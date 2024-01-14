# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nath <nath@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 15:28:04 by nsion             #+#    #+#              #
#    Updated: 2024/01/14 20:01:27 by nath             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	stock.c\
	check_syntax.c\
	stock_elem.c\
	check_map.c\
	clean_exit.c\
	testeur.c\
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

all : ${LIB} ${LMLX} $(NAME) 

${LMLX}:
	make -s -C ./includes/mlx/ all

${LIB} :
	make -s -C ./includes/libft/ all

%.o : %.c
	@${CC} ${CFLAGS} -I/usr/includes -Imlx -O3 -c $< -o $@

$(NAME) : $(OBJS) ${LIB} ${LMLX}
	@${CC} ${CFLAGS} $(OBJS) -L./includes/libft -lft -L./includes/mlx/ -lmlx -L/usr/lib/ -I./mlx/ -lXext -lX11 -lm -o ${NAME}
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
