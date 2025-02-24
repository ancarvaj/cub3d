/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:08:08 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/24 16:28:39 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_collision(t_cub3d *data, double new_x, double new_y)
{
	const double	buffer = 0.025;
	int				i;
	int				j;

	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if (data->map.map[(int)(new_x + i * buffer)]
				[(int)(new_y + j * buffer)] == 1)
				return (1);
			j += 2;
		}
		i += 2;
	}
	return (0);
}

void	ft_up_player(t_cub3d *data, const double move_speed)
{
	double	new_x;
	double	new_y;

	if (data->map.map[(int)(data->player.position.x
			+ data->player.direction.x * (move_speed + 0.3))]
			[(int)(data->player.position.y +
			data->player.direction.y * (move_speed + 0.3))] == 1)
		return ;
	new_x = data->player.position.x + data->player.direction.x * move_speed;
	new_y = data->player.position.y + data->player.direction.y * move_speed;
	if (check_collision(data, new_x, new_y))
		return ;
	data->player.position.x = new_x;
	data->player.position.y = new_y;
}

void	ft_down_player(t_cub3d *data, const double move_speed)
{
	double	new_x;
	double	new_y;

	/*if (data->map.map[(int)(data->player.position.x
			- data->player.direction.x * (move_speed + 0.3))]
			[(int)(data->player.position.y -
			data->player.direction.y * (move_speed + 0.3))] == 1)
		return ;*/
	new_x = data->player.position.x - data->player.direction.x * move_speed;
	new_y = data->player.position.y - data->player.direction.y * move_speed;
	if (check_collision(data, new_x, new_y))
		return ;
	data->player.position.x = new_x;
	data->player.position.y = new_y;
}

void	ft_strafe_left(t_cub3d *data, const double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = data->player.position.x - data->player.camera.x * move_speed;
	new_y = data->player.position.y - data->player.camera.y * move_speed;
	if (check_collision(data, new_x, new_y))
		return ;
	data->player.position.x = new_x;
	data->player.position.y = new_y;
}

void	ft_strafe_right(t_cub3d *data, const double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = data->player.position.x + data->player.camera.x * move_speed;
	new_y = data->player.position.y + data->player.camera.y * move_speed;
	if (check_collision(data, new_x, new_y))
		return ;
	data->player.position.x = new_x;
	data->player.position.y = new_y;
}
