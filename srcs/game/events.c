/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:56:02 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/07 10:07:11 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	key_release(int keycode, t_env *env)
{
	int	i;

	i = -1;
	while (i++ < MAX_ACTIONS - 1)
	{
		if (keycode == env->actions[i].keycode)
		{
			env->actions[i].is_asked = 0;
			break ;
		}
	}
	return (keycode);
}

int	key_press(int keycode, t_env *env)
{
	int	i;

	i = -1;
	while (i++ < MAX_ACTIONS - 1)
	{
		if (keycode == env->actions[i].keycode)
		{
			env->actions[i].is_asked = 1;
			break ;
		}
	}
	return (keycode);
}

int	quit_cub3d(t_env *env)
{
	printf("QUITTING ! \n");
	mlx_destroy_window(env->mlx, env->win);
}

int	close_window(t_env *env)
{
	env->actions[ESCAPE_ID].is_asked = 1;
	return (0);
}