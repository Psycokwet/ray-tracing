/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:47:50 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/10 17:38:04 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	mouse_rot(int x, int y, void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	(void)y;
	if (x < (int)env->mouse_po.x)
		rotate_left(env);
	else if (x > (int)env->mouse_po.x)
		rotate_rigth(env);
	game_loop(&(*env));
	env->mouse_po.x = (double)x;
	return (0);
}

int	mouse_leave(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	mlx_mouse_move(env->mlx, env->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
