/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:47:50 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/16 10:35:11 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	mouse_rotate_left(void *v_env, double factor)
{
	t_env	*env;
	double	rad;

	rad = (2 + factor) * M_PI / 180;
	env = (t_env *)v_env;
	rotation(&(*env), -rad);
	return (EXIT_SUCCESS);
}

static int	mouse_rotate_right(void *v_env, double factor)
{
	t_env	*env;
	double	rad;

	rad = (2 + factor) * M_PI / 180;
	env = (t_env *)v_env;
	rotation(&(*env), rad);
	return (EXIT_SUCCESS);
}

int	mouse_rot(int x, int y, void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	(void)y;
	if (x + 2 < (int)env->mouse_po.x)
	{
		mouse_rotate_left(env, (env->mouse_po.x - x) / 5);
		env->mouse_po.x = (double)x + 2;
		game_loop(&(*env));
	}
	else if (x - 2 > (int)env->mouse_po.x)
	{
		mouse_rotate_right(env, (x - env->mouse_po.x) / 5);
		env->mouse_po.x = (double)x - 2;
		game_loop(&(*env));
	}
	return (0);
}
