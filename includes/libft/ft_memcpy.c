/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:10:32 by bbach             #+#    #+#             */
/*   Updated: 2023/02/13 17:50:30 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*srce;
	char		*desti;

	srce = (char *)src;
	desti = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		desti[i] = srce[i];
		i++;
	}
	return (dest);
}
