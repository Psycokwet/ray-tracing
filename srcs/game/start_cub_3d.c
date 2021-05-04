/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/05/05 00:11:00 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

#define DestroyNotify		33




void	rotation(t_cartesian_vector *vector, float angle)
{
	float	x;
	float	y;

	x = vector->dir.x;
	y = vector->dir.y;
	vector->dir.x = x * cos(angle) - y * sin(angle);
	vector->dir.y = x * sin(angle) + y * cos(angle);
}


void	draw_rect(t_data *datas, t_coordinates start, t_coordinates end, int color){
	int x;
	int y;

	x = start.x;
	y = start.y;
	while(y < end.y)
	{
		while(x < end.x)
		{
			my_mlx_pixel_put(datas, x, y, color);
			x++;
		}
		x = start.x;
		y++;
	}
}

void	draw_ceiling_floor(t_data *datas, t_env *env)
{
	draw_rect(datas, (t_coordinates){0, 0}, (t_coordinates){env->r.width, env->r.height / 2}, env->g_colors[CODE_CEILING].color);
	draw_rect(datas, (t_coordinates){0, env->r.height / 2}, (t_coordinates){env->r.width, env->r.height}, env->g_colors[CODE_FLOOR].color);
}

void	draw_walls(t_data *datas, t_env *env)
{
	int current_x;
	float ratio;
	int half_width_x;
	t_cartesian_vector char_direction;

	half_width_x = env->r.width/2;
	current_x = 0;
	while(current_x < env->r.width)
	{
		ratio = (current_x - half_width_x) / half_width_x;
		char_direction.dir.x = cos(env->fov_angle)/2 + cos(env->fov_angle - 0.25) * ratio;
		// dir.y = cos();
	}


}

void	print_img(t_env *env)
{
	int i;

	i = 0;
	if (env->imgs[i].img != NULL)
		mlx_destroy_image(env->mlx, env->imgs[i].img);

    env->imgs[i].img = mlx_new_image(env->mlx, env->r.width, env->r.height);
    env->imgs[i].addr = mlx_get_data_addr(env->imgs[i].img,	&env->imgs[i].bits_per_pixel, &env->imgs[i].line_length, &env->imgs[i].endian);

	draw_ceiling_floor(&env->imgs[i], env);

    mlx_put_image_to_window(env->mlx, env->win, env->imgs[i].img, 0, 0);

}

// int             key_press(int keycode, t_env *env)
// {
//     printf("Hello from key_press! %c\n", keycode); //single event ? 
// }

int             key_release(int keycode, t_env *env)
{
	int i;

	i = -1;
	while (i++ < MAX_ACTIONS - 1)
		if (keycode == env->actions[i].keycode)
		{
			env->actions[i].is_asked = 0;
			break ;
		}
	return keycode;
}

int             key_press(int keycode, t_env *env)
{
	int i;

	i = -1;
	while (i++ < MAX_ACTIONS - 1)
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
		print_img(env);
		// img.img = mlx_new_image(env->mlx, env->r.width, env->r.height);
		// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
        //                          &img.endian);
		// my_mlx_pixel_put(&img, env->r.width-1, env->r.height-1, MASK_B); //de 0 a width -1 ou a height -1
		// mlx_put_image_to_window(env->mlx, env->win, img.img, 0, 0);
	}

	int i;

	i = -1;
	while (i++ < MAX_ACTIONS)
	{
		if (env->actions[i].is_asked == 1)
		{
			env->actions[i].fun(env);
		}
	}
	return (0);
}

int mock_actions_fun(void *v_env)
{
	t_env *env = (t_env*)v_env;
	printf("supposed to act\n");
	return (EXIT_SUCCESS);
}

int rotate_left(t_env *env)
{
	rotation(&env->direction, -(env->fov_angle / ROTATE_DIV));
	return (EXIT_SUCCESS);
}

int rotate_rigth(t_env *env)
{
	rotation(&env->direction, (env->fov_angle / ROTATE_DIV));
	return (EXIT_SUCCESS);
}

int run_up(t_env *env)
{
	env->next_pos.y-= QUOTIENT_MOVE;
	env->actions[ACTUALLY_RUN].is_asked = 1;
	return (EXIT_SUCCESS);
}

int run_down(t_env *env)
{
	env->next_pos.y+= QUOTIENT_MOVE;
	env->actions[ACTUALLY_RUN].is_asked = 1;
	return (EXIT_SUCCESS);
}

int run_right(t_env *env)
{
	env->next_pos.x+= QUOTIENT_MOVE;
	env->actions[ACTUALLY_RUN].is_asked = 1;
	return (EXIT_SUCCESS);
}

int run_left(t_env *env)
{
	env->next_pos.x-= QUOTIENT_MOVE;
	env->actions[ACTUALLY_RUN].is_asked = 1;
	return (EXIT_SUCCESS);
}

int actually_run(t_env *env)
{
	printf("RUNNING %f:%f\n", env->next_pos.x, env->next_pos.y);
	env->next_pos = (t_coordinates){0, 0};
	env->actions[ACTUALLY_RUN].is_asked = 0;
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
	int i;

	i = -1;
	while (i++ < MAX_IMGS - 1)
		env->imgs[i] = (t_data){NULL, NULL, -1, -1, -1};
}

void	correct_max_dimension(t_env *env)
{
	int sizex;
	int sizey;

	sizex = 0;
	sizey = 0;
	mlx_get_screen_size(env->mlx, &sizex, &sizey);
	if(sizex < env->r.width)
		env->r.width = sizex;
	if(sizey < env->r.height)
		env->r.height = sizey;
}

void	init_fov(t_env *env)
{
	env->fov_angle = FOV * M_PI / (MAX_DEGREES / 2);
}


void	start_cub_3d(t_env *env)
{
	init_actions(env);
	init_imgs(env);
	init_fov(env);
	env->count = 0;
    env->mlx = mlx_init();
	correct_max_dimension(env);
	env->current_pos = env->player_start.pos;

    env->win = mlx_new_window(env->mlx, env->r.width, env->r.height, "Hello world!");

	print_img(env);

	// mlx_hook(env->win, DestroyNotify, StructureNotifyMask, key_hook, (void *)0);

	mlx_hook(env->win, KeyPress, KeyPressMask, key_press, env);
	mlx_hook(env->win, KeyRelease, KeyReleaseMask, key_release, env);
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask, close_window, env);
	mlx_loop_hook(env->mlx, game_loop, env);
    mlx_loop(env->mlx);

	free_env(env);
}
