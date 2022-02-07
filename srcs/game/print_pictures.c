/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pictures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:00:07 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/07 18:05:02 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_rect(t_data *datas, t_coordinates start, \
	t_coordinates end, int color)
{
	int	x;
	int	y;

	x = start.x;
	y = start.y;
	while (y < end.y)
	{
		while (x < end.x)
		{
			my_mlx_pixel_put(datas, x, y, color);
			x++;
		}
		x = start.x;
		y++;
	}
}

void	draw_ceiling_floor(t_data *datas, t_env *env)
{
	draw_rect(datas, (t_coordinates){0, 0}, (t_coordinates){env->r.width, \
		env->r.height / 2}, env->g_colors[CODE_CEILING].color);
	draw_rect(datas, (t_coordinates){0, env->r.height / 2}, (t_coordinates) \
		{env->r.width, env->r.height}, env->g_colors[CODE_FLOOR].color);
}

double	ft_abs(double nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

void	stepping(t_env *env, t_ray *ray)
{
	int	map_x;
	int	map_y;

	map_x = (int)env->current_pos.x;
	map_y = (int)env->current_pos.y;
	if (ray->dir.x < 0)
	{
		ray->step_X = -1;
		ray->side_dist.x = (env->current_pos.x - map_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_X = 1;
		ray->side_dist.x = (map_x + 1.0 - env->current_pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_Y = -1;
		ray->side_dist.y = (env->current_pos.y - map_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_Y = 1;
		ray->side_dist.y = (map_y + 1.0 - env->current_pos.y) * ray->delta_dist.y;
	}
}

void	wall_hit(t_env *env, t_ray *ray)
{
	int	hit;
	int	map_x;
	int	map_y;

	map_x = (int)env->current_pos.x;
	map_y = (int)env->current_pos.y;
	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			map_x += ray->step_X;
			env->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			map_y += ray->step_Y;
			env->side = 1;
		}
		if (env->map_char[map_y][map_x] == '1')
			hit = 1;
	}
	ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
	if (env->side == 0)
		ray->perp_wall_dist = (ray->side_dist.x - ray->delta_dist.x);
}

int	get_text_x(t_env *env, t_ray *ray)
{
	int	text_x;

	text_x = (int)ray->wall_x * (double)env->textures[0].w;
	if (env->side == 0 && ray->dir.x > 0)
		text_x = env->textures[0].w - text_x - 1;
	if (env->side == 1 && ray->dir.y < 0)
		text_x = env->textures[0].w - text_x - 1;
	return (text_x);
}

void	lineheight(t_env *env, t_ray *ray)
{
	int	pitch;

	pitch = 100;
	env->lineheight = (int)(HEIGHT / ray->perp_wall_dist);
	env->draw_start = -env->lineheight / 2 + HEIGHT / 2;
	if (env->draw_start < 0)
		env->draw_start = 0;
	env->draw_end = env->lineheight / 2 + HEIGHT / 2;
	if (env->draw_end >= HEIGHT)
		env->draw_end = HEIGHT - 1;
	if (env->side == 0)
		ray->wall_x = env->current_pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		ray->wall_x = env->current_pos.x + ray->perp_wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	texturing(t_data *datas, int x, t_env *env, t_ray *ray)
{
	t_texture	tex;
	double		step;
	int			y;

	tex.texture = &env->textures[0];
	tex.texture_x = get_text_x(&(*env), &(*ray));
	step = 1.0 * tex.texture->h / env->lineheight;
	tex.texture_position = (env->draw_start - HEIGHT / 2 + env->lineheight / 2) * step;
	y = env->draw_start;
	while (y < env->draw_end)
	{
		tex.texture_y = (int)tex.texture_position & (tex.texture->h - 1);
		tex.texture_color = ((int *)tex.texture->addr)[(tex.texture->line_length / 4) \
			* tex.texture_y + tex.texture_x];
		my_mlx_pixel_put(datas, x, y, tex.texture_color);
		tex.texture_position += step;
		y++;
	}
}

void	draw_walls(t_data *datas, t_env *env)
{
	t_coordinates	cam;
	t_ray			ray;
	int				x;

	x = 0;
	env->plane.x = 0.0;
	env->plane.y = 0.66;
	while (x < WIDTH)
	{
		cam.x = 2 * x / (double)WIDTH - 1;
		ray.dir.x = env->direction.x + env->plane.x * cam.x;
		ray.dir.y = env->direction.y + env->plane.y * cam.x;
		ray.delta_dist.x = 1e30;
		ray.delta_dist.y = 1e30;
		if (ray.dir.x != 0)
			ray.delta_dist.x = ft_abs(1 / ray.dir.x);
		if (ray.dir.y != 0)
			ray.delta_dist.y = ft_abs(1 / ray.dir.y);
		stepping(&(*env), &ray);
		wall_hit(&(*env), &ray);
		lineheight(&(*env), &ray);
		texturing(&(*datas), x, &(*env), &ray);
		x++;
	}
}

void	print_img(t_env *env)
{
	int	i;

	i = 0;
	if (env->imgs[i].img != NULL)
		mlx_destroy_image(env->mlx, env->imgs[i].img);
	env->imgs[i].img = mlx_new_image(env->mlx, env->r.width, env->r.height);
	env->imgs[i].addr = mlx_get_data_addr(env->imgs[i].img, \
	&env->imgs[i].bits_per_pixel, &env->imgs[i].line_length, \
	&env->imgs[i].endian);
	draw_ceiling_floor(&env->imgs[i], env);
	draw_walls(&env->imgs[i], &(*env));
	mlx_put_image_to_window(env->mlx, env->win, env->imgs[i].img, 0, 0);
}
