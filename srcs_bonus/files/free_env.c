/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/16 10:38:11 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	free_map(t_env *env)
{
	int	i;

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
	free_strs(env->map_char);
}

static void	free_text(t_env *env)
{
	int	i;

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
}

static void	free_text_2(t_env *env)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (env->gun[i].img != NULL)
			mlx_destroy_image(env->mlx, env->gun[i].img);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (env->door[i].img != NULL)
			mlx_destroy_image(env->mlx, env->door[i].img);
		i++;
	}
}

void	free_env(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_SRCS)
	{
		if (env->g_srcs[i].src != NULL)
			free(env->g_srcs[i].src);
		env->g_srcs[i].src = NULL;
		i++;
	}
	free_map(&(*env));
	free_text(&(*env));
	free_text_2(&(*env));
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		env->mlx = NULL;
	}
}
