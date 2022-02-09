/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line_for_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/08 12:36:16 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	id_dir(int x, int y, char c, t_env *env)
{
	double			dir_rad;
	t_coordinates	co;
	t_coordinates	plane;

	if (env->player_start.is_set == 1)
		return (-EXIT_FAILURE);
	env->player_start = (t_start){(t_coordinates){y + 0.5F, x + 0.5F}, 1, c};
	if (c == DIR_WEST)
		dir_rad = M_PI;
	else if (c == DIR_NORTH)
		dir_rad = M_PI / 2;
	else if (c == DIR_SOUTH)
		dir_rad = (3 * M_PI) / 2;
	else if (c == DIR_EAST)
		dir_rad = 0;
	else
		return (-EXIT_FAILURE);
	co = env->direction;
	plane = env->plane;
	env->direction.x = env->direction.x * cos(-dir_rad) - env->direction.y * sin(-dir_rad);
	env->direction.y = co.x * sin(-dir_rad) + env->direction.y * cos(-dir_rad);
	env->plane.x = env->plane.x * cos(-dir_rad) - env->plane.y * sin(-dir_rad);
	env->plane.y = plane.x * sin(-dir_rad) + env->plane.y * cos(-dir_rad);
	return (EXIT_SUCCESS);
}

int	id_mob(int i, int j, char c, t_env *env)
{
	(void)i;
	(void)j;
	(void)c;
	(void)env;
	return (EXIT_SUCCESS);
}

static const t_map_parsing	g_map_parsings[3] = {
	(t_map_parsing){AUTHORIZED_ON_MAP, NULL, -1},
	(t_map_parsing){AUTHORIZED_ON_MAP_MOB, &id_mob, -1},
	(t_map_parsing){AUTHORIZED_ON_MAP_DIR, &id_dir, '0'},
};

char	*test_line_for_map_int(char *line, t_env *env, int x, int y)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = 0;
	while (i < MAX_MAP_PARSING)
	{
		ret = ft_strchr(g_map_parsings[i].authorized_chars, line[y]);
		if (ret != NULL)
		{
			if (g_map_parsings[i].parser)
				if (g_map_parsings[i].parser(x, y, line[y], env) \
				< EXIT_SUCCESS)
					return (NULL);
			if (g_map_parsings[i].replace != -1)
				line[y] = g_map_parsings[i].replace;
			break ;
		}
		i++;
	}
	return (ret);
}

int	test_line_for_map(char *line, t_env *env, int x)
{
	int		y;
	char	*ret;

	y = 0;
	ret = NULL;
	while (line[y])
	{
		ret = test_line_for_map_int(line, env, x, y);
		if (ret == NULL)
			return (-EXIT_FAILURE);
		y++;
	}
	return (y);
}
