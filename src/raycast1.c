/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthong <lthong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:20:21 by lthong            #+#    #+#             */
/*   Updated: 2024/01/27 03:43:05 by lthong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	dist(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	check_full_rota(t_cub *cub)
{
	if (cub->ray.ra < 0)
		cub->ray.ra += 2 * PI;
	if (cub->ray.ra > 2 * PI)
		cub->ray.ra -= 2 * PI;
}

void	draw_ray(t_cub *cub)
{
	int		r;
	int		dof;
	double	a_tan;
	double	n_tan;

	cub->ray.ra = cub->player.pa - (DR * 30);
	check_full_rota(cub);
	r = 0;
	while (r < 60)
	{
		dof = 0;
		a_tan = -1 / tan(cub->ray.ra);
		horizontal_check(cub, &dof, a_tan);
		horizontal_hit(cub, &dof);
		dof = 0;
		n_tan = -tan(cub->ray.ra);
		vertical_check(cub, &dof, n_tan);
		vertical_hit(cub, &dof);
		closest_ray(cub);
		render(cub, r);
		r++;
	}
}

void	render(t_cub *cub, int r)
{
	cub->ray.ca = cub->player.pa - cub->ray.ra;
	if (cub->ray.ca < 0)
		cub->ray.ca += 2 * PI;
	if (cub->ray.ca > 2 * PI)
		cub->ray.ca -= 2 * PI;
	cub->ray.dist_f = cub->ray.dist_f * cos(cub->ray.ca);
	cub->ray.line_h = (cub->data.map_size * SCREEN_HEIGHT) / cub->ray.dist_f;
	if (cub->ray.line_h > SCREEN_HEIGHT)
		cub->ray.line_h = SCREEN_HEIGHT;
	cub->ray.line_o = (SCREEN_HEIGHT / 2) - (cub->ray.line_h / 2);
	//draw_thick_line(cub, r * 17, cub->ray.line_o, r * 17,
	//	cub->ray.line_o + cub->ray.line_h, 17, rgb(255, 0, 0));
	
	
	side_texture(cub);
    /*int texture_column = (int)((cub->ray.rx - floor(cub->ray.rx)) * cub->cur_tex->width);
    double texture_x = (double)texture_column / cub->cur_tex->width;
	for (int y = cub->ray.line_o; y < cub->ray.line_o + cub->ray.line_h; y++)
    {
        double texture_y = (double)(y - cub->ray.line_o) / cub->ray.line_h * cub->cur_tex->height;
        //int texture_row = (int)texture_y;
        draw_thick_line(cub, r * 17, y, r * 17, y + 1, texture_x, texture_y, 17, cub->cur_tex);
    }
	*/
	
	cub->render.tex_col = (int)((cub->ray.rx - floor(cub->ray.rx))
			* cub->cur_tex->width);
	cub->render.tex_x = (double)cub->render.tex_col / cub->cur_tex->width;
	int	y;
	y = cub->ray.line_o;
	while (y < cub->ray.line_o + cub->ray.line_h)
	{
		cub->render.tex_y = (double)(y - cub->ray.line_o) / cub->ray.line_h
			* cub->cur_tex->height;
		draw_thick_line(cub, r * 17, y, r * 17, y + 1, cub->render.tex_x,
			(int)cub->render.tex_y, 17, cub->cur_tex);
		y++;
	}
	
	cub->ray.ra += DR;
	check_full_rota(cub);
}

void	side_texture(t_cub *cub)
{
	cub->cur_tex = NULL;
	if (cub->ray.side == 1)
	{
		if (cub->ray.ra < 3 * PI / 2 && cub->ray.ra > PI / 2)
			cub->cur_tex = &cub->we;
		else
			cub->cur_tex = &cub->ea;
	}
	else if (cub->ray.side == 0)
	{
		if (cub->ray.ra < PI)
			cub->cur_tex = &cub->no;
		else
			cub->cur_tex = &cub->so;
	}
}
