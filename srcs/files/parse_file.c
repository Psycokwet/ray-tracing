/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/13 10:20:55 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"

int	parse_file(t_env *env)
{
	int		fd;
	char	*line;
	int		ret;

	ret = -RETURN_FAILURE;
	init_srcs(env);
	init_colors(env);
	env->r = (t_resolution){"R", 1, -1, -1, -1};
	env->g_colors[CODE_FLOOR] = (t_colors){"F", 1, -1, -1};
	env->g_colors[CODE_CEILING] = (t_colors){"C", 1, -1, -1};
	if ((fd = open(env->conf.map_src, O_RDONLY)) < 0)
	{
		printf("failed to open the map for reading\n");
		exit(EXIT_ARGS_FAILURE);
	}
	while (get_next_line(fd, &line) > 0)
	{
		ret = parse_line(env, line);
		if (ret == EXIT_CODE_MAP_FOUND)
		{
			ret = parse_map(env, line, fd);
			break ;
		}
		else if (RETURN_SUCCES > ret)
		{
			printf("cleaning -> %s\n", line);
			get_next_line(-1, NULL);
			break ;
		}
		else
		{
			printf("-> %s\n", line);
			free(line);
		}
	}
	free(line);
	close(fd);
	return (ret);
}
