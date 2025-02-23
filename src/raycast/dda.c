/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:55:08 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 17:12:46 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dda_params(t_raycast *ray, t_player *player)
{
	ray->map.x = (int)player->position.x;
	ray->map.y = (int)player->position.y;
	ray->delta_dist.x = fabs(safe_divide(1, ray->ray_dir.x));
	ray->delta_dist.y = fabs(safe_divide(1, ray->ray_dir.y));
}

void	set_step_and_side(t_raycast *ray, t_player *player)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->position.x
				- ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0
				- player->position.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->position.y
				- ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0
				- player->position.y) * ray->delta_dist.y;
	}
}

void	perform_dda(t_raycast *ray, t_map *map, int *side)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			*side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			*side = 1;
		}
		if (map->map[ray->map.x][ray->map.y] > 0)
			hit = 1;
	}
}
