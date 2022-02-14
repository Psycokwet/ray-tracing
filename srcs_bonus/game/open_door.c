/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:23:58 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/14 12:06:51 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	could_open_x(t_env *env, int x, int y)
{
	if (env->map_char[y][x + 1] && env->map_char[y][x + 1] == '2')
	{
		env->map_char[y - 1][x + 1] = 'S';
		env->map_char[y][x + 1] = '0';
		return (1);
	}
	else if (env->map_char[y][x - 1] && env->map_char[y][x - 1] == '2')
	{
		env->map_char[y + 1][x - 1] = 'N';
		env->map_char[y][x - 1] = '0';
		return (1);
	}
	return (0);
}

int	could_open_y(t_env *env, int x, int y)
{
	if (env->map_char[y + 1][x] && env->map_char[y + 1][x] == '2')
	{
		env->map_char[y + 1][x] = '0';
		env->map_char[y + 1][x + 1] = 'E';
		return (1);
	}
	else if (env->map_char[y - 1][x] && env->map_char[y - 1][x] == '2')
	{
		env->map_char[y - 1][x] = '0';
		env->map_char[y - 1][x - 1] = 'W';
		return (1);
	}
	return (0);
}

int	open_door(void *v_env)
{
	t_env	*env;
	int		x;
	int		y;

	env = (t_env *)v_env;
	env->actions[8].is_asked = 0;
	x = (int)env->current_pos.x;
	y = (int)env->current_pos.y;
	if (!could_open_x(&(*env), x, y) && !could_open_y(&(*env), x, y))
	{
		could_close_x_1(&(*env), x, y);
		could_close_x_2(&(*env), x, y);
		could_close_y_1(&(*env), x, y);
		could_close_y_2(&(*env), x, y);
	}
	return (1);
}
