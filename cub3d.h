/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/05 17:13:51 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libs/libft/libft.h"
# include "libs/minilibx-linux/mlx.h"
# include "libs/minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>

# define B_SHIFT_T 24
# define B_SHIFT_R 16
# define B_SHIFT_G 8
# define B_SHIFT_B 0

# define MASK_T 0xFF000000
# define MASK_R 0x00FF0000
# define MASK_G 0x0000FF00
# define MASK_B 0x000000FF

# define MAP_ARG "MAP.cub"
# define MAP_EXT ".cub"
# define SAVE_ARG "--save"
# define USAGE "Usage : MAP.cub [--save]"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;


typedef struct		s_conf
{
    int             save;
    char*           map_src;
}	                t_conf;

typedef struct		s_env
{
    t_conf          conf;
	// t_conf			*conf;
	// t_map			*map;
	// t_rndr			*rndr;
	// t_data			img;
	// t_data			tex[4];
	// t_sprite		sp;
	// void			*mlx;
	// void			*win;
	// int				left;
	// int				right;
	// int				up;
	// int				down;
	// int				strafe_left;
	// int				strafe_right;
	// int				sprite;
}					t_env;


/*
** COLORS
*/

int	add_shade(double dist, int trgb);
int	get_opposite(int trgb);
int	create_trgb(int t, int r, int g, int b);

/*
** IMG
*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
** FILES
*/

void	args_parse(t_env *env, int argc, char const *argv[]);
void	check_save_arg(t_env *env, int argc, char const *argv[]);
void	set_src_map(t_env *env, char const *argv[]);

#endif
