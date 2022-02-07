/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pictures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:00:07 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/07 10:44:25 by chbadad          ###   ########.fr       */
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
	mlx_put_image_to_window(env->mlx, env->win, env->imgs[i].img, 0, 0);
}
