/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:38:59 by bbach             #+#    #+#             */
/*   Updated: 2023/04/28 17:57:58 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*silo[1024];
	char		*buff;
	int			oeuf;

	if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (free(silo[fd]), silo[fd] = NULL, NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	oeuf = 1;
	while (oeuf >= 1)
	{
		oeuf = read(fd, buff, BUFFER_SIZE);
		buff[oeuf] = '\0';
		silo[fd] = ft_strjoin2(silo[fd], buff);
		if (ft_strchr2(silo[fd], '\n') == 1)
			break ;
	}
	if (buff)
		free(buff);
	buff = NULL;
	return (extract_line(&silo[fd]));
}

char	*extract_line(char **silo)
{
	int		ble;
	char	*tmp;
	char	*line;

	if (!*silo)
		return (NULL);
	ble = 0;
	tmp = *silo;
	while (tmp[ble] && tmp[ble] != '\n')
		ble++;
	if (tmp[ble] == '\n')
		ble++;
	line = ft_strndup2(tmp, ble);
	*silo = ft_strndup2(tmp + ble, ft_strlen2(tmp + ble));
	free(tmp);
	return (line);
}
