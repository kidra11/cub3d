/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:09:48 by bbach             #+#    #+#             */
/*   Updated: 2023/05/19 18:30:01 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	int				value;
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_struct
{
	int	len;
	int	width;
}		t_struct;

int			ft_lstsize(t_list *lst);
int			ft_memcmp(const void*s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *nptr);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isprint(int c);

void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstclear(t_list **lst);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
char		**ft_split(const char *s, char c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int content);

//------------------Get_Next_Line---------------------------------//

char		*get_next_line(int fd);
char		*extract_line(char **silo);
char		*ft_strjoin2(char *s1, char *s2);
size_t		ft_strlen2(char *str);
int			ft_strchr2(char *s, char c);
char		*ft_strndup2(char *s, int n);

//-----------------Print_F---------------------------------------//

const char	*ft_ifformat(va_list arg, const char *str, t_struct *sc);
const char	*ft_arg1(va_list arg, const char *format, t_struct *sc);
const char	*ft_arg2(va_list arg, const char *format, t_struct *sc);
const char	*ft_arg3(va_list arg, const char *format, t_struct *sc);
const char	*ft_arg4(va_list arg, const char *format, t_struct *sc);

const char	*ft_texte(t_struct *sc, const char *str);
int			ft_printf(const char *str, ...);
int			ft_strlen3(const char *s);

int			ft_intlen(int nb, char c);
int			ft_unsignedlen(unsigned int number, char c);
int			ft_unsignedlonglen(unsigned long int number, char c);

void		ft_printhexalow(unsigned int x);
void		ft_printhexaup(unsigned int X);
void		ft_printad(unsigned long int x);
void		ft_printadress(unsigned long int p);

void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		ft_putnbru(long long nb);
void		ft_putstr(char *str);

#endif
