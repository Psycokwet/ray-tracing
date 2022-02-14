/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:47:50 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/14 15:37:25 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	mouse_rotate_left(void *v_env)
{
	t_env	*env;
	double	rad;

	rad = 2 * M_PI / 180;
	env = (t_env *)v_env;
	rotation(&(*env), -rad);
	return (EXIT_SUCCESS);
}

static int	mouse_rotate_right(void *v_env)
{
	t_env	*env;
	double	rad;

	rad = 2 * M_PI / 180;
	env = (t_env *)v_env;
	rotation(&(*env), rad);
	return (EXIT_SUCCESS);
}

int	mouse_rot(int x, int y, void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	(void)y;
	if (x < (int)env->mouse_po.x - 2)
	{
		mouse_rotate_left(env);
		game_loop(&(*env));
	}
	else if (x > (int)env->mouse_po.x + 2)
	{
		mouse_rotate_right(env);
		game_loop(&(*env));
	}
	env->mouse_po.x = (double)x;
	return (0);
}

int	mouse_leave(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	if (env->mouse_po.x < WIDTH / 2)
	{
		printf("mouse pos x %f\n", env->mouse_po.x);
		mouse_rotate_left(env);
		game_loop(&(*env));
	}
	if (env->mouse_po.x > WIDTH / 2)
	{
		printf("mouse pos x %f\n", env->mouse_po.x);
		mouse_rotate_right(env);
		game_loop(&(*env));
	}
	return (0);
}
