/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:32:21 by bbach             #+#    #+#             */
/*   Updated: 2023/04/28 18:08:46 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr3(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return ((char *)s);
		s++;
	}
	if (!s)
		return ((char *)s);
	return (NULL);
}

const char	*ft_texte(t_struct *sc, const char *str)
{
	char	*first_text;

	first_text = ft_strchr3(str);
	if (first_text)
		sc->width = first_text - str;
	else
		sc->width = ft_strlen3(str);
	write(1, str, sc->width);
	sc->len += sc->width;
	while (*str && *str != '%')
		++str;
	return (str);
}
