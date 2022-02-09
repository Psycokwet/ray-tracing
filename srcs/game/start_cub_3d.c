/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/09 14:30:09 by scarboni         ###   ########.fr       */
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

void	start_cub_3d(t_env *env)
{
	printf("HELLO \n%f:%f\n", env->player_start.pos.x, env->player_start.pos.y);
	printf("HELLO \n%f:%f\n", env->current_pos.x, env->current_pos.y);
	init_actions(env);
	init_imgs(env);
	init_fov(env);
	env->count = 0;
	env->mlx = mlx_init();
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
	mlx_hook(env->win, DestroyNotify_FIX, StructureNotifyMask, close_window, env);
	mlx_loop_hook(env->mlx, game_loop, env);
	mlx_loop(env->mlx);
	free_env(env);
}
