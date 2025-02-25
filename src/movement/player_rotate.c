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
	const double			old_plane_x = data->player.camera.x;
	const double	old_dir_x = data->player.direction.x;
	const	double	cos_rot = cos(-rot_speed);
	const	double	sin_rot= sin(-rot_speed);

	data->player.direction.x = data->player.direction.x * cos_rot
		- data->player.direction.y * sin_rot;
	data->player.direction.y = old_dir_x * sin_rot
		+ data->player.direction.y * cos_rot;
	data->player.camera.x = data->player.camera.x * cos_rot
		- data->player.camera.y * sin_rot;
	data->player.camera.y = old_plane_x * sin_rot 
		+ data->player.camera.y * cos_rot;
}

void	ft_left_player(t_cub3d *data, const double rot_speed)
{
	const double	old_plane_x = data->player.camera.x;
	const double	old_dir_x = data->player.direction.x;
	const double	sin_rot = sin(rot_speed);
	const double	cos_rot = cos(rot_speed);

	data->player.direction.x = data->player.direction.x * cos_rot
		- data->player.direction.y * sin_rot;
	data->player.direction.y = old_dir_x * sin_rot
		+ data->player.direction.y * cos_rot;
	data->player.camera.x = data->player.camera.x * cos_rot
		- data->player.camera.y * sin_rot;
	data->player.camera.y = old_plane_x * sin_rot
		+ data->player.camera.y * cos_rot;
}
