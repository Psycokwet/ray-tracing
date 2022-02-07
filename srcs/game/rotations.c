/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:57:00 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/07 12:22:01 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	rotation(t_coordinates *vector, float angle)
{
	float	x;
	float	y;

	x = vector->x;
	y = vector->y;
	vector->x = x * cos(angle) - y * sin(angle);
	vector->y = x * sin(angle) + y * cos(angle);
}

int	rotate_left(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	rotation(&env->direction, -(env->fov_angle / ROTATE_DIV));
	return (EXIT_SUCCESS);
}

int	rotate_rigth(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	rotation(&env->direction, (env->fov_angle / ROTATE_DIV));
	return (EXIT_SUCCESS);
}
