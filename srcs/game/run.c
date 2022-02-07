/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:58:02 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/07 10:18:54 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	run_up(t_env *env)
{
	env->try_to_run_dir.y -= QUOTIENT_MOVE;
	env->actions[ACTUALLY_RUN].is_asked = 1;
	return (EXIT_SUCCESS);
}

int	run_down(t_env *env)
{
	env->try_to_run_dir.y += QUOTIENT_MOVE;
	env->actions[ACTUALLY_RUN].is_asked = 1;
	return (EXIT_SUCCESS);
}

int	run_right(t_env *env)
{
	env->try_to_run_dir.x += QUOTIENT_MOVE;
	env->actions[ACTUALLY_RUN].is_asked = 1;
	return (EXIT_SUCCESS);
}

int	run_left(t_env *env)
{
	env->try_to_run_dir.x -= QUOTIENT_MOVE;
	env->actions[ACTUALLY_RUN].is_asked = 1;
	return (EXIT_SUCCESS);
}
