/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:43:48 by bbach             #+#    #+#             */
/*   Updated: 2023/04/28 18:06:24 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printhexalow(unsigned int x)
{
	char	*hexa;
	int		res[100];
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	while (x >= 16)
	{
		res[i] = hexa[x % 16];
		x = x / 16;
		i++;
	}
	res[i] = hexa[x];
	while (i >= 0)
	{
		ft_putchar(res[i]);
		i--;
	}
}

void	ft_printhexaup(unsigned int X)
{
	char	*hexa;
	int		res[100];
	int		i;

	hexa = "0123456789ABCDEF";
	i = 0;
	while (X >= 16)
	{
		res[i] = hexa[X % 16];
		X = X / 16;
		i++;
	}
	res[i] = hexa[X];
	while (i >= 0)
	{
		ft_putchar(res[i]);
		i--;
	}
}

void	ft_printad(unsigned long int x)
{
	char	*hexa;
	int		res[100];
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	while (x >= 16)
	{
		res[i] = hexa[x % 16];
		x = x / 16;
		i++;
	}
	res[i] = hexa[x];
	while (i >= 0)
	{
		ft_putchar(res[i]);
		i--;
	}
}

void	ft_printadress(unsigned long int p)
{
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return ;
	}
	write(1, "0x", 2);
	ft_printad(p);
}
