/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:09 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/22 15:22:47 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_textures(char **content, t_textures *textures)
{
	int					i;
	char				*path;
	enum e_identifier	tmp;

	i = 0;
	tmp = ERR;
	while (content[i])
	{
		path = get_path(content[i], &tmp);
		if ((tmp == NO || tmp == SO || tmp == WE || tmp == EA) && path)
			parse_texture(tmp, textures->texture_path, path);
		else if ((tmp == F || tmp == C) && path)
			parse_color(tmp, textures->color, path);
		i++;
	}
}

void	load_textures(t_textures *textures, t_mlx *mlx)
{
	int	i;
	int	text_width;
	int	text_height;

	i = -1;
	while (++i < TEXTURE_NUM)
	{
		textures->texture[i] = mlx_xpm_file_to_image(mlx->mlx,
				textures->texture_path[i], &text_width, &text_height);
		if (!textures->texture[i])
			exit(ft_error("Error cargando textura\n"));
		if (text_width != TEXTURE_WIDTH || text_height != TEXTURE_HEIGHT)
			exit(ft_error("Error: La textura, no tiene el tamaño correcto"));
		textures->_texture[i].address
			= (int*)mlx_get_data_addr(textures->texture[i],
				&textures->_texture[i].bpp, &textures->_texture[i].size_line,
				&textures->_texture[i].endian);
	}
}
