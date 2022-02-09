/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/09 14:30:29 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	in(char c)
{
	int	i;

	i = 0;
	while (i < INSIDE_MAX_TYPE)
	{
		if (INSIDE[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_map_for_holes(t_env *env)
{
	int			l;
	int			c;
	t_map_line	**li;

	li = env->map_array.lines;
	l = 0;
	while (++l < env->map_array.size)
	{
		c = 0;
		while (li[l]->size > c)
		{
			if ((in(li[l]->line[c]) == 1) && ((l > 0 \
				&& in(li[l - 1]->line[c]) == 0 && li[l - 1]->line[c] != '1') \
				|| (l + 1 < env->map_array.size \
				&& in(li[l + 1]->line[c]) == 0 \
				&& li[l + 1]->line[c] != '1') \
				|| (c > 0 && in(li[l]->line[c - 1]) == 0 \
				&& li[l]->line[c - 1] != '1') || (c + 1 <= li[l]->size \
				&& in(li[l]->line[c + 1]) == 0 \
				&& li[l]->line[c + 1] != '1')))
				return (-EXIT_FAILURE);
			c++;
		}
	}
	return (EXIT_SUCCESS);
}

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
	const char	*name;

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
	env->direction.x = 1;
	env->direction.y = 0;
	env->plane.x = 0.0;
	env->plane.y = 0.66;
	if (argc == 3)
		check_save_arg(env, argv);
	if (parse_file(env) < RETURN_SUCCES)
		quit_app(env, "Error, while reading the file", -EXIT_ARGS_FAILURE);
	if (check_map_for_holes(env) < EXIT_SUCCESS)
		quit_app(env, "Error, the map contains holes", -EXIT_FAILURE);
	if (make_map_char(&(*env)) < EXIT_SUCCESS)
		quit_app(env, "Malloc failed.", -EXIT_FAILURE);
}
