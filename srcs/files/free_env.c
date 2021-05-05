/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/05/05 09:41:49 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_env(t_env *env)
{
	int i;

	i = 0;
	while (i < MAX_SRCS)
	{
		if (env->g_srcs[i].src != NULL)
			free(env->g_srcs[i].src);
		env->g_srcs[i].src = NULL;
		i++;
	}
	if (env->map_array.lines)
	{
		i = 0;
		while (i < env->map_array.size)
		{
			if (env->map_array.lines[i] != NULL)
			{
				if (env->map_array.lines[i]->line != NULL)
					free(env->map_array.lines[i]->line);
				free(env->map_array.lines[i]);
			}
			i++;
		}
		free(env->map_array.lines);
	}
	env->conf.map_src = NULL;

	i = 0;
	while (i < MAX_IMGS)
	{
		if (env->imgs[i].img != NULL)
			mlx_destroy_image(env->mlx, env->imgs[i].img);
		i++;
	}
	i = 0;
	while (i < MAX_TEX)
	{
		if (env->textures[i].img != NULL)
			mlx_destroy_image(env->mlx, env->textures[i].img);
		i++;
	}
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		env->mlx = NULL;
	}
}
