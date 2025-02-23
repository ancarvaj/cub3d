/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:37:10 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 15:42:26 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	not_surronded_up(char **map, int x, int y, char search)
{
	while (x >= 0 && map[x] && ft_strlen(map[x]) >= y)
	{
		if (map[x][y] == VOID)
			return (1);
		if (map[x][y] == search)
			return (0);
		x = x - 1;
	}
	return (1);
}

int	not_surronded_down(char **map, int x, int y, char search)
{
	while (x > 0 && map[x] && ft_strlen(map[x]) >= y)
	{
		if (map[x][y] == VOID)
			return (1);
		if (map[x][y] == search)
			return (0);
		x = x + 1;
	}
	return (1);
}

int	not_surronded_right(char **map, int x, int y, char search)
{
	while (map[x] && map[x][y])
	{
		if (map[x][y] == VOID)
			return (1);
		if (map[x][y] == search)
			return (0);
		y = y + 1;
	}
	return (1);
}

int	not_surronded_left(char **map, int x, int y, char search)
{
	while (map[x] && y >= 0 && map[x][y])
	{
		if (map[x][y] == VOID)
			return (1);
		if (map[x][y] == search)
			return (0);
		y = y - 1;
	}
	return (1);
}

int	floor_not_surround_by_wall(char **map, int x, int y)
{
	if (not_surronded_up(map, x, y, WALL))
		return (1);
	if (not_surronded_down(map, x, y, WALL))
		return (1);
	if (not_surronded_right(map, x, y, WALL))
		return (1);
	if (not_surronded_left(map, x, y, WALL))
		return (1);
	return (0);
}
