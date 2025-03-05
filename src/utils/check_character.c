/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:49:18 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/03/05 13:47:57 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_character(char c)
{
	const char		character[6] = "NSEW";
	int				i;

	i = 0;
	while (character[i])
	{
		if (character[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	character_in_map(char **map)
{
	int	i;
	int	j;
	int	character;

	i = -1;
	character = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!check_character(map[i][j]))
			{
				if (character == 1)
					return (ft_error("Error\nFound more than one character\n"));
				character = 1;
			}
		}
	}
	if (character == 0)
		return (ft_error("Error\nThere is not a character\n"));
	return (0);
}

int	ft_check_map_char(char **map)
{
	int	i;
	int	j;

	if (character_in_map(map))
		return (1);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_is_map(map[i][j]))
				return (ft_error("Error\nMap has invalid char\n"));
			j++;
		}
		i++;
	}
	return (0);
}
