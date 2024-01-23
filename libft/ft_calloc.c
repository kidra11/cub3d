/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:40:19 by bbach             #+#    #+#             */
/*   Updated: 2023/02/23 12:51:40 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	p;
	char	*dst;

	p = (nmemb * size);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size != (p / nmemb))
		return (NULL);
	dst = malloc(p);
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, p);
	return (dst);
}
