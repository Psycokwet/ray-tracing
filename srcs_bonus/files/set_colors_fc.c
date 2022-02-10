/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors_fc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/10 11:07:02 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_colors_fc(t_env *env, char *args[3])
{
	int		i;
	int		color;
	int		ret;
	char	*code;

	code = args[0];
	ret = EXIT_CODE_NOT_FOUND;
	i = MAX_COLORS;
	if (!args[0] || !args[1])
		return (EXIT_CODE_NOT_FOUND);
	while (--i >= 0)
	{
		if (ft_strncmp(code, env->g_colors[i].code, env->g_colors[i].size) == 0 \
			&& ft_strlen(code) == env->g_colors[i].size)
		{
			color = get_colors_from_line(args[1]);
			if (env->g_colors[i].is_set == 1 || color < 0)
				return (-EXIT_FAILURE);
			env->g_colors[i].color = color;
			env->g_colors[i].is_set = 1;
			ret = EXIT_CODE_FOUND;
			break ;
		}
	}
	return (ret);
}
