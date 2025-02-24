/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:52:10 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/24 16:54:06 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_dir(double x, double y, t_point *direction)
{
	direction->x = x;
	direction->y = y;
}

void	set_player_camera(double x, double y, t_point *camera)
{
	camera->x = x;
	camera->y = y;
}

void	get_player_direction(t_player *player, int vector)
{
	if (vector == NORTH)
	{
		set_player_dir(-1, 0, &player->direction);
		set_player_camera(0, 0.66, &player->camera);
	}
	else if (vector == SOUTH)
	{
		set_player_dir(1, 0, &player->direction);
		set_player_camera(0, -0.66, &player->camera);
	}
	else if (vector == EAST)
	{
		set_player_dir(0, 1, &player->direction);
		set_player_camera(0.66, 0, &player->camera);
	}
	else if (vector == WEST)
	{
		set_player_dir(0, -1, &player->direction);
		set_player_camera(-0.66, 0, &player->camera);
	}
}
