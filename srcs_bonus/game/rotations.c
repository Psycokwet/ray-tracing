/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:57:00 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/10 11:07:49 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calc_dir(t_cartesian_vector *vector, float angle)
{
	float	x;
	float	y;

	x = vector->dir.x;
	y = vector->dir.y;
	vector->dir.x = x * cos(angle) - y * sin(angle);
	vector->dir.y = x * sin(angle) + y * cos(angle);
}

void	rotation(t_env *env, double rotspeed)
{
	t_coordinates	old_dir;
	t_coordinates	old_plane;

	old_dir = env->direction;
	old_plane = env->plane;
	env->direction.x = env->direction.x * \
		cos(rotspeed) - env->direction.y * sin(rotspeed);
	env->direction.y = old_dir.x * sin(rotspeed) + \
		env->direction.y * cos(rotspeed);
	env->plane.x = env->plane.x * cos(rotspeed) - \
		env->plane.y * sin(rotspeed);
	env->plane.y = old_plane.x * sin(rotspeed) + \
		env->plane.y * cos(rotspeed);
}

int	rotate_left(void *v_env)
{
	t_env	*env;
	double	rad;

	rad = 2 * M_PI / 180;
	env = (t_env *)v_env;
	rotation(&(*env), -rad);
	return (EXIT_SUCCESS);
}

int	rotate_rigth(void *v_env)
{
	t_env	*env;
	double	rad;

	rad = 2 * M_PI / 180;
	env = (t_env *)v_env;
	rotation(&(*env), rad);
	return (EXIT_SUCCESS);
}
