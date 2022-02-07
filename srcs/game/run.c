/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:58:02 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/07 12:16:44 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	run_up(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	env->try_to_run_dir.y -= QUOTIENT_MOVE;
	env->actions[ACTUALLY_RUN].is_asked = 1;
	return (EXIT_SUCCESS);
}

int	run_down(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	env->try_to_run_dir.y += QUOTIENT_MOVE;
	env->actions[ACTUALLY_RUN].is_asked = 1;
	return (EXIT_SUCCESS);
}

int	run_right(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	env->try_to_run_dir.x += QUOTIENT_MOVE;
	env->actions[ACTUALLY_RUN].is_asked = 1;
	return (EXIT_SUCCESS);
}

int	run_left(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	env->try_to_run_dir.x -= QUOTIENT_MOVE;
	env->actions[ACTUALLY_RUN].is_asked = 1;
	return (EXIT_SUCCESS);
}
