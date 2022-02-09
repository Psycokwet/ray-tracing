/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/09 15:38:02 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_env(t_env *env)
{
	init_srcs(env);
	init_colors(env);
}

int	open_map(t_env *env)
{
	int			fd;

	fd = open(env->conf.map_src, __O_DIRECTORY);
	if (fd > 0)
	{
		printf("Argument is a directory\n");
		close(fd);
		exit(EXIT_ARGS_FAILURE);
	}
	fd = open(env->conf.map_src, O_RDONLY);
	if (fd < 0)
	{
		printf("Failed to open the map for reading\n");
		exit(EXIT_ARGS_FAILURE);
	}
	return (fd);
}

int	parse_file(t_env *env)
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
