/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:53:02 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/14 11:55:05 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	could_close_x_1(t_env *env, int x, int y)
{
	if (env->map_char[y - 1][x + 1] && env->map_char[y - 1][x + 1] == 'S')
	{
		env->map_char[y - 1][x + 1] = '1';
		env->map_char[y][x + 1] = '2';
	}
	else if (env->map_char[y - 1][x - 1] && env->map_char[y - 1][x - 1] == 'S')
	{
		env->map_char[y - 1][x - 1] = '1';
		env->map_char[y][x - 1] = '2';
	}
}

void	could_close_x_2(t_env *env, int x, int y)
{
	if (env->map_char[y + 1][x - 1] && env->map_char[y + 1][x - 1] == 'N')
	{
		env->map_char[y + 1][x - 1] = '1';
		env->map_char[y][x - 1] = '2';
	}
	else if (env->map_char[y + 1][x + 1] && env->map_char[y + 1][x + 1] == 'N')
	{
		env->map_char[y + 1][x + 1] = '1';
		env->map_char[y][x + 1] = '2';
	}
}

void	could_close_y_1(t_env *env, int x, int y)
{
	if (env->map_char[y + 1][x + 1] && env->map_char[y + 1][x + 1] == 'E')
	{
		env->map_char[y + 1][x] = '2';
		env->map_char[y + 1][x + 1] = '1';
	}
	else if (env->map_char[y - 1][x + 1] && env->map_char[y - 1][x + 1] == 'E')
	{
		env->map_char[y - 1][x] = '2';
		env->map_char[y - 1][x + 1] = '1';
	}
}

void	could_close_y_2(t_env *env, int x, int y)
{
	if (env->map_char[y - 1][x - 1] && env->map_char[y - 1][x - 1] == 'W')
	{
		env->map_char[y - 1][x] = '2';
		env->map_char[y - 1][x - 1] = '1';
	}
	else if (env->map_char[y + 1][x - 1] && env->map_char[y + 1][x - 1] == 'W')
	{
		env->map_char[y + 1][x] = '2';
		env->map_char[y + 1][x - 1] = '1';
	}
}
