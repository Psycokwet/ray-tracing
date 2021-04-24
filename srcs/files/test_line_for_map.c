/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line_for_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/24 18:27:49 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"

int		id_dir(int i, int j, char c, t_env *env)
{
	if (env->player_start.is_set == 1)
		return (-EXIT_FAILURE);
	env->player_start = (t_start){(t_position){i, j }, 1, c};
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
	(t_map_parsing){AUTHORIZED_ON_MAP, NULL},
	(t_map_parsing){AUTHORIZED_ON_MAP_MOB, &id_mob},
	(t_map_parsing){AUTHORIZED_ON_MAP_DIR, &id_dir},
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
