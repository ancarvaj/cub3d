/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:01:56 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 16:02:43 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_right_player(t_cub3d *data, const double rotSpeed)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = data->player.direction.x;
	data->player.direction.x = data->player.direction.x * cos(-rotSpeed)
		- data->player.direction.y * sin(-rotSpeed);
	data->player.direction.y = old_dir_x * sin(-rotSpeed)
		+ data->player.direction.y * cos(-rotSpeed);
	old_plane_x = data->player.camera.x;
	data->player.camera.x = data->player.camera.x * cos(-rotSpeed)
		- data->player.camera.y * sin(-rotSpeed);
	data->player.camera.y = old_plane_x * sin(-rotSpeed)
		+ data->player.camera.y * cos(-rotSpeed);
}

void	ft_left_player(t_cub3d *data, const double rotSpeed)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = data->player.direction.x;
	data->player.direction.x = data->player.direction.x * cos(rotSpeed)
		- data->player.direction.y * sin(rotSpeed);
	data->player.direction.y = old_dir_x * sin(rotSpeed)
		+ data->player.direction.y * cos(rotSpeed);
	old_plane_x = data->player.camera.x;
	data->player.camera.x = data->player.camera.x * cos(rotSpeed)
		- data->player.camera.y * sin(rotSpeed);
	data->player.camera.y = old_plane_x * sin(rotSpeed)
		+ data->player.camera.y * cos(rotSpeed);
}
