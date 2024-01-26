/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:57:25 by bbach             #+#    #+#             */
/*   Updated: 2024/01/26 16:05:30 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    define_column(t_cub *cub, int *line_height, int *start, int *end)
{
    *line_height = cub->data.display_height / cub->data.perpwalldist;
    *start = -*line_height / 2 + cub->data.display_height / 2;
    if (*start < 0)
        *start = 0;
    *end = *line_height / 2 + cub->data.display_height / 2;
    if (*end >= cub->data.display_height)
        *end = cub->data.display_height - 1;
}

int	get_color(t_cub *cub, int x, int y, int i)
{
	return (*(int *)(cub->img[i].addr
		+ (y * cub->img[i].line_length + x * (cub->img[i].bits_per_pixel/ 8))));
}

void    define_texture(t_cub *cub, int start, int line_height)
{
    if (cub->data.wall_side == 0)
        cub->data.wall_x = cub->data.pos_y + cub->data.perpwalldist * cub->data.ray_dir_y;
    else
        cub->data.wall_x = cub->data.pos_x + cub->data.perpwalldist * cub->data.ray_dir_x;
    cub->data.wall_x -= floor((cub->data.wall_x));
    cub->data.tex_x = cub->data.wall_x * 128;
    if (cub->data.wall_side == 0 && cub->data.ray_dir_x > 0)
        cub->data.tex_x = 128 - cub->data.tex_x - 1;
    if (cub->data.wall_side == 1 && cub->data.ray_dir_y < 0)
        cub->data.tex_x = 128 - cub->data.tex_x - 1;
    cub->data.step = 128.0 / line_height;
    cub->data.tex_pos = (start - cub->data.display_height / 2 + line_height / 2) * cub->data.step;
}

void    draw(t_cub *cub, int x, int texture)
{
    int color;

    color = get_color(cub, cub->data.tex_x, cub->data.tex_y, texture);
    my_mlx_pixel_put(cub, x, cub->data.start, color);
}
void    draw_column(t_cub *cub, int x)
{
    int line_height;

    define_column(cub, &line_height, &cub->data.start, &cub->data.end);
    define_texture(cub, cub->data.start, line_height);
    while (cub->data.start < cub->data.end)
    {
        cub->data.tex_y = (int)cub->data.tex_pos & (128 - 1);
        cub->data.tex_pos += cub->data.step;
        if (cub->data.wall_side == 1 && cub->data.ray_dir_y < 0)
            draw(cub, x, 3);
        else if (cub->data.wall_side == 1 && cub->data.ray_dir_y > 0)
            draw(cub, x, 1);
        else if (cub->data.wall_side == 0 && cub->data.ray_dir_x < 0)
            draw(cub, x, 4);
        else if (cub->data.wall_side == 0 && cub->data.ray_dir_x > 0)
            draw(cub, x, 2);
        cub->data.start++;
    }
}

void    get_delta_distance(t_cub *cub)
{
    if(cub->data.ray_dir_x == 0)
        cub->data.delta_dist_x = INT_MAX;
    else
        cub->data.delta_dist_x = fabs(1 / cub->data.ray_dir_x);
    if(cub->data.ray_dir_y == 0)
        cub->data.delta_dist_y = INT_MAX;
    else
        cub->data.delta_dist_y = fabs(1 / cub->data.ray_dir_y);
}
void    get_step(t_cub *cub)
{
    if (cub->data.ray_dir_x < 0)
    {
        cub->data.step_x = -1;
        cub->data.side_dist_x = (cub->data.pos_x - cub->data.map_x) * cub->data.delta_dist_x;
    }
    else
    {
        cub->data.step_x = 1;
        cub->data.side_dist_x = (cub->data.map_x + 1.0 - cub->data.pos_x) * cub->data.delta_dist_x;
    }
    if (cub->data.ray_dir_y < 0)
    {
        cub->data.step_y = -1;
        cub->data.side_dist_y = (cub->data.pos_y - cub->data.map_y) * cub->data.delta_dist_y;
    }
    else
    {
        cub->data.step_y = 1;
        cub->data.side_dist_y = (cub->data.map_y + 1.0 - cub->data.pos_y) * cub->data.delta_dist_y;
    }
}

void    dda(t_cub *cub)
{
    int hit;

    hit = 0;
    while (hit == 0)
    {
        if (cub->data.side_dist_x < cub->data.side_dist_y)
        {
            cub->data.side_dist_x += cub->data.delta_dist_x;
            cub->data.map_x += cub->data.step_x;
            cub->data.wall_side = 0;
        }
        else
        {
            cub->data.side_dist_y += cub->data.delta_dist_y;
            cub->data.map_y += cub->data.step_y;
            cub->data.wall_side = 1;
        }
        if (cub->new_map[cub->data.map_y][cub->data.map_x] == '1')
            hit = 1;
    }
}

void    init_raycast(t_cub *cub, int x)
{
    cub->data.map_x = cub->data.pos_x;
    cub->data.map_y = cub->data.pos_y;
    cub->data.cam_x = 2 * x / (double)cub->data.display_width - 1;
    cub->data.ray_dir_x = cub->data.dir_x + cub->data.plane_x * cub->data.cam_x;
    cub->data.ray_dir_y = cub->data.dir_y + cub->data.plane_y * cub->data.cam_x;
}
void    raycasting(t_cub *cub)
{
    int x;

    x = 0;
    while (x < cub->data.display_width)
    {
        init_raycast(cub, x);
        get_delta_distance(cub);
        get_step(cub);
        dda(cub);
        if (cub->data.wall_side == 0)
            cub->data.perpwalldist = ((cub->data.side_dist_x - cub->data.delta_dist_x));
        else
            cub->data.perpwalldist = ((cub->data.side_dist_y - cub->data.delta_dist_y));
        draw_column(cub, x);
        x++;
    }
}