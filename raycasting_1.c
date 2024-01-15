/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:25:24 by bbach             #+#    #+#             */
/*   Updated: 2024/01/15 15:02:40 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void    put_color_in_game(t_cub *cub)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < screen_height)
    {
        while (j < screen_width)
        {
            my_mlx_pixel_put(&cub->data, i, j, trgb (0, 255, 0, 0));
            j++;
        }
        j = 0;
        i++;
    }
}