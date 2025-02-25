/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:58:22 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/25 19:24:18 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_window(t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	if (!mlx->win)
		exit(ft_error("Error\nFailed creating window\n"));
}

int	ft_close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->_img.address + ((y * mlx->_img.size_line)
			+ (x * (mlx->_img.bpp / 8)));
	*(unsigned int *)dst = color;
}

void	update_position(t_cub3d *data, int vector)
{
	const double	move_speed = 0.2;
	const double	rotation_speed = 0.1;

	if (vector == UP)
		ft_up_player(data, move_speed);
	if (vector == DOWN)
		ft_down_player(data, move_speed);
	if (vector == LEFT)
		ft_left_player(data, rotation_speed);
	if (vector == RIGHT)
		ft_right_player(data, rotation_speed);
	if (vector == STRAFE_LEFT)
		ft_strafe_left(data, move_speed);
	if (vector == STRAFE_RIGHT)
		ft_strafe_right(data, move_speed);
}

int	key_press(int key_code, t_cub3d *data)
{
	if (key_code == 65307)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		exit(0);
	}
	if (key_code == 119)
		update_position(data, UP);
	if (key_code == 65363)
		update_position(data, RIGHT);
	if (key_code == 100)
		update_position(data, STRAFE_RIGHT);
	if (key_code == 115)
		update_position(data, DOWN);
	if (key_code == 65361)
		update_position(data, LEFT);
	if (key_code == 97)
		update_position(data, STRAFE_LEFT);
	render_frame(data);
	return (0);
}
