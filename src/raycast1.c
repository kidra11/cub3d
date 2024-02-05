/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:20:21 by lthong            #+#    #+#             */
/*   Updated: 2024/02/05 14:36:11 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	mlx_put_image_to_window(cub->data.mlx, cub->data.mlx_win,
		cub->img.img, 0, 0);
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
	side_texture(cub);
	cub->render.tex_col = (int)((cub->ray.rx - floor(cub->ray.rx))
			* cub->cur_tex->width);
	cub->render.tex_x = (double)cub->render.tex_col / cub->cur_tex->width;
	draw_wall(cub, r);
	cub->ray.ra += DR;
	check_full_rota(cub);
}

void	draw_wall(t_cub *cub, int r)
{
	int	x;
	int	y;

	y = cub->ray.line_o;
	while (y < cub->ray.line_o + cub->ray.line_h)
	{
		cub->render.tex_y = fmod((y - cub->ray.line_o) / cub->ray.line_h \
			* cub->cur_tex->height, cub->cur_tex->height);
		if (cub->render.tex_y < 0)
			cub->render.tex_y += cub->cur_tex->height;
		x = 0;
		while (x < 17)
		{
			cub->render.tex_x = fmod((r * 17.0 + x) / 170.0 * \
				cub->cur_tex->width, cub->cur_tex->width);
			if (cub->render.tex_x < 0)
				cub->render.tex_x += cub->cur_tex->width;
			draw_vline(cub, r * 17 + x, y, y + 1);
			x++;
		}
		y++;
	}
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
