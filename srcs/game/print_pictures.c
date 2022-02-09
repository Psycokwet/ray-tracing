/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pictures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:00:07 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/09 14:50:52 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_ceiling_floor(t_data *datas, t_env *env)
{
	draw_rect(datas, (t_coordinates){0, 0}, (t_coordinates){WIDTH, \
		HEIGHT / 2}, env->g_colors[CODE_CEILING].color);
	draw_rect(datas, (t_coordinates){0, HEIGHT / 2}, (t_coordinates) \
		{WIDTH, HEIGHT}, env->g_colors[CODE_FLOOR].color);
}

int	get_text_x(t_texture *tex, t_env *env, t_ray *ray)
{
	int	text_x;

	text_x = (int)(ray->wall_x * (double)tex->texture->w);
	if (env->side == 0 && ray->dir.x > 0)
		text_x = tex->texture->w - text_x - 1;
	if (env->side == 1 && ray->dir.y < 0)
		text_x = tex->texture->w - text_x - 1;
	return (text_x);
}

void	get_texture(t_env *env, t_texture *text, t_ray *ray)
{
	if (env->side == 1)
	{
		if (ray->dir.y > 0)
			text->texture = &env->textures[CODE_NO];
		if (ray->dir.y < 0)
			text->texture = &env->textures[CODE_SO];
	}
	else if (env->side == 0)
	{
		if (ray->dir.x > 0)
			text->texture = &env->textures[CODE_EA];
		if (ray->dir.x < 0)
			text->texture = &env->textures[CODE_WE];
	}
}

void	texturing(t_data *datas, int x, t_env *env, t_ray *ray)
{
	t_texture	tex;
	double		step;
	int			y;

	get_texture(&(*env), &tex, &(*ray));
	tex.texture_x = get_text_x(&tex, &(*env), &(*ray));
	step = 1.0 * tex.texture->h / env->lineheight;
	tex.texture_position = (env->draw_start - HEIGHT / 2 \
		+ env->lineheight / 2) * step;
	y = env->draw_start;
	while (y < env->draw_end)
	{
		tex.texture_y = (int)tex.texture_position & (tex.texture->h - 1);
		tex.texture_color = ((int *)tex.texture->addr)[tex.texture->h \
			* tex.texture_y + tex.texture_x];
		my_mlx_pixel_put(datas, x, y, tex.texture_color);
		tex.texture_position += step;
		y++;
	}
}

int	print_img(t_env *env)
{
	int	i;

	i = 0;
	if (env->imgs[i].img != NULL)
		mlx_destroy_image(env->mlx, env->imgs[i].img);
	env->imgs[i].img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->imgs[i].addr = mlx_get_data_addr(env->imgs[i].img, \
	&env->imgs[i].bits_per_pixel, &env->imgs[i].line_length, \
	&env->imgs[i].endian);
	draw_ceiling_floor(&env->imgs[i], env);
	draw_walls(&env->imgs[i], &(*env));
	mlx_put_image_to_window(env->mlx, env->win, env->imgs[i].img, 0, 0);
	return (1);
}
