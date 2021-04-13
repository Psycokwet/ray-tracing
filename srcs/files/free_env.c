/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/13 10:21:38 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"

void	free_env(t_env *env)
{
	int i;

	i = 0;
	while (i < MAX_SRCS)
	{
		if (env->g_srcs[i].src != NULL)
			free(env->g_srcs[i].src);
		env->g_srcs[i].src = NULL;
		i++;
	}
	env->conf.map_src = NULL;
}
