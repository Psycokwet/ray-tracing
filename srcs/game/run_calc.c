/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:58:55 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/07 12:31:26 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_coordinates	calc_run_dir(t_env *env)
{
	t_coordinates	run_dir;
	float			pi_quotient;
	float			angle;

	pi_quotient = 0;
	angle = 2.0;
	if (env->try_to_run_dir.x != 0)
		pi_quotient = -(env->try_to_run_dir.x - 1);
	if (env->try_to_run_dir.y != 0)
		pi_quotient += -env->try_to_run_dir.y + 2;
	if (env->try_to_run_dir.x == +1 && env->try_to_run_dir.y == -1)
		pi_quotient = 7;
	run_dir.x = env->direction.x;
	run_dir.y = env->direction.y;
	if ((float)(env->try_to_run_dir.y != 0 && env->try_to_run_dir.x != 0))
		angle = 4;
	rotation(&run_dir, (pi_quotient * M_PI) / angle);
	return (run_dir);
}

int	actually_run(void *v_env)
{
	t_env			*env;
	t_coordinates	run_dir;
	t_coordinates	new_pos;

	env = (t_env *)v_env;
	run_dir = calc_run_dir(env);
	new_pos = (t_coordinates){env->current_pos.x + \
	run_dir.x * RUN_STEP, env->current_pos.y + run_dir.y * RUN_STEP};
	env->actions[ACTUALLY_RUN].is_asked = 0;
	if (env->map_array.lines[(int)(new_pos.y + (env->try_to_run_dir.y * \
	WALL_HIT_BOX))]->line[(int)(env->current_pos.x)] != '1')
		env->current_pos.y = new_pos.y;
	if (env->map_array.lines[(int)(env->current_pos.y)]->line[(int)(new_pos.x \
	+ (env->try_to_run_dir.x * WALL_HIT_BOX))] != '1')
		env->current_pos.x = new_pos.x;
	env->try_to_run_dir = (t_coordinates){0, 0};
	return (EXIT_SUCCESS);
}

int	mock_actions_fun(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	printf("supposed to act\n");
	return (EXIT_SUCCESS);
}
