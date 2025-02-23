/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:23:39 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/22 15:25:48 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

enum e_identifier	ft_get_identifier(const char *line)
{
	if (!ft_strncmp("NO", line, ft_strlen(line) + 1))
		return (NO);
	if (!ft_strncmp("SO", line, ft_strlen(line) + 1))
		return (SO);
	if (!ft_strncmp("WE", line, ft_strlen(line) + 1))
		return (WE);
	if (!ft_strncmp("EA", line, ft_strlen(line) + 1))
		return (EA);
	if (!ft_strncmp("F", line, ft_strlen(line) + 1))
		return (F);
	if (!ft_strncmp("C", line, ft_strlen(line) + 1))
		return (C);
	if (!ft_is_map(line[0]))
		return (MAP_CHAR);
	return (ERR);
}

//north, southm east, west
int	set_texture(char **files, char *path, enum e_identifier id)
{
	if (id == NO)
	{
		if (!files[0])
			return (files[0] = path, 0);
	}
	else if (id == SO)
	{
		if (!files[1])
			return (files[1] = path, 0);
	}
	else if (id == EA)
	{
		if (!files[2])
			return (files[2] = path, 0);
	}
	else if (id == WE)
	{
		if (!files[3])
			return (files[3] = path, 0);
	}
	return (free(path), 1);
}

char	*skip_pattern(char *s, char const *follow)
{
	int	i;

	i = 0;
	while (s[i] && ft_strchr(follow, s[i]))
		i++;
	return (&s[i]);
}

int	goto_pattern(char const *s, char *skip)
{
	int	i;

	i = 0;
	while (s[i] && !ft_strchr(skip, s[i]))
		i++;
	return (i);
}

int	parse_texture(enum e_identifier id, char **files, char *texture)
{
	int		i;
	char	*tmp;

	texture = skip_pattern(texture, " \t");
	if (!*texture || *texture == '\n')
		exit(ft_error("Error\nFound identifier but no path\n"));
	i = goto_pattern(texture, " \t\n");
	if (texture[i] && texture[i] != '\n')
	{
		tmp = skip_pattern(&texture[i], " \t");
		if (*tmp != 0 && *tmp != '\n')
			exit(ft_error("Error\nNot valid path\n"));
	}
	if (set_texture(files, ft_strdup_len(texture, i), id))
		exit(ft_error("Error\nDuplicated texture????????\n"));
	return (0);
}
