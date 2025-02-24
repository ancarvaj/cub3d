/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:54:30 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/24 17:38:01 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (ft_error("Error\nNo idea, but there is an error, \
let me guess...no map?\n"));
}
