/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/13 10:21:12 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"

int	set_resolution(t_env *env, const char **params)
{
	int tmp_height;
	int tmp_width;

	if (ft_strncmp(params[0], env->r.code,
		env->r.size) == 0 && ft_strlen(params[0]) == env->r.size)
	{
		tmp_height = parse_value(params[1]);
		if (tmp_height < 0)
			return (-EXIT_FAILURE);
		tmp_width = parse_value(params[2]);
		if (tmp_width < 0)
			return (-EXIT_FAILURE);
		if (params[3] != NULL || env->r.is_set == 1)
			return (-EXIT_FAILURE);
		env->r.height = tmp_height;
		env->r.width = tmp_width;
		env->r.is_set = 1;
		return (EXIT_CODE_FOUND);
	}
	return (EXIT_CODE_NOT_FOUND);
}
