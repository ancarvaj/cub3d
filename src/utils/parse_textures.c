/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:09 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 18:13:30 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	get_textures(char **content, t_textures *textures)
{
	int					i;
	char				*path;
	enum e_identifier	tmp;

	i = 0;
	tmp = ERR;
	while (content[i])
	{
		path = get_texture_path(content[i], &tmp);
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

char	*get_texture_path(char *line, enum e_identifier *tmp)
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
