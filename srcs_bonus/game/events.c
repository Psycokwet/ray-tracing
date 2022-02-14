/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:56:02 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/14 15:13:35 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	fire_realase(int button, int x, int y, void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	(void)x;
	(void)y;
	if (button == 1)
	{
		env->img_gun = 0;
		key_release(24, &(*env));
	}
	return (1);
}

int	fire(void *v_env)
{
	t_env		*env;
	static int	i = 0;

	env = (t_env *)v_env;
	env->img_gun = i++;
	if (i == 5)
		i = 0;
	return (1);
}

int	fire_push(int button, int x, int y, void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	(void)x;
	(void)y;
	if (button == 1)
		key_press(24, &(*env));
	return (1);
}

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

int	quit_cub3d(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	printf("QUITTING ! \n");
	mlx_destroy_window(env->mlx, env->win);
	return (0);
}

int	close_window(t_env *env)
{
	env->actions[ESCAPE_ID].is_asked = 1;
	return (0);
}
