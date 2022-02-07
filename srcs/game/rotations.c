/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:57:00 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/07 10:03:46 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	rotation(t_cartesian_vector *vector, float angle)
{
	float	x;
	float	y;

	x = vector->dir.x;
	y = vector->dir.y;
	vector->dir.x = x * cos(angle) - y * sin(angle);
	vector->dir.y = x * sin(angle) + y * cos(angle);
}

int	rotate_left(t_env *env)
{
	rotation(&env->direction, -(env->fov_angle / ROTATE_DIV));
	return (EXIT_SUCCESS);
}

int	rotate_rigth(t_env *env)
{
	rotation(&env->direction, (env->fov_angle / ROTATE_DIV));
	return (EXIT_SUCCESS);
}
