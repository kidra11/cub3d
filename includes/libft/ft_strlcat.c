/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:36:09 by bbach             #+#    #+#             */
/*   Updated: 2023/03/13 14:17:34 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if ((!dst || !src) && !size)
		return (0);
	if (dlen >= size)
		return (slen + size);
	ft_strlcpy(dst + dlen, src, size - dlen);
	return (dlen + slen);
}
