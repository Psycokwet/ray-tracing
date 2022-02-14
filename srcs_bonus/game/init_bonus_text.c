/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:08:27 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/14 15:53:20 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	check_sprites_bonus(t_env *env)
{
	int		i;
	char	*path[5];

	path[0] = GUN0;
	path[1] = GUN1;
	path[2] = GUN2;
	path[3] = GUN3;
	path[4] = GUN4;
	i = 0;
	while (i < 5)
	{
		env->gun[i].img = mlx_xpm_file_to_image(env->mlx, \
		path[i], &env->gun[i].w, &env->gun[i].h);
		if (!env->gun[i].img)
			return (-EXIT_FAILURE);
		env->gun[i].addr = mlx_get_data_addr(env->gun[i].img, \
			&env->gun[i].bits_per_pixel, &env->gun[i] \
			.line_length, &env->gun[i].endian);
		if (!env->gun[i].img)
			return (-EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_door_bonus(t_env *env)
{
	int		i;
	char	*path[2];

	path[0] = PATHDOOROPEN;
	path[1] = PATHDOORCLOSE;
	i = 0;
	while (i < 2)
	{
		env->door[i].img = mlx_xpm_file_to_image(env->mlx, \
		path[i], &env->door[i].w, &env->door[i].h);
		if (!env->door[i].img)
			return (-EXIT_FAILURE);
		env->door[i].addr = mlx_get_data_addr(env->door[i].img, \
			&env->door[i].bits_per_pixel, &env->door[i] \
			.line_length, &env->door[i].endian);
		if (!env->door[i].img)
			return (-EXIT_FAILURE);
		i++;
	}
	return (check_sprites_bonus(&(*env)));
}

int	check_srcs_bonus(t_env *env)
{
	int		i;
	char	*path[2];

	path[0] = PATHFLOOR;
	path[1] = PATHCEIL;
	i = 0;
	while (i < 2)
	{
		env->floor_ceil[i].img = mlx_xpm_file_to_image(env->mlx, \
		path[i], &env->floor_ceil[i].w, &env->floor_ceil[i].h);
		if (!env->floor_ceil[i].img)
			return (-EXIT_FAILURE);
		env->floor_ceil[i].addr = mlx_get_data_addr(env->floor_ceil[i].img, \
			&env->floor_ceil[i].bits_per_pixel, &env->floor_ceil[i] \
			.line_length, &env->floor_ceil[i].endian);
		if (!env->floor_ceil[i].img)
			return (-EXIT_FAILURE);
		i++;
	}
	return (check_door_bonus(&(*env)));
}
