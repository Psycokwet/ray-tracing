/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line_for_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/05/04 22:34:51 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"

int		id_dir(int i, int j, char c, t_env *env)
{
	if (env->player_start.is_set == 1)
		return (-EXIT_FAILURE);
	env->player_start = (t_start){(t_coordinates){i + 0.5F, j + 0.5F}, 1, c};
	if (c == DIR_WEST)
		env->direction = (t_coordinates){-1, 0};
	else if (c == DIR_NORTH)
		env->direction = (t_coordinates){0, -1};
	else if (c == DIR_SOUTH)
		env->direction = (t_coordinates){0, 1};
	else if (c == DIR_EAST)
		env->direction = (t_coordinates){1, 0};
	else
		return (-EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
** Je sais pas encore quoi foutre avec ça
*/

int		id_mob(int i, int j, char c, t_env *env)
{
	(void)i;
	(void)j;
	(void)c;
	(void)env;
	return (EXIT_SUCCESS);
}

#define MAX_MAP_PARSING 3

static const t_map_parsing g_map_parsings[3] = {
	(t_map_parsing){AUTHORIZED_ON_MAP, NULL, -1},
	(t_map_parsing){AUTHORIZED_ON_MAP_MOB, &id_mob, -1},
	(t_map_parsing){AUTHORIZED_ON_MAP_DIR, &id_dir, '0'},
};

char	*test_line_for_map_int(char *line, t_env *env, int i)
{
	int		j;
	char	*ret;

	ret = NULL;
	j = 0;
	while (j < MAX_MAP_PARSING)
	{
		ret = ft_strchr(g_map_parsings[j].authorized_chars, line[i]);
		if (ret != NULL)
		{
			if (g_map_parsings[j].parser)
				if (g_map_parsings[j].parser(i, j, line[i], env)
				< EXIT_SUCCESS)
					return (NULL);
			if (g_map_parsings[j].replace != -1)
				line[i] = g_map_parsings[j].replace;
			break ;
		}
		j++;
	}
	return (ret);
}

int		test_line_for_map(char *line, t_env *env)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (line[i])
	{
		ret = test_line_for_map_int(line, env, i);
		if (ret == NULL)
			return (-EXIT_FAILURE);
		i++;
	}
	return (i);
}
