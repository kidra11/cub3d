/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:08:31 by bbach             #+#    #+#             */
/*   Updated: 2023/02/07 16:39:38 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nstr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nstr == 32 || (*nstr >= 9 && *nstr <= 13))
		nstr++;
	if (*nstr == '-' || *nstr == '+')
	{
		if (*nstr == '-')
			sign *= -1;
		nstr++;
	}
	while (*nstr >= '0' && *nstr <= '9')
	{
		res = res * 10 + (*nstr - '0');
		nstr++;
	}
	return (res * sign);
}
