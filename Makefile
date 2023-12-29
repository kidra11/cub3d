# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsion <nsion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 15:28:04 by nsion             #+#    #+#              #
#    Updated: 2023/12/29 19:31:59 by nsion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c check_map.c clean_exit.c check_syntax.c ft_printf/ft_printf.c  ft_printf/ft_find.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

NAME = cub3D

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJS = $(SRCS:.c=.o)

#LMLX = mlx/libmlx.a

#LIB = -Lmlx/ -lmlx -L/usr/lib/ -lXext -lX11 -lm -I ./ -I ./mlx/

all	:  $(NAME) #$(LMLX)

#${LMLX}	:
#	make -C mlx/ all

.c.o	:
	$(GCC) $(CFLAGS) $(LIB) -c $< -o $(<:.c=.o) 

$(NAME) : $(OBJS)
	$(GCC) $(OBJS) -o $(NAME)

clean	:
	$(RM) $(OBJS)
#	make -C mlx clean

fclean	:	clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re