/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:18:57 by bbach             #+#    #+#             */
/*   Updated: 2023/03/13 14:15:53 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_quicompt(const char *s, char c)
{
	size_t	nbmot;
	size_t	index;

	nbmot = 0;
	index = 0;
	while (*s)
	{
		if (*s != c && index == 0)
		{
			nbmot++;
			index = 1;
		}
		else if (*s == c)
			index = 0;
		s++;
	}
	return (nbmot);
}

static char	*ft_print(const char *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	size_t	j;
	size_t	i;
	size_t	adress;
	char	**tab;

	tab = malloc(sizeof(char *) * (ft_quicompt(s, c) + 1));
	if (!tab)
		return (NULL);
	adress = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		adress = i;
		while (s[i] != c && s[i])
			i++;
		if (adress != i)
			tab[j++] = ft_print(s, adress, i);
	}
	tab[j] = NULL;
	return (tab);
}
