/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/07 10:57:16 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static const t_parsing	g_parsings[MAX_PARSING] = {
	(t_parsing){&is_map},
	(t_parsing){&set_resolution},
	(t_parsing){&set_colors_fc},
	(t_parsing){&set_srcs},
};

int	parse_line(t_env *datas, char *line)
{
	int		ret;
	int		command_id;
	char	**splitted;

	ret = -EXIT_CODE_NOT_FOUND;
	command_id = MAX_PARSING;
	splitted = ft_split(line, ' ');
	if (!splitted[0])
	{
		free(splitted);
		return (EXIT_CODE_NOT_FOUND);
	}
	while (--command_id >= 0)
	{
		ret = g_parsings[command_id].parser(datas, (const char **)splitted);
		if (ret != EXIT_CODE_NOT_FOUND)
			break ;
	}
	free_array(splitted);
	splitted = NULL;
	return (ret);
}
