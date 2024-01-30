/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthong <lthong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:26:17 by lthong            #+#    #+#             */
/*   Updated: 2024/01/30 17:06:31 by lthong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_texel_color(t_texture *texture, int x, int y)
{
	return (*(unsigned int *)(texture->img.addr + \
	(y * texture->img.line_length + x * (texture->img.bits_per_pixel / 8))));
}

void	put_color_in_game(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH - 4)
		{
			if (i < SCREEN_HEIGHT / 2)
				my_mlx_pixel_put(&cub->img, j, i,
					rgb(cub->data.red_c, cub->data.green_c, cub->data.blue_c));
			else
				my_mlx_pixel_put(&cub->img, j, i,
					rgb(cub->data.red_f, cub->data.green_f, cub->data.blue_f));
			j++;
		}
		i++;
	}
}

t_texture	load_texture(t_cub *cub, char *xpm_file)
{
	t_texture	texture;

	texture.img.img = mlx_xpm_file_to_image(cub->data.mlx, xpm_file,
			&texture.width, &texture.height);
	texture.img.addr = mlx_get_data_addr(texture.img.img,
			&texture.img.bits_per_pixel, &texture.img.line_length,
			&texture.img.endian);
	return (texture);
}
