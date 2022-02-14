/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/14 15:19:15 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libs/libft/libft.h"
# include "../libs/libft/get_next_line.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

# define BLANK_CHARS " \t\r\v\f"
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
# define USAGE					"Usage : MAP.cub"
# define WALL					"1"
# define INSIDE_MAX_TYPE		7
# define INSIDE					"023NWES"
# define AUTHORIZED_ON_MAP		"1230 "
# define AUTHORIZED_ON_MAP_DIR	"NWES"
# define DIR_NORTH				'N'
# define DIR_WEST				'W'
# define DIR_EAST				'E'
# define DIR_SOUTH				'S'

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
# define RUN_STEP				0.05F
# define WALL_HIT_BOX			0.3
# define QUOTIENT_MOVE			1

# ifndef M_PI
#  define M_PI					3.14159265358979323846
# endif

# define XK_ESCAPE						0xff1b
# define ESCAPE_ID						0

/* Move left, left arrow */
# define XK_LEFT						0xff51

/* Move left, left arrow */
# define ROTATE_LEFT_ID					1

/* Move right, right arrow */
# define XK_RIGHT						0xff53

/* Move right, right arrow */
# define ROTATE_RIGHT_ID				2

/* U+0061 LATIN SMALL LETTER A */
# define XK_LOW_A						0x0061

# define GO_LEFT_A_ID					3

/* U+0064 LATIN SMALL LETTER D */
# define XK_LOW_D						0x0064
# define GO_RIGTH_D_ID					4

/* U+0073 LATIN SMALL LETTER S */
# define XK_LOW_S						0x0073
# define GO_BACK_S_ID					5

/* U+0077 LATIN SMALL LETTER W */
# define XK_LOW_W						0x0077
# define GO_FRONT_W_ID					6

# define ACTUALLY_RUN					7

# define XK_LOW_E						0x0065
# define E_KEY							8

# define MAX_SRCS		5
# define MAX_COLORS		2
# define MAX_ACTIONS	10
# define MAX_IMGS		7
# define MAX_TEX		4
# define MAX_PARSING	3
# define DESTROY_NOTIFY_FIX 33

// # define PATHFLOOR "/home/batche/Documents/cub3D/textures/floor.xpm"
// # define PATHCEIL "/home/batche/Documents/cub3D/textures/ceil.xpm"
// # define PATHDOOROPEN "/home/batche/Documents/cub3D/textures/door_open.xpm"
// # define PATHDOORCLOSE "/home/batche/Documents/cub3D/textures/door_close.xpm"

# define PATHFLOOR "./textures/floor.xpm"
# define PATHCEIL "./textures/ceil.xpm"
# define PATHDOOROPEN "./textures/door_open.xpm"
# define PATHDOORCLOSE "./textures/door_close.xpm"
# define GUN0 "./textures/GUN_0.xpm"
# define GUN1 "./textures/GUN_1.xpm"
# define GUN2 "./textures/GUN_2.xpm"
# define GUN3 "./textures/GUN_3.xpm"
# define GUN4 "./textures/GUN_4.xpm"
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_data;

typedef struct s_conf
{
	int				save;
	const char		*map_src;
}					t_conf;

typedef struct s_srcs
{
	char				*code;
	unsigned int		size;
	char				*src;
}						t_srcs;

typedef struct s_colors
{
	char				*code;
	unsigned int		size;
	int					color;
	int					is_set;
}						t_colors;

typedef struct s_resolution
{
	char				*code;
	unsigned int		size;
	int					width;
	int					height;
	int					is_set;
}						t_resolution;

typedef struct s_texture
{
	int					texture_x;
	int					texture_y;
	int					texture_color;
	double				texture_position;
	t_data				*texture;
}						t_texture;

typedef struct s_coordinates
{
	double				x;
	double				y;
}						t_coordinates;

typedef struct s_cartesian_vector
{
	t_coordinates		dir;
}						t_cartesian_vector;

typedef struct s_ray
{
	t_coordinates		dir;
	t_coordinates		side_dist;
	t_coordinates		delta_dist;
	double				perp_wall_dist;
	double				wall_x;
	int					step_x;
	int					step_y;

}						t_ray;

typedef struct s_polar_vector
{
	double				angle;
	double				size;
}						t_polar_vector;

typedef struct s_start
{
	t_coordinates		pos;
	int					is_set;
	char				dir;
}						t_start;

typedef struct s_map_line
{
	char				*line;
	int					size;
}						t_map_line;

typedef struct s_map_array
{
	t_map_line			**lines;
	int					size;
}						t_map_array;

typedef struct s_actions
{
	int					is_asked;
	int					keycode;
	int					(*fun)(void *);
}						t_action;

typedef struct s_env
{
	t_conf			conf;
	t_srcs			g_srcs[MAX_SRCS];
	t_colors		g_colors[MAX_COLORS];
	t_resolution	r;
	t_map_array		map_array;
	t_start			player_start;
	t_coordinates	try_to_run_dir;
	t_coordinates	current_pos;
	t_coordinates	mouse_po;
	char			**map_char;
	void			*mlx;
	void			*win;
	t_action		actions[MAX_ACTIONS];
	t_data			imgs[MAX_IMGS];
	t_data			textures[MAX_TEX];
	t_data			floor_ceil[3];
	t_data			gun[5];
	t_data			door[2];
	double			fov_angle;
	t_coordinates	direction;
	t_coordinates	plane;
	int				side;
	int				lineheight;
	int				count;
	int				draw_start;
	int				draw_end;
	double			row_dist;
	double			pos_z;
	int				map_x;
	int				map_y;
	double			floor_step_x;
	double			floor_step_y;
	double			floor_x;
	double			floor_y;
	int				y_minmap;
	int				img_gun;
	int				mouse_click;
}					t_env;

typedef struct s_parsing
{
	int					(*parser)(t_env *, char *[3]);
}						t_parsing;

/*
** ************************************************************************** **
** 									COLORS                                    **
** ************************************************************************** **
*/

int		add_shade(double dist, int trgb);
int		get_opposite(int trgb);
int		create_trgb(int t, int r, int g, int b);

/*
** ************************************************************************** **
** 									IMG                                       **
** ************************************************************************** **
*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		my_mlx_pixel_get(t_data *datas, int x, int y);
/*
** ************************************************************************** **
** 									FILES                                     **
** ************************************************************************** **
*/

typedef struct s_map_parsing
{
	char const			*authorized_chars;
	int					(*parser)(int i, int j, char c, t_env *);
	int					replace;
}						t_map_parsing;

typedef struct s_map_rec_datas
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
double	init_rad(char c);
int		is_map(t_env *env, char *args[3]);
int		parse_file(t_env *env);
int		parse_line(t_env *datas, char *line);
int		parse_map_int(t_env *env, t_map_rec_datas datas);
int		parse_map(t_env *env, int fd, char *line);
int		parse_value(char const *arg);
int		set_colors_fc(t_env *env, char *args[3]);
void	set_src_map(t_env *env, char const *argv[]);
int		set_srcs(t_env *env, char *args[3]);
int		test_line_for_map(char *line, t_env *env, int x);
int		game_loop(t_env *env);

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
int		get_text_x(t_texture *tex, t_env *env, t_ray *ray);
void	get_texture(t_env *env, t_texture *text, t_ray *ray);
void	texturing(t_data *datas, int x, t_env *env, t_ray *ray);
void	draw_walls(t_data *datas, t_env *env);
void	stepping(t_env *env, t_ray *ray);
void	wall_hit(t_env *env, t_ray *ray, int hit);
void	lineheight(t_env *env, t_ray *ray);
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

/**
 * @brief Bonus
 */
int		check_srcs_bonus(t_env *env);
int		mouse_rot(int x, int y, void *v_env);
int		mouse_leave(void *v_env);
void	get_cell_floor_text(t_texture *floor, t_texture *ceil, t_env *env);
void	stepping_floor(t_ray *ray_1, t_ray *ray_2, t_env *env);
void	floor_ceil_cast(t_env *env, int y);
void	draw_ceiling_floor(t_env *env);
void	make_map(t_env *env);
int		check_door_bonus(t_env *env);
int		open_door(void *v_env);
int		could_open_x(t_env *env, int x, int y);
int		could_open_y(t_env *env, int x, int y);
void	could_close_x_1(t_env *env, int x, int y);
void	could_close_x_2(t_env *env, int x, int y);
void	could_close_y_1(t_env *env, int x, int y);
void	could_close_y_2(t_env *env, int x, int y);
void	draw_gun(t_env *env, int img_gun);
int		fire_push(int button, int x, int y, void *v_env);
int		fire_realase(int button, int x, int y, void *v_env);
int		fire(void *v_env);

#endif
