/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:01:56 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/25 15:19:22 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_right_player(t_cub3d *data, const double rot_speed)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = data->player.direction.x;
	data->player.direction.x = data->player.direction.x * cos(-rot_speed)
		- data->player.direction.y * sin(-rot_speed);
	data->player.direction.y = old_dir_x * sin(-rot_speed)
		+ data->player.direction.y * cos(-rot_speed);
	old_plane_x = data->player.camera.x;
	data->player.camera.x = data->player.camera.x * cos(-rot_speed)
		- data->player.camera.y * sin(-rot_speed);
	data->player.camera.y = old_plane_x * sin(-rot_speed)
		+ data->player.camera.y * cos(-rot_speed);
}

void	ft_left_player(t_cub3d *data, const double rot_speed)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = data->player.direction.x;
	data->player.direction.x = data->player.direction.x * cos(rot_speed)
		- data->player.direction.y * sin(rot_speed);
	data->player.direction.y = old_dir_x * sin(rot_speed)
		+ data->player.direction.y * cos(rot_speed);
	old_plane_x = data->player.camera.x;
	data->player.camera.x = data->player.camera.x * cos(rot_speed)
		- data->player.camera.y * sin(rot_speed);
	data->player.camera.y = old_plane_x * sin(rot_speed)
		+ data->player.camera.y * cos(rot_speed);
}
