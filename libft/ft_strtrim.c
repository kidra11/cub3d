/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:14:24 by bbach             #+#    #+#             */
/*   Updated: 2023/02/11 12:20:13 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	debut;
	size_t	fin;
	size_t	l;
	size_t	len;
	char	*new;

	debut = 0;
	l = ft_strlen(s1);
	fin = l - 1;
	while (debut < l && ft_strchr(set, s1[debut]) != NULL)
		debut++;
	while (fin > debut && ft_strchr(set, s1[fin]) != NULL)
		fin--;
	len = fin - debut + 1;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1 + debut, len);
	new[len] = '\0';
	return (new);
}
