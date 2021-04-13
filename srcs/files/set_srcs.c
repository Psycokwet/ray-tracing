/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_srcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/13 10:20:58 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"

int	set_srcs(t_env *env, const char **params)
{
	int			i;
	int			ret;
	const char	*code = params[0];

	ret = EXIT_CODE_NOT_FOUND;
	i = MAX_SRCS;
	while (--i >= 0)
	{
		if (ft_strncmp(code, env->g_srcs[i].code,
			env->g_srcs[i].size) == 0 && ft_strlen(code) == env->g_srcs[i].size)
		{
			if (env->g_srcs[i].src != NULL)
			{
				printf("%s is set twice or more times\n", code);
				ret = -EXIT_FAILURE;
				break ;
			}
			else if (!params[1] || params[2])
			{
				printf("There is an issue with the source for %s\n", code);
				ret = -EXIT_FAILURE;
				break ;
			}
			env->g_srcs[i].src = ft_strdup(params[1]);
			ret = EXIT_CODE_FOUND;
		}
	}
	return (ret);
}
