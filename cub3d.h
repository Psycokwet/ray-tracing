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
# define SAVE_ARG "--save"
# define USAGE "Usage : MAP.cub [--save]"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;



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

void	args_parse(int argc, char const *argv[]);

#endif
