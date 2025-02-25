/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:04:16 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/25 19:14:21 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	char	**file_content;
	t_cub3d	cub3d;

	if (argc != 2)
		return (ft_error("Error\nInvalid number of arguments\n"));
	if (ft_check_name(argv[1]))
		return (1);
	file_content = ft_get_file_content(argv[1]);
	if (!file_content)
		return (1);
	if (ft_check_file_elements(file_content))
	{
		ft_free_double(file_content);
		return (1);
	}
	cub3d_init(&cub3d, file_content);
	game_start(&cub3d);
	return (0);
}
