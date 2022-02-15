/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/15 15:38:20 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_color(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_COLORS)
	{
		if (env->g_colors[i].is_set == false)
			return (-EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_texs(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_SRCS)
	{
		if (env->g_srcs[i].src == NULL)
			return (-EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
