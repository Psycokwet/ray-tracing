/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_holes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/15 19:43:50 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	in(t_env *env, int line, int column)
{
	int	i;

	i = 0;
	while (i < INSIDE_MAX_TYPE)
	{
		if (INSIDE[i] == env->map_array.lines[line]->line[column])
			return (true);
		i++;
	}
	return (false);
}

int	is_nin_nout(t_env *env, int line, int column)
{
	return (!in(env, line, column)
		&& env->map_array.lines[line]->line[column] != '1');
}

int	check_map_for_holes(t_env *env)
{
	int	l;
	int	c;

	l = 0;
	c = 0;
	if (env->map_array.size < 3)
		return (-EXIT_FAILURE);
	while (env->map_array.size > l)
	{
		while (env->map_array.lines[l]->size > c)
			if (in(env, l, c) && ((l == 0 || c == 0 || env->map_array.size - 1
						== l || env->map_array.lines[l]->size - 1 == c)
					|| (l > 0 && is_nin_nout(env, l - 1, c))
					|| (l + 1 < env->map_array.size
						&& is_nin_nout(env, l + 1, c))
					|| (c > 0 && is_nin_nout(env, l, c - 1))
					|| (c + 1 <= env->map_array.lines[l]->size
						&& is_nin_nout(env, l, c + 1))))
				return (-EXIT_FAILURE);
		else
			c++;
		c = 0;
		l++;
	}
	return (EXIT_SUCCESS);
}
