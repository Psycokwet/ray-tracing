/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/09 15:00:51 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	game_loop(t_env *env)
{
	int	i;

	if (env->win)
		print_img(env);
	i = -1;
	while (i++ < MAX_ACTIONS)
	{
		if (env->actions[i].is_asked == 1)
			env->actions[i].fun(env);
	}
	return (0);
}

static void	init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	if (env->mlx == NULL)
	{
		free_env(env);
		exit(EXIT_MLX_FAILURE);
	}
}

void	start_cub_3d(t_env *env)
{
	init_actions(env);
	init_imgs(env);
	init_fov(env);
	env->count = 0;
	init_mlx(&(*env));
	if (init_textures(env) != EXIT_SUCCESS)
	{
		printf("Error on textures :the files may not exist\n");
		free_env(env);
		exit(-EXIT_FAILURE);
	}
	env->current_pos = env->player_start.pos;
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Cub3D");
	print_img(env);
	mlx_hook(env->win, KeyPress, KeyPressMask, key_press, env);
	mlx_hook(env->win, KeyRelease, KeyReleaseMask, key_release, env);
	mlx_hook(env->win, DestroyNotify_FIX, \
		StructureNotifyMask, close_window, env);
	mlx_loop_hook(env->mlx, game_loop, env);
	mlx_loop(env->mlx);
	free_env(env);
}
