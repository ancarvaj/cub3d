/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:55:48 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 17:14:04 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calculate_perp_dis(t_raycast *ray, t_player *player, int side)
{
	double	distance;

	if (side == 0)
		distance = safe_divide((ray->map.x - player->position.x
					+ (1 - ray->step.x) / 2), ray->ray_dir.x);
	else
		distance = safe_divide((ray->map.y - player->position.y
					+ (1 - ray->step.y) / 2), ray->ray_dir.y);
	return (fmax(distance, 0.1));
}
