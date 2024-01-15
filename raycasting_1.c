/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:25:24 by bbach             #+#    #+#             */
/*   Updated: 2024/01/15 12:45:13 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_line(void *mlx, void *win, int x, int drawstart, int drawend, int color)
{
    int y;

    y = drawstart;
    while (y <= drawend)
    {
        mlx_pixel_put(mlx, win, x, y, color);
        y++;
    }
}