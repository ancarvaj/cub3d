/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:55:29 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 17:13:41 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_textured_column(t_cub3d *data, t_raycast *ray,
		int tex_num, t_draw_params params)
{
	double	step;
	double	tex_pos;
	int		y;
	int		color;

	step = 1.0 * TEXTURE_HEIGHT / params.line_height;
	tex_pos = (params.draw_start - WINDOW_HEIGHT / 2
			+ params.line_height / 2) * step;
	y = params.draw_start;
	while (y < params.draw_end)
	{
		ray->texture.y = (int)tex_pos & (TEXTURE_HEIGHT - 1);
		tex_pos += step;
		color = data->textures._texture[tex_num].address
		[TEXTURE_HEIGHT * ray->texture.y + ray->texture.x];
		my_mlx_pixel_put(&data->mlx, params.x, y, color);
		y++;
	}
}
