/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_floor_ceil.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:20:49 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/16 10:37:54 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_ceiling_floor(t_data *datas, t_env *env)
{
	draw_rect(datas, (t_coordinates){0, 0}, (t_coordinates){WIDTH, \
		HEIGHT / 2}, env->g_colors[CODE_CEILING].color);
	draw_rect(datas, (t_coordinates){0, HEIGHT / 2}, (t_coordinates) \
		{WIDTH, HEIGHT}, env->g_colors[CODE_FLOOR].color);
}

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
