/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:20:42 by bbach             #+#    #+#             */
/*   Updated: 2023/04/28 18:05:34 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	t_struct	sc;

	if (!str)
		return (0);
	va_start(arg, str);
	sc.len = 0;
	sc.width = 0;
	while (*str)
	{
		if (*str == '%')
			str = ft_ifformat(arg, str + 1, &sc);
		else
			str = ft_texte(&sc, str);
		if (str == NULL)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (sc.len);
		}
	}
	va_end(arg);
	return (sc.len);
}

const char	*ft_ifformat(va_list arg, const char *str, t_struct *sc)
{
	if (*str == 'd' || *str == 'i' || *str == 's')
		return (ft_arg1(arg, str, sc));
	else if (*str == 'c' || *str == 'p')
		return (ft_arg2(arg, str, sc));
	else if (*str == 'u' || *str == '%')
		return (ft_arg3(arg, str, sc));
	else if (*str == 'x' || *str == 'X')
		return (ft_arg4(arg, str, sc));
	else
		return (str);
}
