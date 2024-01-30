# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbach <bbach@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 13:57:31 by bbach             #+#    #+#              #
#    Updated: 2023/05/19 18:30:41 by bbach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_bzero.c \
      ft_isalnum.c \
      ft_isalpha.c \
      ft_isascii.c \
      ft_isdigit.c \
      ft_isprint.c \
      ft_memcpy.c \
      ft_memmove.c \
      ft_memset.c \
      ft_strchr.c \
      ft_strlcat.c \
      ft_strlcpy.c \
      ft_strlen.c \
      ft_tolower.c \
      ft_toupper.c \
      ft_strrchr.c \
      ft_strncmp.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_strnstr.c \
      ft_atoi.c \
      ft_calloc.c \
      ft_strdup.c \
      ft_substr.c \
      ft_strtrim.c \
      ft_itoa.c \
      ft_strmapi.c \
      ft_striteri.c \
      ft_putchar_fd.c \
      ft_putstr_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c \
      ft_strjoin.c \
      ft_split.c \
      get_next_line_bonus.c \
      get_next_line_utils_bonus.c \
      ft_all_len.c \
      ft_arg.c \
      ft_printall.c \
      ft_printf.c \
      ft_texte.c \
      ft_putall.c \
      ft_lstnew.c \
      ft_lstadd_front.c \
      ft_lstsize.c \
	  ft_lstlast.c \
	  ft_lstadd_back.c \
	  ft_putall.c \
        ft_lstclear.c


OBJS = $(SRC:.c=.o)


GCC = gcc -Wall -Werror -Wextra

RM  = rm -f

NAME = libft.a


all: $(NAME)

.c.o:
	$(GCC) -I ./ -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) 

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME) 

.PHONY: all clean fclean re
