/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:08:27 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/12 15:57:31 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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
	return (EXIT_SUCCESS);
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
