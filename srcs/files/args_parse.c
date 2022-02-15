/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/15 19:42:04 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	make_map_char(t_env *env)
{
	int	i;

	env->map_char = malloc(sizeof(char *) * (env->map_array.size + 1));
	if (!env->map_char)
		return (EXIT_FAILURE);
	i = 0;
	while (i < env->map_array.size)
	{
		env->map_char[i] = ft_strdup(env->map_array.lines[i]->line);
		i++;
	}
	env->map_char[i] = NULL;
	return (EXIT_SUCCESS);
}

void	args_parse(t_env *env, int argc, char const *argv[])
{
	if (argc > 2)
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
	if (parse_file(env) < RETURN_SUCCES)
		quit_app(env, "Error, while reading the file\n", -EXIT_ARGS_FAILURE);
	if (env->player_start.is_set == false)
		quit_app(env, "Player is not set\n", -EXIT_ARGS_FAILURE);
	if (check_texs(env) < EXIT_SUCCESS)
		quit_app(env, "Missing some textures.\n", -EXIT_FAILURE);
	if (check_color(env) < EXIT_SUCCESS)
		quit_app(env, "Missing some colors.\n", -EXIT_FAILURE);
	if (check_map_for_holes(env) < EXIT_SUCCESS)
		quit_app(env, "Error, the map contains holes\n", -EXIT_FAILURE);
	if (make_map_char(&(*env)) < EXIT_SUCCESS)
		quit_app(env, "Malloc failed.", -EXIT_FAILURE);
}
