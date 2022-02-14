/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:20:44 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/14 14:17:58 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	my_mlx_pixel_gun_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (color != 0xff0000)
		*(unsigned int *)dst = color;
}

void	draw_gun(t_env *env, int img_gun)
{
	int	color;
	int	y;
	int	x;

	y = 0;
	while (y < 192)
	{
		x = 0;
		while (x < 192)
		{
			color = my_mlx_pixel_get(&env->gun[img_gun], x, y);
			my_mlx_pixel_gun_put(&env->imgs[0], x + (WIDTH - 192) / 2, \
				(int)(y + (HEIGHT - 192)), color);
			x++;
		}
		y++;
	}
}
