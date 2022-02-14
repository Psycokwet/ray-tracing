/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:53:46 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/14 11:04:32 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_walls(t_data *datas, t_env *env)
{
	t_coordinates	cam;
	t_ray			ray;
	int				x;

	x = 0;
	while (x < WIDTH)
	{
		cam.x = 2 * x / (double)WIDTH - 1;
		ray.dir.x = env->direction.x + env->plane.x * cam.x;
		ray.dir.y = env->direction.y + env->plane.y * cam.x;
		if (ray.dir.x == 0)
			ray.delta_dist.x = 100000000000;
		else
			ray.delta_dist.x = fabs(1 / ray.dir.x);
		if (ray.dir.y == 0)
			ray.delta_dist.y = 100000000000;
		else
			ray.delta_dist.y = fabs(1 / ray.dir.y);
		stepping(&(*env), &ray);
		wall_hit(&(*env), &ray, 0);
		lineheight(&(*env), &ray);
		texturing(&(*datas), x, &(*env), &ray);
		x++;
	}
}

void	stepping(t_env *env, t_ray *ray)
{
	int	mx;
	int	my;

	mx = (int)env->current_pos.x;
	my = (int)env->current_pos.y;
	if (ray->dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (env->current_pos.x - mx) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (mx + 1.0 - env->current_pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (env->current_pos.y - my) * ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (my + 1.0 - env->current_pos.y) * ray->delta_dist.y;
	}
}

static bool	is_hit(t_env *env, int x, int y)
{
	return (env->map_char[y][x] == '1' || env->map_char[y][x] == '2'
		|| env->map_char[y][x] == 'N' || env->map_char[y][x] == 'S'
		|| env->map_char[y][x] == 'E' || env->map_char[y][x] == 'W');
}


void	wall_hit(t_env *env, t_ray *ray, int hit)
{
	env->map_x = (int)env->current_pos.x;
	env->map_y = (int)env->current_pos.y;
	while (hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			env->map_x += ray->step_x;
			env->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			env->map_y += ray->step_y;
			env->side = 1;
		}
		if (is_hit(&(*env), env->map_x, env->map_y))
			hit = 1;
	}
	ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
	if (env->side == 0)
		ray->perp_wall_dist = (ray->side_dist.x - ray->delta_dist.x);
}

void	lineheight(t_env *env, t_ray *ray)
{
	env->lineheight = (int)(HEIGHT / ray->perp_wall_dist);
	env->draw_start = -env->lineheight / 2 + HEIGHT / 2;
	if (env->draw_start < 0)
		env->draw_start = 0;
	env->draw_end = env->lineheight / 2 + HEIGHT / 2;
	if (env->draw_end >= HEIGHT)
		env->draw_end = HEIGHT;
	if (env->side == 0)
		ray->wall_x = env->current_pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		ray->wall_x = env->current_pos.x + ray->perp_wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}
