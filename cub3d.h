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
# include <stddef.h>

# define RETURN_SUCCES			0
# define RETURN_FAILURE			1

# define EXIT_CODE_MAP_FOUND	2
# define EXIT_CODE_FOUND		1
# define EXIT_CODE_NOT_FOUND	0

# define EXIT_ARGS_FAILURE		1
# define EXIT_MLX_FAILURE		2
# define EXIT_NORMAL			0

# define B_SHIFT_T				24
# define B_SHIFT_R				16
# define B_SHIFT_G				8
# define B_SHIFT_B				0

# define MASK_T					0xFF000000
# define MASK_R					0x00FF0000
# define MASK_G					0x0000FF00
# define MASK_B					0x000000FF

# define MAP_ARG				"MAP.cub"
# define MAP_EXT				".cub"
# define SAVE_ARG				"--save"
# define USAGE					"Usage : MAP.cub [--save]"
# define AUTHORIZED_ON_MAP		"10 2NOES"

# define CODE_WE				0
# define CODE_NO				1
# define CODE_EA				2
# define CODE_SO				3
# define CODE_S					4

# define CODE_FLOOR				1
# define CODE_CEILING			0

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

typedef struct			s_srcs
{
	char*				code;
	int					size;
	char*				src;
}						t_srcs;

typedef struct			s_colors
{
	char*				code;
	int					color;
	int					is_set;
}						t_colors;

typedef struct			s_resolution
{
	char*				code;
	int					size;
	int					width;
	int					height;
	int					is_set;
}						t_resolution;

# define MAX_SRCS 5
# define MAX_COLORS 2

typedef struct		s_env
{
    t_conf          conf;
	t_srcs			g_srcs[MAX_SRCS];
	t_colors		g_colors[MAX_COLORS];
	t_resolution	r;
	
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

typedef struct			s_parsing
{
	int					(*parser)(const char *, t_env *);
}						t_parsing;

/*
** ************************************************************************** **
** 									COLORS                                    **
** ************************************************************************** **
*/

int	add_shade(double dist, int trgb);
int	get_opposite(int trgb);
int	create_trgb(int t, int r, int g, int b);

/*
** ************************************************************************** **
** 									IMG                                       **
** ************************************************************************** **
*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
** ************************************************************************** **
** 									FILES                                     **
** ************************************************************************** **
*/

void	args_parse(t_env *env, int argc, char const *argv[]);
void	check_save_arg(t_env *env, int argc, char const *argv[]);
void	set_src_map(t_env *env, char const *argv[]);

int	set_srcs(t_env * env, const char **params);
int is_map(t_env * env, const char **params);
int set_resolution(t_env * env, const char **params);
int set_colorsFC(t_env * env, const char **params);
int		parse_line(t_env *datas, char *line);
void	init_srcs(t_env *env);
void	init_colors(t_env *env);
int	parse_file(t_env *env);
int parse_map(t_env *env, int fd, char *line);
void	freeArray(char **splitted);
void free_env(t_env *env);
int parse_r_value(char* arg);



#endif
