/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/24 15:38:27 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int is_inside(char c)
{
			// printf("is_insid\n");
	int i = 0;
	while (i < INSIDE_MAX_TYPE)
	{
		if(INSIDE[i] == c){

			// printf("skip_chars_down_to_up IS IN %d:%d\n", INSIDE[i], c);
			return 1;
		}
		i++;
	}
	// printf("is_insid NOPE, %c\n", c);
	return 0;
}

int		check_map_for_holes(t_env *env)
{
	unsigned int line;
	unsigned int column;

	line = 0;
	column = 0;
	while(env->map_array.size > line){
		while(env->map_array.lines[line]->size > column){
			if(is_inside(env->map_array.lines[line]->line[column]) == 1){
				if(line > 0 && is_inside(env->map_array.lines[line - 1]->line[column]) == 0 && env->map_array.lines[line - 1]->line[column] != '1')
					return (-EXIT_FAILURE);
				if(line + 1 < env->map_array.size && is_inside(env->map_array.lines[line + 1]->line[column]) == 0 && env->map_array.lines[line + 1]->line[column] != '1')
					return (-EXIT_FAILURE);
				if(column > 0 && is_inside(env->map_array.lines[line]->line[column - 1]) == 0 && env->map_array.lines[line]->line[column - 1] != '1')
					return (-EXIT_FAILURE);
				if(column + 1 < env->map_array.lines[line]->size  && is_inside(env->map_array.lines[line]->line[column + 1]) == 0  && env->map_array.lines[line]->line[column + 1] != '1')
					return (-EXIT_FAILURE);
			}
			column++;
		}
		column=0;
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
	if(check_map_for_holes(env) < EXIT_SUCCESS)
		quit_app(env, "Error, the map contains holes", -EXIT_FAILURE);
	printf("ok %s %d %d %d\n", env->g_srcs[0].src, env->r.width, env->g_colors[0].color, env->map_array.size);

		for(int i = 0; env->map_array.size > i; i++)
			printf("RESULT %s, %u %d\n", env->map_array.lines[i]->line, env->map_array.lines[i]->size, i);
	
		free_env(env);
}
