/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:37:36 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 15:54:18 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	char_color(char c)
{
	const char	color[12] = "0123456789,";
	int			i;

	if (c == '-')
		exit(ft_error("Error\nDo not use simbol + or -\n"));
	i = 0;
	while (color[i])
	{
		if (color[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	check_color(char *color)
{
	int	i;

	i = 0;
	while (color[i] && color[i] != ' ' && color[i] != '\t' && color[i] != '\n')
	{
		if (char_color(color[i]))
			return (1);
		i++;
	}
	return (0);
}

int	convert_rgb_to_hex(char *color)
{
	int					j;
	int					i;
	unsigned long int	hex_color;
	char				*col;

	j = ((hex_color = 0), 3);
	while (--j >= 0)
	{
		i = goto_pattern(color, ",");
		col = ft_strdup_len(color, i);
		color = skip_pattern(color, "0123456789");
		if (!col || !col[0] || col[0] == ',')
			exit(ft_error("Error\nInvalid color,\
				permited->(0-255,0-255,0-255)\n"));
		color++;
		i = ft_atoi(col);
		if (i > 255 || i < 0)
			exit(ft_error("Error\nValid range->0-255\n"));
		if (i > 0)
			hex_color += i * (int)pow(256, j);
		free(col);
	}
	if ((*color && *color != ' ' && *color
			!= '\n' && *color != '\t') || *--color == ',')
		exit(ft_error("Error\nInvalid color, permited->(0-255,0-255,0-255)\n"));
	return (hex_color);
}

void	get_color(enum e_identifier id, int *color, char *path)
{
	int	hex_color;

	hex_color = convert_rgb_to_hex(path);
	if (id == C && color[0] == 0)
		color[0] = hex_color;
	else if (id == F && color[1] == 0)
		color[1] = hex_color;
	else
		exit(ft_error("Error\nColor duplicated???"));
}

int	parse_color(enum e_identifier id, int *color, char *path)
{
	int		i;
	char	*tmp;

	path = skip_pattern(path, " \t");
	if (!*path || *path == '\n')
		exit(ft_error("Error\nFound C/F  but color not specified\n"));
	i = goto_pattern(path, " \t\n");
	if (path[i] && path[i] != '\n')
	{
		tmp = skip_pattern(&path[i], " \t");
		if (*tmp != 0 && *tmp != '\n')
			exit(ft_error("Error\nInvalid path\n"));
	}
	if (check_color(path))
		exit(ft_error("Error\nInvalid color or found invalid caracter\n"));
	get_color(id, color, path);
	return (0);
}
