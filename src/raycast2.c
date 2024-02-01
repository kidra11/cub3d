/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:40:51 by lthong            #+#    #+#             */
/*   Updated: 2024/02/01 23:49:11 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	horizontal_check(t_cub *cub, int *dof, double a_tan)
{
	cub->ray.dist_h = 1000000000;
	cub->ray.hx = cub->player.pos_x;
	cub->ray.hy = cub->player.pos_y;
	if (cub->ray.ra > PI)
	{
		cub->ray.ry = (((int)cub->player.pos_y >> 6) << 6) - 0.0001;
		cub->ray.rx = (cub->player.pos_y - cub->ray.ry)
			* a_tan + cub->player.pos_x;
		cub->ray.yo = -64;
		cub->ray.xo = -(cub->ray.yo) * a_tan;
	}
	else if (cub->ray.ra < PI)
	{
		cub->ray.ry = (((int)cub->player.pos_y >> 6) << 6) + 64;
		cub->ray.rx = (cub->player.pos_y - cub->ray.ry)
			* a_tan + cub->player.pos_x;
		cub->ray.yo = 64;
		cub->ray.xo = -(cub->ray.yo) * a_tan;
	}
	else if (cub->ray.ra == 0 || cub->ray.ra == PI)
	{
		cub->ray.rx = cub->player.pos_x;
		cub->ray.ry = cub->player.pos_y;
		*dof = cub->data.map_height;
	}
}

void	vertical_check(t_cub *cub, int *dof, double n_tan)
{
	cub->ray.dist_v = 1000000000;
	cub->ray.vx = cub->player.pos_x;
	cub->ray.vy = cub->player.pos_y;
	if (cub->ray.ra > PI / 2 && cub->ray.ra < 3 * PI / 2)
	{
		cub->ray.rx = (((int)cub->player.pos_x >> 6) << 6) - 0.0001;
		cub->ray.ry = (cub->player.pos_x - cub->ray.rx)
			* n_tan + cub->player.pos_y;
		cub->ray.xo = -64;
		cub->ray.yo = -(cub->ray.xo) * n_tan;
	}
	else if (cub->ray.ra < PI / 2 || cub->ray.ra > 3 * PI / 2)
	{
		cub->ray.rx = (((int)cub->player.pos_x >> 6) << 6) + 64;
		cub->ray.ry = (cub->player.pos_x - cub->ray.rx)
			* n_tan + cub->player.pos_y;
		cub->ray.xo = 64;
		cub->ray.yo = -(cub->ray.xo) * n_tan;
	}
	else if (cub->ray.ra == 0 || cub->ray.ra == PI)
	{
		cub->ray.rx = cub->player.pos_x;
		cub->ray.ry = cub->player.pos_y;
		*dof = cub->data.map_width;
	}
}

void	horizontal_hit(t_cub *cub, int *dof)
{
	while (*dof < cub->data.map_height)
	{
		cub->ray.mx = (int)(cub->ray.rx) >> 6;
		cub->ray.my = (int)(cub->ray.ry) >> 6;
		if (cub->ray.mx >= 0 && cub->ray.mx < cub->data.map_width
			&& cub->ray.my >= 0 && cub->ray.my < cub->data.map_height
			&& cub->new_map[cub->ray.my][cub->ray.mx] == '1')
		{
			cub->ray.hx = cub->ray.rx;
			cub->ray.hy = cub->ray.ry;
			cub->ray.dist_h = dist(cub->player.pos_x, cub->player.pos_y,
					cub->ray.hx, cub->ray.hy);
			*dof = cub->data.map_height;
		}
		else
		{
			cub->ray.rx += cub->ray.xo;
			cub->ray.ry += cub->ray.yo;
			(*dof)++;
		}
	}
}

void	vertical_hit(t_cub *cub, int *dof)
{
	while (*dof < cub->data.map_width)
	{
		cub->ray.mx = (int)(cub->ray.rx) >> 6;
		cub->ray.my = (int)(cub->ray.ry) >> 6;
		if (cub->ray.mx >= 0 && cub->ray.mx < cub->data.map_width
			&& cub->ray.my >= 0 && cub->ray.my < cub->data.map_height
			&& cub->new_map[cub->ray.my][cub->ray.mx] == '1')
		{
			cub->ray.vx = cub->ray.rx;
			cub->ray.vy = cub->ray.ry;
			cub->ray.dist_v = dist(cub->player.pos_x, cub->player.pos_y,
					cub->ray.vx, cub->ray.vy);
			*dof = cub->data.map_width;
		}
		else
		{
			cub->ray.rx += cub->ray.xo;
			cub->ray.ry += cub->ray.yo;
			(*dof)++;
		}
	}
}

void	closest_ray(t_cub *cub)
{
	if (cub->ray.dist_v < cub->ray.dist_h)
	{
		cub->ray.rx = cub->ray.vx;
		cub->ray.ry = cub->ray.vy;
		cub->ray.side = 1;
		cub->ray.dist_f = cub->ray.dist_v;
	}
	if (cub->ray.dist_h < cub->ray.dist_v)
	{
		cub->ray.rx = cub->ray.hx;
		cub->ray.ry = cub->ray.hy;
		cub->ray.side = 0;
		cub->ray.dist_f = cub->ray.dist_h;
	}
}
