/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_src_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/09 14:49:27 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	set_src_map(t_env *env, char const *argv[])
{
	int	s1;
	int	s2;

	s1 = ft_strlen(MAP_EXT);
	s2 = ft_strlen(argv[1]);
	if (ft_memcmp(MAP_EXT, argv[1] + s2 - s1, s1) != 0)
	{
		printf("Error, the first argument has a wrong extension fit.\n %s", \
		USAGE);
		exit(EXIT_ARGS_FAILURE);
	}
	env->conf.map_src = argv[1];
	env->direction.x = 1;
	env->direction.y = 0;
	env->plane.x = 0.0;
	env->plane.y = 0.66;
}

double	init_rad(char c)
{
	if (c == DIR_WEST)
		return (M_PI);
	else if (c == DIR_NORTH)
		return (M_PI / 2);
	else if (c == DIR_SOUTH)
		return ((3 * M_PI) / 2);
	else if (c == DIR_EAST)
		return (0);
	return (-EXIT_FAILURE);
}
