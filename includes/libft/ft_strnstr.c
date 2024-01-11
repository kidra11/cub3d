/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:26:15 by bbach             #+#    #+#             */
/*   Updated: 2023/02/16 13:24:40 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;

	if ((!haystack || !needle) && n == 0)
		return (0);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack && n)
	{
		if (*haystack == needle[0])
		{
			i = 1;
			while ((haystack[i] == needle[i])
				&& needle[i] && haystack[i] && i < n)
				i++;
			if (needle[i] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		n--;
	}
	return (0);
}
