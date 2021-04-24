/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/24 18:20:31 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"

void	init_env(t_env *env)
{
	init_srcs(env);
	init_colors(env);
	env->r = (t_resolution){"R", 1, -1, -1, -1};
}

int		open_map(t_env *env)
{
	int		fd;

	if ((fd = open(env->conf.map_src, O_RDONLY)) < 0)
	{
		printf("failed to open the map for reading\n");
		exit(EXIT_ARGS_FAILURE);
	}
	return (fd);
}

int		parse_file(t_env *env)
{
	int		fd;
	char	*line;
	int		ret;

	ret = -RETURN_FAILURE;
	init_env(env);
	fd = open_map(env);
	while (get_next_line(fd, &line) > 0)
	{
		ret = parse_line(env, line);
		if (ret == EXIT_CODE_MAP_FOUND)
		{
			ret = parse_map(env, fd, line);
			break ;
		}
		else if (ret < RETURN_SUCCES)
			break ;
		else
			free(line);
	}
	if (ret < RETURN_SUCCES)
		get_next_line(-1, NULL);
	free(line);
	close(fd);
	return (ret);
}
