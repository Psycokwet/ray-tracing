/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/10 11:06:54 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	simple_free_and_return(char *line, int code)
{
	if (line)
		free(line);
	return (code);
}

int	parse_map_int1(t_env *env, t_map_rec_datas *datas, int line_size)
{
	t_map_line	*tmp;
	char		*next_line;

	next_line = NULL;
	datas->ret_gnl = get_next_line(datas->fd, &next_line);
	if (datas->ret_gnl >= 0)
	{
		if (parse_map_int(env, (t_map_rec_datas) \
		{datas->fd, next_line, datas->i + 1, datas->ret_gnl}) \
		< EXIT_SUCCESS)
			return (simple_free_and_return(datas->line, -EXIT_FAILURE));
		tmp = (t_map_line *)malloc(sizeof(t_map_line));
		if (tmp == NULL)
			return (-EXIT_FAILURE);
		tmp->line = datas->line;
		tmp->size = line_size;
		env->map_array.lines[datas->i] = tmp;
	}
	return (EXIT_SUCCESS);
}

int	parse_map_int(t_env *env, t_map_rec_datas datas)
{
	int	line_size;

	line_size = 0;
	if (!datas.line)
		return (-EXIT_FAILURE);
	line_size = test_line_for_map(datas.line, env, datas.i);
	if (line_size < EXIT_SUCCESS)
		return (simple_free_and_return(datas.line, -EXIT_FAILURE));
	else if (datas.line[0])
		return (parse_map_int1(env, &datas, line_size));
	else if (datas.ret_gnl == 0)
	{
		env->map_array.lines = malloc(sizeof(t_map_line *) * (datas.i));
		if (env->map_array.lines == NULL)
			return (-EXIT_FAILURE);
		env->map_array.size = datas.i;
		free(datas.line);
	}
	else
		return (simple_free_and_return(datas.line, -EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

int	parse_map(t_env *env, int fd, char *line)
{
	env->map_array.size = -1;
	return (parse_map_int(env, (t_map_rec_datas){fd, ft_strdup(line), 0, 1}));
}
