/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors_fc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/13 10:25:34 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"

int	set_colors_fc(t_env *env, const char **params)
{
	int			i;
	int			color;
	int			ret;
	const char	*code = params[0];

	ret = EXIT_CODE_NOT_FOUND;
	i = MAX_COLORS;
	while (--i >= 0)
	{
		if (ft_strncmp(code, env->g_colors[i].code,
			env->g_colors[i].size) == 0 && ft_strlen(code) == env->g_colors[i].size)
		{
			if (params[1] == NULL || params[2] != NULL || env->g_colors[i].is_set == 1 || (color = get_colors_from_line(params[1])) < 0)
				return (-EXIT_FAILURE);
			env->g_colors[i].color = color;
			env->g_colors[i].is_set = 1;
		}
	}
	return (ret);
}
