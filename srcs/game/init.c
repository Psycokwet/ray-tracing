/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:54:24 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/08 10:55:04 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_fov(t_env *env)
{
	env->fov_angle = FOV * M_PI / (MAX_DEGREES / 2);
}

int	init_textures(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_TEX)
	{
		env->textures[i].img = mlx_xpm_file_to_image(env->mlx, \
		env->g_srcs[i].src, &env->textures[i].w, &env->textures[i].h);
		if (!env->textures[i].img)
			return (-EXIT_FAILURE);
		env->textures[i].addr = mlx_get_data_addr(env->textures[i].img, \
		&env->textures[i].bits_per_pixel, &env->textures[i].line_length, \
		&env->textures[i].endian);
		if (!env->textures[i].img)
			return (-EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	init_actions(t_env *env)
{
	env->actions[ESCAPE_ID] = (t_action){0, XK_Escape, &quit_cub3d};
	env->actions[ROTATE_LEFT_ID] = (t_action){0, XK_Left, &rotate_left};
	env->actions[ROTATE_RIGHT_ID] = (t_action){0, XK_Right, &rotate_rigth};
	env->actions[GO_LEFT_A_ID] = (t_action){0, XK_a, &run_left};
	env->actions[GO_RIGTH_D_ID] = (t_action){0, XK_d, &run_right};
	env->actions[GO_BACK_S_ID] = (t_action){0, XK_s, &run_down};
	env->actions[GO_FRONT_W_ID] = (t_action){0, XK_w, &run_up};
	env->actions[ACTUALLY_RUN] = (t_action){0, -1, &actually_run};
}

void	init_imgs(t_env *env)
{
	int	i;

	i = -1;
	while (i++ < MAX_IMGS - 1)
		env->imgs[i] = (t_data){NULL, NULL, -1, -1, -1, -1, -1};
}
