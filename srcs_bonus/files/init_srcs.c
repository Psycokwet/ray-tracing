/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_srcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/14 15:33:21 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	init_srcs(t_env *env)
{
	env->g_srcs[CODE_NO] = (t_srcs){"NO", ft_strlen("NO"), NULL};
	env->g_srcs[CODE_SO] = (t_srcs){"SO", ft_strlen("SO"), NULL};
	env->g_srcs[CODE_EA] = (t_srcs){"EA", ft_strlen("EA"), NULL};
	env->g_srcs[CODE_WE] = (t_srcs){"WE", ft_strlen("WE"), NULL};
}
