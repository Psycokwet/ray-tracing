/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/24 18:07:03 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	start_cub_3d(t_env *env)
{
	printf("ok %s %d %d %d\n", env->g_srcs[0].src, env->r.width,
	env->g_colors[0].color, env->map_array.size);
	for(int i = 0; env->map_array.size > i; i++)
		printf("RESULT %s, %u %d\n", env->map_array.lines[i]->line,
		env->map_array.lines[i]->size, i);
	free_env(env);
}
