/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:52:35 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 15:46:23 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	max_line(char **matrix)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (matrix[i])
	{
		if (ret < ft_strlen(matrix[i]))
			ret = ft_strlen(matrix[i]);
		i++;
	}
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

int	**matomi(char **matrix, int *line)
{
	int	i;
	int	j;
	int	**result;

	result = malloc(sizeof(int *) * ft_strlen_double(matrix));
	i = 0;
	*line = max_line(matrix);
	while (matrix[i])
	{
		result[i] = malloc(sizeof(int) * *line);
		j = 0;
		while (matrix[i][j] && j < *line)
		{
			if (!check_character(matrix[i][j]))
				character(matrix[i][j], &result[i][j]);
			else if (matrix[i][j] == '\n' || matrix[i][j] == ' ')
				result[i][j] = 1;
			else
				result[i][j] = matrix[i][j] - '0';
			j++;
		}
		i++;
	}
	return (result);
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
