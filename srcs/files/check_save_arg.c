/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_save_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/07 08:52:11 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_save_arg(t_env *env, char const *argv[])
{
	int	s1;
	int	s2;

	s1 = ft_strlen(SAVE_ARG);
	s2 = ft_strlen(argv[2]);
	if (ft_memcmp(SAVE_ARG, argv[2], s2) != 0 || s1 != s2)
	{
		printf("Error, the second argument doesn't fit.\n%s\n", USAGE);
		exit(EXIT_ARGS_FAILURE);
	}
	env->conf.save = 1;
}
