/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:55:38 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 17:08:52 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	safe_divide(double numerator, double denominator)
{
	if (denominator == 0.0)
		return (1e30);
	return (numerator / denominator);
}

void	calculate_ray_direction(t_raycast *ray, t_player *player, int x)
{
	const double	camera_x = 2 * x / (double)WINDOW_WIDTH - 1;

	ray->ray_dir.x = player->direction.x + player->camera.x * camera_x;
	ray->ray_dir.y = player->direction.y + player->camera.y * camera_x;
}

int	determine_texture(t_raycast *ray, int side)
{
	if (side == 0)
	{
		if (ray->ray_dir.x > 0)
			return (TEX_EAST);
		return (TEX_WEST);
	}
	else
	{
		if (ray->ray_dir.y > 0)
			return (TEX_SOUTH);
		return (TEX_NORTH);
	}
}

void	calculate_texture_x(t_raycast *ray, t_player *player,
		int side, double wall_distance)
{
	double	wall_x;

	if (side == 0)
		wall_x = player->position.y + wall_distance * ray->ray_dir.y;
	else
		wall_x = player->position.x + wall_distance * ray->ray_dir.x;
	wall_x -= floor(wall_x);
	ray->texture.x = (int)(wall_x * TEXTURE_WIDTH);
	if ((side == 0 && ray->ray_dir.x > 0) || (side == 1 && ray->ray_dir.y < 0))
		ray->texture.x = TEXTURE_WIDTH - ray->texture.x - 1;
}

void	render_frame(t_cub3d *data)
{
	int				x;
	int				side;
	t_raycast		ray;
	t_draw_params	params;

	print_floor_ceiling(data, data->textures.color[1], data->textures.color[0]);
	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		calculate_ray_direction(&ray, &data->player, x);
		init_dda_params(&ray, &data->player);
		set_step_and_side(&ray, &data->player);
		perform_dda(&ray, &data->map, &side);
		params.wall_distance = calculate_perp_dis(&ray, &data->player, side);
		params.line_height = (int)(WINDOW_HEIGHT / params.wall_distance);
		params.draw_start = -params.line_height / 2 + WINDOW_HEIGHT / 2;
		params.draw_start = fmax(params.draw_start, 0);
		params.draw_end = params.line_height / 2 + WINDOW_HEIGHT / 2;
		params.draw_end = fmin(params.draw_end, WINDOW_HEIGHT - 1);
		params.tex_num = determine_texture(&ray, side);
		params.x = x;
		calculate_texture_x(&ray, &data->player, side, params.wall_distance);
		draw_textured_column(data, &ray, params.tex_num, params);
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}
