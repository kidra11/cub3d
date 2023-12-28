/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:44:45 by bbach             #+#    #+#             */
/*   Updated: 2023/02/13 17:54:01 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cast;

	i = 0;
	cast = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == cast)
			return ((char *)s + i);
		i++;
	}
	if (cast == '\0')
		return ((char *)s + i);
	return (0);
}
