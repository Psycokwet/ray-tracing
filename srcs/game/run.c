/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:58:02 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/09 10:56:57 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	run_up(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	if (env->map_char[(int)(env->current_pos.y)][(int)(env->current_pos.x + \
		env->direction.x * (RUN_STEP + WALL_HIT_BOX))] == '0')
		env->current_pos.x += env->direction.x * RUN_STEP;
	if (env->map_char[(int)(env->current_pos.y + env->direction.y * (RUN_STEP \
		+ WALL_HIT_BOX))][(int)env->current_pos.x] == '0')
		env->current_pos.y += env->direction.y * RUN_STEP;
	return (EXIT_SUCCESS);
}

int	run_down(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	if (env->map_char[(int)(env->current_pos.y)][(int)(env->current_pos.x - \
		env->direction.x * (RUN_STEP + WALL_HIT_BOX))] == '0')
		env->current_pos.x -= env->direction.x * RUN_STEP;
	if (env->map_char[(int)(env->current_pos.y - env->direction.y * (RUN_STEP \
		+ WALL_HIT_BOX))][(int)env->current_pos.x] == '0')
		env->current_pos.y -= env->direction.y * RUN_STEP;
	return (EXIT_SUCCESS);
}

int	run_right(void *v_env)
{
	// t_env	*env;

	// env = (t_env *)v_env;
	// env->try_to_run_dir.x += QUOTIENT_MOVE;
	// env->actions[ACTUALLY_RUN].is_asked = 1;
	// return (EXIT_SUCCESS);
}

int	run_left(void *v_env)
{
	// t_env	*env;

	// env = (t_env *)v_env;
	// printf("RUN LEFT\n");
	// env->try_to_run_dir.x -= QUOTIENT_MOVE;
	// env->actions[ACTUALLY_RUN].is_asked = 1;
	// return (EXIT_SUCCESS);
}
