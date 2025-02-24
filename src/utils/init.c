/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:58:12 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/24 16:25:13 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(ft_error("Error\nFailed connecting with graphical server\n"));
	mlx->img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!mlx->img)
		exit(ft_error("Error\nFailed creating image\n"));
	mlx->_img.address = mlx_get_data_addr(mlx->img, &mlx->_img.bpp,
			&mlx->_img.size_line, &mlx->_img.endian);
}

void	cub3d_init(t_cub3d *cub3d, char **file_content)
{
	textures_init(&cub3d->textures, file_content);
	map_init(&cub3d->map, get_map(file_content));
	player_init(&cub3d->player, &cub3d->map);
	my_mlx_init(&cub3d->mlx);
	load_textures(&cub3d->textures, &cub3d->mlx);
}

void	player_init(t_player *player, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->dimension.height)
	{
		j = 0;
		while (j < map->dimension.width)
		{
			if (map->map[i][j] > 1)
			{
				get_player_direction(player, map->map[i][j]);
				map->map[i][j] = 0;
				player->position.x = i + 0.0;
				player->position.y = j + 0.0;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	textures_init(t_textures *textures, char **file_content)
{
	int	i;

	i = -1;
	while (++i < TEXTURE_NUM)
	{
		textures->texture_path[i] = NULL;
		textures->texture[i] = NULL;
		textures->_texture[i].address = NULL;
		textures->_texture[i].endian = 0;
		textures->_texture[i].bpp = 0;
		textures->_texture[i].size_line = 0;
	}
	i = -1;
	while (++i < COLOR_NUM)
		textures->color[i] = 0;
	get_textures(file_content, textures);
}

void	map_init(t_map *map, char **char_map)
{
	map->dimension.width = 0;
	map->dimension.height = 0;
	map->map = matomi(char_map, &map->dimension.height, &map->dimension.width);
}
