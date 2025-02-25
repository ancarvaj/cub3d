/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:42:51 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/25 19:24:08 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_start(t_cub3d *cub3d)
{
	create_window(&cub3d->mlx);
	render_frame(cub3d);
	mlx_hook(cub3d->mlx.win, 2, 1l << 0, key_press, cub3d);
	mlx_hook(cub3d->mlx.win, 17, 0, ft_close_window, &cub3d->mlx);
	mlx_loop(cub3d->mlx.mlx);
}
