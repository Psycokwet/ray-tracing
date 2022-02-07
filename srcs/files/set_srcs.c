/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_srcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/07 10:57:58 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	set_srcs(t_env *env, const char **params)
{
	int	i;
	int	ret;

	ret = EXIT_CODE_NOT_FOUND;
	i = MAX_SRCS;
	while (--i >= 0)
	{
		if (ft_strncmp(params[0], env->g_srcs[i].code, env->g_srcs[i].size) \
		== 0 && ft_strlen(params[0]) == env->g_srcs[i].size)
		{
			if (env->g_srcs[i].src != NULL)
			{
				printf("%s is set twice or more times\n", params[0]);
				return (-EXIT_FAILURE);
			}
			else if (!params[1] || params[2])
			{
				printf("There is an issue with the source for %s\n", params[0]);
				return (-EXIT_FAILURE);
			}
			env->g_srcs[i].src = ft_strdup(params[1]);
			ret = EXIT_CODE_FOUND;
		}
	}
	return (ret);
}
