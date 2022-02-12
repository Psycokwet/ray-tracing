/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:58:02 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/11 18:05:25 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	run_up(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	if (env->map_char[(int)(env->current_pos.y)][(int)(env->current_pos.x + \
		env->direction.x * (RUN_STEP + WALL_HIT_BOX))] == '0')
		env->current_pos.x += env->direction.x * RUN_STEP;
	if (env->map_char[(int)(env->current_pos.y + env->direction.y * (RUN_STEP \
	+ (RUN_STEP + WALL_HIT_BOX)))][(int)env->current_pos.x] == '0')
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
	if (env->map_char[(int)(env->current_pos.y - env->direction.y * \
		(RUN_STEP + WALL_HIT_BOX))][(int)env->current_pos.x] == '0')
		env->current_pos.y -= env->direction.y * RUN_STEP;
	return (EXIT_SUCCESS);
}

int	run_right(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	if (env->map_char[(int)(env->current_pos.y)][(int)(env->current_pos.x + \
		env->plane.x * (RUN_STEP + WALL_HIT_BOX))] == '0')
		env->current_pos.x += env->plane.x * RUN_STEP;
	if (env->map_char[(int)(env->current_pos.y + env->plane.y * (RUN_STEP \
	+ (RUN_STEP + WALL_HIT_BOX)))][(int)env->current_pos.x] == '0')
		env->current_pos.y += env->plane.y * RUN_STEP;
	return (EXIT_SUCCESS);
}

int	run_left(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	if (env->map_char[(int)(env->current_pos.y)][(int)(env->current_pos.x - \
		env->plane.x * (RUN_STEP + WALL_HIT_BOX))] == '0')
		env->current_pos.x -= env->plane.x * RUN_STEP;
	if (env->map_char[(int)(env->current_pos.y - env->plane.y * \
		(RUN_STEP + WALL_HIT_BOX))][(int)env->current_pos.x] == '0')
		env->current_pos.y -= env->plane.y * RUN_STEP;
	return (EXIT_SUCCESS);
}
