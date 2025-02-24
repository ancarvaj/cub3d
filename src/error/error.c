/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:05:28 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/24 17:42:07 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	ft_error(char const *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

int	ft_check_name(char const *fmap)
{
	int	len;

	if (!fmap || !fmap[0])
		return (ft_error("Error\nPlease enter a map name\n"));
	len = ft_strlen(fmap) - 1;
	if (fmap[len--] != 'b')
		return (ft_error("Error\nThis is not a valid map extension\n"));
	if (fmap[len--] != 'u')
		return (ft_error("Error\nThis is not a valid map extension\n"));
	if (fmap[len--] != 'c')
		return (ft_error("Error\nThis is not a valid map extension\n"));
	if (fmap[len--] != '.')
		return (ft_error("Error\nThis is not a valid map extension\n"));
	if (len == -1 || fmap[len] == '/')
		return (ft_error("Error\nIf a file starts with . is a hidden\
 file not an extension\n"));
	return (0);
}
