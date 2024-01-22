/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthong <lthong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:20:21 by lthong            #+#    #+#             */
/*   Updated: 2024/01/22 14:31:14 by lthong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dist(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	draw_ray(t_cub *cub, int psize)
{
	int		r;
	int		dof;
	double	a_tan;
	double	yo;
	double	xo;
	int		mx;
	int		my;

	double	n_tan; //vertical

	double	dist_h; //horizontal
	double	hx;
	double	hy;

	double	dist_v; //vertical
	double	vx;
	double	vy;

	double	dist_f;

	(void)psize;
	cub->ray.ra = cub->player.pa - (DR * 30);
	if (cub->ray.ra < 0)
		cub->ray.ra += 2 * PI;
	if (cub->ray.ra > 2 * PI)
		cub->ray.ra -= 2 * PI;
	r = 0;
	while (r < 60)
	{
		// Horizontal check
		dof = 0;
		dist_h = 1000000000;
		hx = cub->player.pos_x;
		hy = cub->player.pos_y;
		a_tan = -1 / tan(cub->ray.ra);
		if (cub->ray.ra > PI) // looking up
		{
			cub->ray.ry = (((int)cub->player.pos_y >> 6) << 6) - 0.0001;
			cub->ray.rx = (cub->player.pos_y - cub->ray.ry) * a_tan + cub->player.pos_x;
			yo = -64;
			xo = -yo * a_tan;
		}
		else if (cub->ray.ra < PI) // looking down
		{
			cub->ray.ry = (((int)cub->player.pos_y >> 6) << 6) + 64;
			cub->ray.rx = (cub->player.pos_y - cub->ray.ry) * a_tan + cub->player.pos_x;
			yo = 64;
			xo = -yo * a_tan;
		}
		else if (cub->ray.ra == 0 || cub->ray.ra == PI) // looking left or right
		{
			cub->ray.rx = cub->player.pos_x;
			cub->ray.ry = cub->player.pos_y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(cub->ray.rx) >> 6;
			my = (int)(cub->ray.ry) >> 6;
			if (mx >= 0 && mx < cub->data.map_width && my >= 0 && my < cub->data.map_height && cub->map[my][mx] == '1')
			{
				//draw_line(cub, cub->player.pos_x + (psize / 2), cub->player.pos_y + (psize / 2), (int)cub->ray.rx, (int)cub->ray.ry, 0x0000FF);
				hx = cub->ray.rx;
				hy = cub->ray.ry;
				dist_h = dist(cub->player.pos_x, cub->player.pos_y, hx, hy);
				dof = 8;
			}
			else
			{
				cub->ray.rx += xo;
				cub->ray.ry += yo;
				dof++;
			}
		}
		// Vertical check
		dof = 0;
		dist_v = 1000000000;
		vx = cub->player.pos_x;
		vy = cub->player.pos_y;
		n_tan = -tan(cub->ray.ra);
		if (cub->ray.ra > PI / 2 && cub->ray.ra < 3 * PI / 2) // looking left
		{
			cub->ray.rx = (((int)cub->player.pos_x >> 6) << 6) - 0.0001;
			cub->ray.ry = (cub->player.pos_x - cub->ray.rx) * n_tan + cub->player.pos_y;
			xo = -64;
			yo = -xo * n_tan;
		}
		else if (cub->ray.ra < PI / 2 || cub->ray.ra > 3 * PI / 2) // looking right
		{
			cub->ray.rx = (((int)cub->player.pos_x >> 6) << 6) + 64;
			cub->ray.ry = (cub->player.pos_x - cub->ray.rx) * n_tan + cub->player.pos_y;
			xo = 64;
			yo = -xo * n_tan;
		}
		else if (cub->ray.ra == 0 || cub->ray.ra == PI) // looking up or down
		{
			cub->ray.rx = cub->player.pos_x;
			cub->ray.ry = cub->player.pos_y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(cub->ray.rx) >> 6;
			my = (int)(cub->ray.ry) >> 6;
			if (mx >= 0 && mx < cub->data.map_width && my >= 0 && my < cub->data.map_height && cub->map[my][mx] == '1')
			{
				//draw_line(cub, cub->player.pos_x + (psize / 2), cub->player.pos_y + (psize / 2), (int)cub->ray.rx, (int)cub->ray.ry, 0xFF0000);
				vx = cub->ray.rx;
				vy = cub->ray.ry;
				dist_v = dist(cub->player.pos_x, cub->player.pos_y, vx, vy);
				dof = 8;
			}
			else
			{
				cub->ray.rx += xo;
				cub->ray.ry += yo;
				dof++;
			}
		}
		if (dist_v < dist_h)
		{
			cub->ray.rx = vx;
			cub->ray.ry = vy;
			dist_f = dist_v;
		}
		if (dist_h < dist_v)
		{
			cub->ray.rx = hx;
			cub->ray.ry = hy;
			dist_f = dist_h;
		}
		draw_line(cub, cub->player.pos_x + (psize / 2), cub->player.pos_y + (psize / 2), (int)cub->ray.rx, (int)cub->ray.ry, 0x00FF00);
		// draw 3D
		double line_h;
		double line_o;
		double	ca;
		 //fish eye
		ca = cub->player.pa - cub->ray.ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		dist_f = dist_f * cos(ca);
		
		line_h = (64 * 320) / dist_f;
		if (line_h > 320)
			line_h = 320;
		line_o = 160 - (line_h / 2);
		draw_thick_line(cub, 530 + (r * 8), line_o, 530 + (r * 8), line_o + line_h, 8, 0x00FF00);
		cub->ray.ra += DR;
		if (cub->ray.ra < 0)
			cub->ray.ra += 2 * PI;
		if (cub->ray.ra > 2 * PI)
			cub->ray.ra -= 2 * PI;
		r++;
	}
}