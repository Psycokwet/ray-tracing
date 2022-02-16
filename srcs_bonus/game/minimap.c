/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:31:32 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/16 10:42:13 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	get_size_col(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	draw_asset(t_env *env, t_data *data, int x_start, int y_start)
{
	int	color;
	int	y;
	int	x;

	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			color = my_mlx_pixel_get(&(*data), x, y);
			my_mlx_pixel_put(&env->imgs[0], (int)(x + x_start), \
				(int)(y + y_start), color);
			x++;
		}
		y++;
	}
}

static bool	is_fit(t_env *env, int layer)
{
	return ((int)env->current_pos.y + layer >= 0
		&& (int)env->current_pos.y + layer < get_size_col(env->map_char));
}

static char	**make_minimap_char(t_env *env)
{
	char	**str;
	int		nb;
	int		layer;
	int		i;

	str = malloc(sizeof(char *) * (16 + 1));
	if (!str)
		return (NULL);
	nb = 16;
	layer = -8;
	i = 0;
	while (nb--)
	{
		if (is_fit(&(*env), layer))
		{
			if (layer == 0)
				env->y_minmap = i;
			str[i++] = ft_strndup(&env->map_char[(int)env->current_pos.y \
				+ layer][(int)env->current_pos.x - 1], 16);
		}
		layer++;
	}
	str[i] = NULL;
	return (str);
}

void	make_map(t_env *env)
{
	int		x;
	int		y;
	char	**str;

	y = -1;
	str = make_minimap_char(&(*env));
	while (++y < get_size_col(str))
	{
		x = -1;
		while (++x < (int)ft_strlen(str[y]))
		{
			if (str[y][x])
			{
				if (x == 1 && y == env->y_minmap)
					draw_asset(env, &env->textures[0], x * 8, y * 8);
				else if (str[y][x] == '0')
					draw_asset(env, &env->textures[1], x * 8, y * 8);
				else if (is_map_wall(str[y][x]))
					draw_asset(env, &env->textures[2], x * 8, y * 8);
				else if (str[y][x] == '2')
					draw_asset(env, &env->door[1], x * 8, y * 8);
			}
		}
	}
	free_array(str);
}
