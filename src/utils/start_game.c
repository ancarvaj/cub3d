/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:42:51 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 15:00:59 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_window(t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	if (!mlx->win)
		exit(ft_error("Error\nFailed creating window\n"));
}

int	ft_close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

void	game_start(t_cub3d *cub3d)
{
	create_window(&cub3d->mlx);
	render_frame(cub3d);
	mlx_hook(cub3d->mlx.win, 2, 1l << 0, key_press, cub3d);
	mlx_hook(cub3d->mlx.win, 17, 0, ft_close_window, &cub3d->mlx);
	mlx_loop(cub3d->mlx.mlx);
}
