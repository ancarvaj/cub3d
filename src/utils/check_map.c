/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:38:41 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/03/05 13:47:51 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map(char **map)
{
	if (ft_check_map_char(map))
		return (1);
	if (ft_check_map_wall(map))
		return (1);
	return (0);
}

int	ft_is_map(char c)
{
	const char	map[10] = "01NSEW \n";
	int			i;

	i = 0;
	while (map[i])
	{
		if (c == map[i])
			return (0);
		i++;
	}
	return (1);
}
