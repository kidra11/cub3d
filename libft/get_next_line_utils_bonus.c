/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:02:18 by bbach             #+#    #+#             */
/*   Updated: 2023/04/28 17:58:04 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char		*result;
	size_t		len;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strndup2(s2, ft_strlen2(s2)));
	if (!s2)
		return (NULL);
	len = (ft_strlen2(s1) + ft_strlen2(s2));
	result = malloc((sizeof(char) * len + 1));
	if (!result)
		return (NULL);
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	free(s1);
	return (result);
}

size_t	ft_strlen2(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr2(char *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strndup2(char *s, int n)
{
	int		i;
	char	*dest;

	if (!s || !n)
		return (NULL);
	i = 0;
	dest = malloc(sizeof(char) * n + 1);
	if (dest == NULL)
		return (NULL);
	while (s[i] && i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
