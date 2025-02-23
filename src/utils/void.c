/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:37:01 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 15:40:11 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	void_not_surronded_up(char **map, int x, int y)
{
	while (x >= 0 && map[x])
	{
		if (ft_strlen(map[x]) >= y)
		{
			if (map[x][y] == FLOOR)
				return (1);
			if (map[x][y] == WALL)
				return (0);
		}
		x = x - 1;
	}
	return (0);
}

int	void_not_surronded_down(char **map, int x, int y)
{
	while (x >= 0 && map[x])
	{
		if (ft_strlen(map[x]) >= y)
		{
			if (map[x][y] == FLOOR)
				return (1);
			if (map[x][y] == WALL)
				return (0);
		}
		x = x + 1;
	}
	return (0);
}

int	void_not_surronded_left(char **map, int x, int y)
{
	while (map[x] && y >= 0 && map[x][y])
	{
		if (map[x][y] == FLOOR)
			return (1);
		if (map[x][y] == WALL)
			return (0);
		y = y - 1;
	}
	return (0);
}

int	void_not_surronded_right(char **map, int x, int y)
{
	while (map[x] && y >= 0 && map[x][y])
	{
		if (map[x][y] == FLOOR)
			return (1);
		if (map[x][y] == WALL)
			return (0);
		y = y + 1;
	}
	return (0);
}

int	void_surronded_by_floor(char **map, int x, int y)
{
	if (void_not_surronded_up(map, x, y))
		return (1);
	if (void_not_surronded_down(map, x, y))
		return (1);
	if (void_not_surronded_left(map, x, y))
		return (1);
	if (void_not_surronded_right(map, x, y))
		return (1);
	return (0);
}
