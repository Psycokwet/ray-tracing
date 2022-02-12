/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_floor_ceil.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:20:49 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/12 15:08:06 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	stepping_floor(t_ray *ray_1, t_ray *ray_2, t_env *env)
{
	env->floor_step_x = env->row_dist * (ray_2->dir.x - ray_1->dir.x) / WIDTH;
	env->floor_step_y = env->row_dist * (ray_2->dir.y - ray_1->dir.y) / WIDTH;
	env->floor_x = env->current_pos.x + env->row_dist * ray_1->dir.x;
	env->floor_y = env->current_pos.y + env->row_dist * ray_1->dir.y;
}

void	get_cell_floor_text(t_texture *floor, t_texture *ceil, t_env *env)
{
	int	cell_x;
	int	cell_y;

	cell_x = (int)env->floor_x;
	cell_y = (int)env->floor_y;
	floor->texture = &env->floor_ceil[0];
	ceil->texture = &env->floor_ceil[1];
	floor->texture_x = (int)(floor->texture->w * (env->floor_x - cell_x)) \
		& floor->texture->w - 1;
	ceil->texture_x = (int)(ceil->texture->w * (env->floor_x - cell_x)) \
		& ceil->texture->w - 1;
	floor->texture_y = (int)(floor->texture->h * (env->floor_y - cell_y)) \
		& floor->texture->h - 1;
	ceil->texture_y = (int)(ceil->texture->h * (env->floor_y - cell_y)) \
		& ceil->texture->h - 1;
}

void	floor_ceil_cast(t_env *env, int y)
{
	int			x;
	int			cell_x;
	int			cell_y;
	t_texture	floor;
	t_texture	ceil;

	x = 0;
	while (x < WIDTH)
	{
		cell_x = (int)env->floor_x;
		cell_y = (int)env->floor_y;
		get_cell_floor_text(&floor, &ceil, &(*env));
		env->floor_x += env->floor_step_x;
		env->floor_y += env->floor_step_y;
		floor.texture_color = ((int *)floor.texture->addr) \
			[floor.texture->w * floor.texture_x + floor.texture_y];
		ceil.texture_color = ((int *)ceil.texture->addr) \
			[ceil.texture->w * ceil.texture_y + ceil.texture_x];
		my_mlx_pixel_put(&env->imgs[0], x, y, floor.texture_color);
		my_mlx_pixel_put(&env->imgs[0], x, HEIGHT - y - 1, ceil.texture_color);
		x++;
	}
}

void	draw_ceiling_floor(t_env *env)
{
	t_ray			ray_1;
	t_ray			ray_2;
	int				y;
	int				p;

	y = 0;
	while (y < HEIGHT)
	{
		ray_1.dir.x = env->direction.x - env->plane.x;
		ray_1.dir.y = env->direction.y - env->plane.y;
		ray_2.dir.x = env->direction.x + env->plane.x;
		ray_2.dir.y = env->direction.y + env->plane.y;
		p = y - HEIGHT / 2;
		env->pos_z = 0.5 * HEIGHT;
		env->row_dist = env->pos_z / p;
		stepping_floor(&ray_1, &ray_2, &(*env));
		floor_ceil_cast(&(*env), y);
		y++;
	}
}
