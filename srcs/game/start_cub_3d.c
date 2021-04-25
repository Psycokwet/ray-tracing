/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/25 20:17:48 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

#define DestroyNotify		33

#define MAX_PARSING		7

// int             key_press(int keycode, t_env *env)
// {
//     printf("Hello from key_press! %c\n", keycode); //single event ? 
// }

int             key_release(int keycode, t_env *env)
{
	int i;

	i = -1;
	while (i++ < MAX_PARSING)
		if (keycode == env->actions[i].keycode)
		{
			env->actions[i].is_asked = 1;
			break ;
		}
	return keycode;
}

int		quit_cub3d(t_env *env)
{
	printf("QUITTING ! \n");
	// mlx_destroy_image(env->mlx, game->screen.ptr);
	mlx_destroy_window(env->mlx, env->win);
	// free_env(env);
}

int		close_window(t_env *env)
{
	env->actions[ESCAPE_ID].is_asked = 1;
	return (0);
}

int		game_loop(t_env *env)
{
	if(env->win){
		
		t_data  img;

		// img.img = mlx_new_image(env->mlx, env->r.width, env->r.height);
		// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
        //                          &img.endian);
		// my_mlx_pixel_put(&img, env->r.width-1, env->r.height-1, MASK_B); //de 0 a width -1 ou a height -1
		// mlx_put_image_to_window(env->mlx, env->win, img.img, 0, 0);
	}

	int i;

	i = -1;
	while (i++ < MAX_PARSING)
	{
		if (env->actions[i].is_asked == 1)
		{
			env->actions[i].fun(env);
			env->actions[i].is_asked = 0;
		}
	}
	return (0);
}

int mock_actions_fun(void *v_env){
	t_env *env = (t_env*)v_env;
	printf("supposed to act\n");
}

void	init_actions(t_env *env){
	env->actions[ESCAPE_ID] = (t_action){0, XK_Escape, &quit_cub3d};
	env->actions[ROTATE_LEFT_ID] = (t_action){0, XK_Left, &mock_actions_fun};
	env->actions[ROTATE_RIGHT_ID] = (t_action){0, XK_Right, &mock_actions_fun};
	env->actions[GO_LEFT_A_ID] = (t_action){0, XK_a, &mock_actions_fun};
	env->actions[GO_RIGTH_D_ID] = (t_action){0, XK_d, &mock_actions_fun};
	env->actions[GO_BACK_S_ID] = (t_action){0, XK_s, &mock_actions_fun};
	env->actions[GO_FRONT_W_ID] = (t_action){0, XK_w, &mock_actions_fun};
}
void	start_cub_3d(t_env *env)
{
	init_actions(env);

    env->mlx = mlx_init(); //mlx_destroy_display

    env->win = mlx_new_window(env->mlx, env->r.width, env->r.height, "Hello world!");
    // // mlx_key_hook(env->win, key_hook, env);
    // t_data  img;

    // img.img = mlx_new_image(env->mlx, env->r.width, env->r.height);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
    //                              &img.endian);
    // my_mlx_pixel_put(&img, env->r.width-1, env->r.height, MASK_R); //de 0 a width -1 ou a height -1
    // mlx_put_image_to_window(env->mlx, env->win, img.img, 0, 0);

	// mlx_hook(env->win, DestroyNotify, StructureNotifyMask, key_hook, (void *)0);

	mlx_hook(env->win, KeyPress, KeyPressMask, key_release, env);
	mlx_hook(env->win, KeyRelease, KeyReleaseMask, key_release, env);
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask, close_window, env);
	mlx_loop_hook(env->mlx, game_loop, env);
    mlx_loop(env->mlx);

	free_env(env);
}
