/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:29:05 by bbach             #+#    #+#             */
/*   Updated: 2024/01/17 15:56:28 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    rendering(t_cub *cub)
{
    int x = 0;
    int y = 0;
    int hit = 0;
    int side;
    int line_height;
    int pitch;
    int draw_start;
    int draw_end;
    int text_num;
    int text_x;
    int text_y;

    while (x < SCREEN_WIDTH)
    {
        cub->data.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
        cub->data.ray_dir_x = cub->data.player_dir_x + cub->data.plane_x * cub->data.camera_x;
        cub->data.ray_dir_y = cub->data.player_dir_y + cub->data.plane_y * cub->data.camera_x;

        cub->data.map_x = (int)cub->data.player_pos_x;
        cub->data.map_y = (int)cub->data.player_pos_y;

        if (cub->data.ray_dir_x == 0) 
            cub->data.delta_dist_x = 1e30;
        else 
            cub->data.delta_dist_x = fabs(1.0 / cub->data.ray_dir_x);
            
        if (cub->data.ray_dir_y == 0)
            cub->data.delta_dist_y = 1e30;
        else 
            cub->data.delta_dist_y = fabs(1.0 / cub->data.ray_dir_y);
            
        if (cub->data.ray_dir_x < 0)
        {
            cub->data.step_x = -1;
            cub->data.side_dist_x = (cub->data.player_pos_x - cub->data.map_x) * cub->data.delta_dist_x;
        }
        else
        {
            cub->data.step_x = 1;
            cub->data.side_dist_x = (cub->data.map_x + 1.0 - cub->data.player_pos_x) * cub->data.delta_dist_x;
        }

        if (cub->data.ray_dir_y < 0)
        {
            cub->data.step_y = -1;
            cub->data.side_dist_y = (cub->data.player_pos_y - cub->data.map_y) * cub->data.delta_dist_y;
        }
        else
        {
            cub->data.step_y = 1;
            cub->data.side_dist_y = (cub->data.map_y + 1.0 - cub->data.player_pos_y) * cub->data.delta_dist_y;
        }
        //starting algo de ses morts
        while (hit == 0)
        {
            if (cub->data.side_dist_x < cub->data.side_dist_y)
            {
                cub->data.side_dist_x += cub->data.delta_dist_x;
                cub->data.map_x += cub->data.step_x;
                side = 0;
            }
            else
            {
                cub->data.side_dist_y += cub->data.delta_dist_y;
                cub->data.map_y += cub->data.step_y;
                side = 1;
            }

            if (cub->map_copy[cub->data.map_y][cub->data.map_x] == '1')
                hit = 1;
        }
        //calcul de la distance
        if (side == 0)
            cub->data.perp_wall_dist = cub->data.side_dist_x - cub->data.delta_dist_x;
        else
            cub->data.perp_wall_dist = cub->data.side_dist_y - cub->data.delta_dist_y;

        //calcul de la hauteur de la ligne

        line_height = (int)(SCREEN_HEIGHT / cub->data.perp_wall_dist);
        
        pitch = 100;

        //calcul des points de depart et d'arrivee de la ligne
        draw_start = -line_height / 2 + SCREEN_HEIGHT / 2 + pitch;
        if (draw_start < 0)
            draw_start = 0;
        draw_end = line_height / 2 + SCREEN_HEIGHT / 2 + pitch;
        if (draw_end >= SCREEN_HEIGHT)
            draw_end = SCREEN_HEIGHT - 1;

        //calcul de la texture
        text_num = cub->map_copy[cub->data.map_y][cub->data.map_x] - 1;

        if (side == 0)
            cub->data.wall_x = cub->data.player_pos_y + cub->data.perp_wall_dist * cub->data.ray_dir_y;
        else
            cub->data.wall_x = cub->data.player_pos_x + cub->data.perp_wall_dist * cub->data.ray_dir_x;

        cub->data.wall_x -= floor((cub->data.wall_x));

        //calcul de la position dans la texture

        text_x = (int)(cub->data.wall_x * (double)TEX_WIDTH);
        if (side == 0 && cub->data.ray_dir_x > 0)
            text_x = TEX_WIDTH - text_x - 1;
        if (side == 1 && cub->data.ray_dir_y < 0)
            text_x = TEX_WIDTH - text_x - 1;
        
        // calcul de la position dans la texture 

        cub->data.step = 1.0 * TEX_HEIGHT / line_height;
        cub->data.tex_pos = (draw_start - pitch - SCREEN_HEIGHT / 2 + line_height / 2) * cub->data.step;
        
        y = draw_start;

        while (y < draw_end)
        {
            text_y = (int)cub->data.tex_pos & (TEX_HEIGHT - 1);
            cub->data.tex_pos += cub->data.step;
            unsigned int color = cub->textures_path[text_num][TEX_HEIGHT * text_y + text_x];
            if (side == 1)
                color = (color >> 1) & 8355711;
            my_mlx_pixel_put(&cub->img, x, y, cub->textures_path[text_num][TEX_HEIGHT * text_y + text_x]);
            y++;
        }
        x++;
    }
}
