/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:23:39 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 17:49:32 by ancarvaj         ###   ########.fr       */
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

enum e_identifier	ft_identifier(char *line)
{
	int					i;
	char				*ident;
	enum e_identifier	id;

	line = skip_pattern(line, " \t");
	if (!*line || *line == '\n')
		return (0);
	i = goto_pattern(line, " \t\n");
	ident = ft_strdup_len(line, i);
	id = ft_get_identifier(ident);
	free(ident);
	return (id);
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
