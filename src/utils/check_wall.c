/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:26:23 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 15:43:35 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_wall(char **map)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == FLOOR || !check_character(map[x][y]))
			{
				if (floor_not_surround_by_wall(map, x, y))
					return (ft_error("Error\nMap not surrounded\n"));
			}
			if (map[x][y] == VOID)
			{
				if (void_surronded_by_floor(map, x, y))
					return (ft_error("Error\nMap not surrounded\n"));
			}
		}
	}
	return (0);
}
