/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:10:26 by bbach             #+#    #+#             */
/*   Updated: 2023/04/28 18:06:26 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen3(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_intlen(int nb, char c)
{
	int	j;
	int	number;

	j = 0;
	if (!nb)
		return (1);
	if (nb < 0)
	{
		j++;
		number = -nb;
	}
	else
		number = nb;
	if (c == 'd' || c == 'i')
	{
		while (number)
		{
			number /= 10;
			j++;
		}
		return (j);
	}
	return (0);
}

int	ft_unsignedlen(unsigned int number, char c)
{
	unsigned int	i;

	if (!number)
		return (1);
	i = 0;
	if (c == 'x' || c == 'X')
	{
		while (number)
		{
			number /= 16;
			i++;
		}
		return (i);
	}
	if (c == 'u')
	{
		while (number)
		{
			number /= 10;
			i++;
		}
		return (i);
	}
	return (0);
}

int	ft_unsignedlonglen(unsigned long int number, char c)
{
	unsigned long int	i;

	i = 0;
	if (c == 'p')
	{
		while (number)
		{
			number /= 16;
			i++;
		}
		return (i);
	}
	return (0);
}
