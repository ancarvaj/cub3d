/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:52:35 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/24 16:24:46 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	max_line(char **matrix)
{
	int		i;
	int		ret;
	char	*max_line;

	i = 0;
	ret = 0;
	while (matrix[i])
	{
		if (ret < ft_strlen(matrix[i]))
		{
			max_line = matrix[i];
			ret = ft_strlen(matrix[i]);
		}
		i++;
	}
	if (max_line[ret - 1] == '\n')
		ret--;
	return (ret);
}

//N->2|S->3|E->4|W->5
void	character(int character, int *position)
{
	if (character == 'N')
		*position = 2;
	if (character == 'S')
		*position = 3;
	if (character == 'E')
		*position = 4;
	if (character == 'W')
		*position = 5;
}

int	*fill_line(char *line, int width)
{
	int	i;
	int	*map_line;

	i = 0;
	map_line = malloc(sizeof(int) * width);
	while (line[i] && line[i] != '\n')
	{
		if (!check_character(line[i]))
			character(line[i], &map_line[i]);
		else if (line[i] == ' ')
			map_line[i] = 1;
		else
			map_line[i] = line[i] - '0';
		i++;
	}
	while (i < width)
	{
		map_line[i] = 1;
		i++;
	}
	return (map_line);
}

int	**matomi(char **matrix, int *map_height, int *map_width)
{
	int	i;
	int	**map;

	*map_height = ft_strlen_double(matrix);
	map = malloc(sizeof(int *) * (*map_height));
	i = 0;
	*map_width = max_line(matrix);
	while (i < *map_height)
	{
		map[i] = fill_line(matrix[i], *map_width);
		i++;
	}
	return (map);
}

char	**get_map(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (ft_identifier(file[i]) == MAP_CHAR)
			return (&file[i]);
		i++;
	}
	return (NULL);
}
