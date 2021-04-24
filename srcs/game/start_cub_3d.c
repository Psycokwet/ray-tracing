/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/24 18:36:46 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	start_cub_3d(t_env *env)
{

    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, env->r.width, env->r.height, "Hello world!");
    img.img = mlx_new_image(mlx, env->r.width, env->r.height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    my_mlx_pixel_put(&img, 5, 5, MASK_R);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);



	
	// // debug
	// printf("ok %s %d %d %d\n", env->g_srcs[0].src, env->r.width,
	// env->g_colors[0].color, env->map_array.size);
	// for(int i = 0; env->map_array.size > i; i++)
	// 	printf("RESULT %s, %u %d\n", env->map_array.lines[i]->line,
	// 	env->map_array.lines[i]->size, i);
	// free_env(env);
}
