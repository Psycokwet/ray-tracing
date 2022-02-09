/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/09 10:43:38 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libs/libft/libft.h"
# include "libs/libft/get_next_line.h"
# include "libs/minilibx-linux/mlx.h"
# include "libs/minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

# define RETURN_SUCCES			0
# define RETURN_FAILURE			1

# define EXIT_CODE_MAP_FOUND	2
# define EXIT_CODE_FOUND		1
# define EXIT_CODE_NOT_FOUND	0

# define EXIT_ARGS_FAILURE		2
# define EXIT_MLX_FAILURE		3
# define EXIT_NORMAL			0

# define B_SHIFT_T				24
# define B_SHIFT_R				16
# define B_SHIFT_G				8
# define B_SHIFT_B				0

# define MASK_T					0xFF000000
# define MASK_R					0x00FF0000
# define MASK_G					0x0000FF00
# define MASK_B					0x000000FF

# define WIDTH 800
# define HEIGHT 600

# define MAP_ARG				"MAP.cub"
# define MAP_EXT				".cub"
# define SAVE_ARG				"--save"
# define USAGE					"Usage : MAP.cub [--save]"
# define WALL					"1"
# define INSIDE_MAX_TYPE		6
# define INSIDE					"02NWES"
# define AUTHORIZED_ON_MAP		"10 "
# define AUTHORIZED_ON_MAP_DIR	"NWES"
# define DIR_NORTH				'N'
# define DIR_WEST				'W'
# define DIR_EAST				'E'
# define DIR_SOUTH				'S'
# define AUTHORIZED_ON_MAP_MOB	"2"

# define CODE_WE				0
# define CODE_NO				1
# define CODE_EA				2
# define CODE_SO				3
# define CODE_S					4

# define CODE_FLOOR				1
# define CODE_CEILING			0

# define MAX_DEGREES			360
# define FOV					90
# define ROTATE_DIV				1000
# define RUN_STEP				0.2F
# define WALL_HIT_BOX			0.3
# define QUOTIENT_MOVE			1

# ifndef M_PI
#  define M_PI					3.14159265358979323846
# endif

# define XK_Escape						0xff1b
# define ESCAPE_ID						0
# define XK_Left							0xff51  /* Move left, left arrow */
# define ROTATE_LEFT_ID					1  /* Move left, left arrow */
# define XK_Right						0xff53  /* Move right, right arrow */
# define ROTATE_RIGHT_ID					2  /* Move right, right arrow */
# define XK_a							0x0061  /* U+0061 LATIN SMALL LETTER A */
# define GO_LEFT_A_ID					3  /* U+0061 LATIN SMALL LETTER A */
# define XK_d							0x0064  /* U+0064 LATIN SMALL LETTER D */
# define GO_RIGTH_D_ID					4  /* U+0064 LATIN SMALL LETTER D */
# define XK_s							0x0073  /* U+0073 LATIN SMALL LETTER S */
# define GO_BACK_S_ID					5  /* U+0073 LATIN SMALL LETTER S */
# define XK_w							0x0077  /* U+0077 LATIN SMALL LETTER W */
# define GO_FRONT_W_ID					6  /* U+0077 LATIN SMALL LETTER W */
# define ACTUALLY_RUN					7

# define MAX_SRCS		5
# define MAX_COLORS		2
# define MAX_ACTIONS	8
# define MAX_IMGS		7
# define MAX_TEX		4
# define MAX_PARSING	4
# define MAX_MAP_PARSING 3
# define DestroyNotify_FIX 33

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_data;

typedef struct		s_conf
{
	int				save;
	const char		*map_src;
}					t_conf;

typedef struct			s_srcs
{
	char*				code;
	unsigned int		size;
	char*				src;
}						t_srcs;

typedef struct			s_colors
{
	char*				code;
	unsigned int		size;
	int					color;
	int					is_set;
}						t_colors;

typedef struct			s_resolution
{
	char*				code;
	unsigned int		size;
	int					width;
	int					height;
	int					is_set;
}						t_resolution;

typedef struct			s_texture
{
	int					texture_x;
	int					texture_y;
	int					texture_color;
	double				texture_position;
	t_data				*texture;
}						t_texture;


typedef struct			s_coordinates
{
	double				x;
	double				y;
}						t_coordinates;

typedef struct			s_cartesian_vector
{
	t_coordinates		dir;
}						t_cartesian_vector;

typedef struct			s_ray
{
	t_coordinates		dir;
	t_coordinates		side_dist;
	t_coordinates		delta_dist;
	double				perp_wall_dist;
	double				wall_x;
	int					step_X;
	int					step_Y;

}						t_ray;

typedef struct			s_polar_vector
{
	double				angle;
	double				size;
}						t_polar_vector;


typedef struct			s_start
{
	t_coordinates		pos;
	int					is_set;
	char				dir;
}						t_start;

typedef struct			s_map_line
{
	char				*line;
	int					size;
}						t_map_line;

typedef struct			s_map_array
{
	t_map_line			**lines;
	int					size;
}						t_map_array;

typedef struct			s_actions
{
	int					is_asked;
	int					keycode;
	int					(*fun)(void *);
}						t_action;

typedef struct		s_env
{
	t_conf			conf;
	t_srcs			g_srcs[MAX_SRCS];
	t_colors		g_colors[MAX_COLORS];
	t_resolution	r;
	t_map_array		map_array;
	t_start			player_start;
	t_coordinates	try_to_run_dir;
	t_coordinates	current_pos;
	char			**map_char;
	void			*mlx;
	void			*win;
	t_action		actions[MAX_ACTIONS];
	t_data			imgs[MAX_IMGS];
	t_data			textures[MAX_TEX];
	double			fov_angle;
	t_coordinates	direction;
	t_coordinates	plane;
	int				side;
	int				lineheight;
	int				count;
	int				draw_start;
	int				draw_end;
}					t_env;

typedef struct			s_parsing
{
	int					(*parser)(t_env *, const char **);
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

typedef struct			s_map_parsing
{
	char const			*authorized_chars;
	int					(*parser)(int i, int j, char c, t_env *);
	int					replace;
}						t_map_parsing;

typedef struct			s_map_rec_datas
{
	int					fd;
	char				*line;
	int					i;
	int					ret_gnl;
}						t_map_rec_datas;

void	args_parse(t_env *env, int argc, char const *argv[]);
void	check_save_arg(t_env *env, char const *argv[]);
void	free_array(char **splitted);
void	free_env(t_env *env);
int		get_colors_from_line(const char *line);
void	init_colors(t_env *env);
void	init_srcs(t_env *env);
int		is_map(t_env *env, const char **params);
int		parse_file(t_env *env);
int		parse_line(t_env *datas, char *line);
int		parse_map_int(t_env *env, t_map_rec_datas datas);
int		parse_map(t_env *env, int fd, char *line);
int		parse_value(char const *arg);
int		set_colors_fc(t_env *env, const char **params);
int		set_resolution(t_env *env, const char **params);
void	set_src_map(t_env *env, char const *argv[]);
int		set_srcs(t_env *env, const char **params);
int		test_line_for_map(char *line, t_env *env, int x);


/*
** ************************************************************************** **
** 									COMMON                                    **
** ************************************************************************** **
*/

void	quit_app(t_env *env, const char *message, int code);
int		key_release(int keycode, t_env *env);
int		key_press(int keycode, t_env *env);
int		quit_cub3d(void *v_env);
int		close_window(t_env *env);

/*
** ************************************************************************** **
** 									GAME                                      **
** ************************************************************************** **
*/

int		print_img(t_env *env);
void	init_actions(t_env *env);
void	init_imgs(t_env *env);
void	init_fov(t_env *env);
int		init_textures(t_env *env);
void	start_cub_3d(t_env *env);
void	rotation(t_env *env, double rotspeed);
void	calc_dir(t_cartesian_vector *vector, float angle);
int		rotate_left(void *v_env);
int		rotate_rigth(void *v_env);
int		actually_run(void *v_env);
int		mock_actions_fun(void *v_env);
int		run_up(void *v_env);
int		run_down(void *v_env);
int		run_right(void *v_env);
int		run_left(void *v_env);

#endif
