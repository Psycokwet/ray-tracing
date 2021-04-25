/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/24 22:13:52 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		is_inside(char c)
{
	int i;

	i = 0;
	while (i < INSIDE_MAX_TYPE)
	{
		if (INSIDE[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		check_map_for_holes(t_env *env)
{
	int line;
	int column;

	line = 0;
	column = 0;
	while (env->map_array.size > line)
	{
		while (env->map_array.lines[line]->size > column)
			if ((is_inside(env->map_array.lines[line]->line[column]) == 1) &&
			((line > 0 && is_inside(env->map_array.lines[line - 1]->line[column
			]) == 0 && env->map_array.lines[line - 1]->line[column] != '1') || (
			line + 1 < env->map_array.size && is_inside(env->map_array.lines[
			line + 1]->line[column]) == 0 && env->map_array.lines[line + 1]->
			line[column] != '1') || (column > 0 && is_inside(env->map_array.
			lines[line]->line[column - 1]) == 0 && env->map_array.lines[line]->
			line[column - 1] != '1') || (column + 1 <= env->map_array.lines[line
			]->size && is_inside(env->map_array.lines[line]->line[column + 1])
			== 0 && env->map_array.lines[line]->line[column + 1] != '1')))
				return (-EXIT_FAILURE);
			else
				column++;
		column = 0;
		line++;
	}
	return (EXIT_SUCCESS);
}

void	args_parse(t_env *env, int argc, char const *argv[])
{
	const char *name;

	name = argv[0];
	if (argc > 3)
	{
		printf("Error, there is too much arguments.\n%s\n", USAGE);
		exit(EXIT_ARGS_FAILURE);
	}
	if (argc < 2)
	{
		printf("Error, there is not enough arguments.\n%s\n", USAGE);
		exit(EXIT_ARGS_FAILURE);
	}
	set_src_map(env, argv);
	if (argc == 3)
		check_save_arg(env, argv);
	if (parse_file(env) < RETURN_SUCCES)
		quit_app(env, "Error, while reading the file", -EXIT_ARGS_FAILURE);
	if (check_map_for_holes(env) < EXIT_SUCCESS)
		quit_app(env, "Error, the map contains holes", -EXIT_FAILURE);
}
