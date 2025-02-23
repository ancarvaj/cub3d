/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:54:30 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/22 15:57:50 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	ft_check_file_elements(char **file)
{
	int						i;
	enum e_identifier		identifier_tmp;
	unsigned char			file_identifiers;

	file_identifiers = 0;
	i = 0;
	while (file[i])
	{
		identifier_tmp = ft_identifier(file[i]);
		if (identifier_tmp == ERR)
			return (ft_error("Error\nNot valid identifier\n"));
		if (identifier_tmp == MAP_CHAR)
		{
			if (file_identifiers == CORRECT_IDENTIFIER
				&& !ft_check_map_char(&file[i])
				&& !ft_check_map_wall(&file[i]))
				return (0);
			return (ft_error("Error\nInvaid file content\n"));
		}
		file_identifiers += identifier_tmp;
		i++;
	}
	return (ft_error("Error\nNo idea, but there is an error\n"));
}

char	*get_path(char *line, enum e_identifier *tmp)
{
	int		i;
	char	*ident;

	line = skip_pattern(line, " \n");
	if (!*line || *line == '\n')
		return (0);
	i = goto_pattern(line, " \t\n");
	ident = ft_strdup_len(line, i);
	*tmp = ft_get_identifier(ident);
	free(ident);
	return (line + i);
}
