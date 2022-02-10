/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_srcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/10 11:07:12 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	error_quit(t_env *env, char *args[3], int i)
{
	if (env->g_srcs[i].src != NULL)
	{
		printf("%s is set twice or more times\n", args[0]);
		return (-EXIT_FAILURE);
	}
	else if (!args[1] || args[2])
	{
		printf("There is an issue with the source for %s\n", args[0]);
		return (-EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	set_srcs(t_env *env, char *args[3])
{
	int	i;
	int	ret;

	ret = EXIT_CODE_NOT_FOUND;
	i = MAX_SRCS;
	if (!args[0] || !args[1])
		return (EXIT_CODE_NOT_FOUND);
	while (--i >= 0)
	{
		if (ft_strncmp(args[0], env->g_srcs[i].code, env->g_srcs[i].size) \
		== 0 && ft_strlen(args[0]) == env->g_srcs[i].size)
		{
			if (error_quit(env, args, i) != EXIT_SUCCESS)
				return (-EXIT_FAILURE);
			env->g_srcs[i].src = ft_strdup(args[1]);
			ret = EXIT_CODE_FOUND;
		}
	}
	return (ret);
}
