/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:39:24 by bbach             #+#    #+#             */
/*   Updated: 2023/12/29 17:11:20 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(char *file, t_cub *cub)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		clean_exit("Error opening file", cub);
	cub->lines_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		cub->lines_count++;
		free(line);
	}
	close(fd);
	ft_printf("test_count_lines_1\n");
	ft_printf("cub->lines_count : %d\n", cub->lines_count);
	return (cub->lines_count);
}

char	*ft_copy(const char *str, int start, int end)
{
	int		i;
	char	*cp;

	i = 0;
	cp = (char *) malloc(((end - start) + 1) * sizeof(char));
	if (!cp)
		return (NULL);
	while (start < end)
	{
		if (str[start] == '\n')
			start++;
		cp[i++] = str[start++];
	}
	cp[i] = '\0';
	return (cp);
}