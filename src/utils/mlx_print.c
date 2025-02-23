/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:43:10 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/22 15:48:04 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->_img.address + ((y * mlx->_img.size_line)
			+ (x * (mlx->_img.bpp / 8)));
	*(unsigned int *)dst = color;
}

void	print_floor_ceiling(t_cub3d *data, int color_floor, int color_ceiling)
{
	int	x;
	int	y;

	x = 0;
	while (x < WINDOW_HEIGHT)
	{
		y = 0;
		while (y < WINDOW_WIDTH)
		{
			if (x < WINDOW_HEIGHT / 2)
				my_mlx_pixel_put(&data->mlx, y, x, color_ceiling);
			else if (x >= WINDOW_HEIGHT / 2)
				my_mlx_pixel_put(&data->mlx, y, x, color_floor);
			y++;
		}
		x++;
	}
}
