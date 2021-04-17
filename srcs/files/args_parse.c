/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/17 22:33:40 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


int is_blank(char c)
{
	return (c == ' ' || c == 0 || (c > 8 && c < 14) ? 1: 0);
}

static int	skip_blanks(const char *str)
{
	int i;

	i = 0;
	while (is_blank(str[i]) == 1)
		i++;
	return (i);
}

static int	skip_blanks_up_to_down(t_env *env, unsigned int column)
{
	int i;

	i = 0;
	while (i < env->map_array.size )
	{
		while(env->map_array.lines[i]->size < column)
			i++;
		if(is_blank(env->map_array.lines[i]->line[column]) != 1)
			break;
		i++;
	}
	return (i);
}

static int	skip_blanks_down_to_up(t_env *env, unsigned int column)
{
	int i;

	i = env->map_array.size - 1;
	while (i >= 0)
	{
		while(env->map_array.lines[i]->size < column)
			i--;
		if(is_blank(env->map_array.lines[i]->line[column]) != 1)
			break;
		i--;
	}
	return (i);
}



static int	skip_blanks_reverse(const char *str, unsigned int size)
{
	int i;

	i = size -1;
	while (i > 0 && is_blank(str[i]) == 1)
		i--;
	return (i);
}

int		check_map_for_holes(t_env *env)
{
	unsigned int i;
	unsigned int max_width;

	i = 0;
	max_width = 0;
	while(env->map_array.size > i){
		if(!(env->map_array.lines[i]->line[skip_blanks(env->map_array.lines[i]->line)] == '1' && env->map_array.lines[i]->line[skip_blanks_reverse(env->map_array.lines[i]->line, env->map_array.lines[i]->size)] == '1'))
		{
			printf("ERRORe %d:%c:%c\n",i, env->map_array.lines[i]->line[skip_blanks(env->map_array.lines[i]->line)], env->map_array.lines[i]->line[skip_blanks_reverse(env->map_array.lines[i]->line, env->map_array.lines[i]->size)] );
		}
		if(env->map_array.lines[i]->size > max_width)
			max_width = env->map_array.lines[i]->size;
		i++;
	}
	i = 0;
	while(max_width > i){
		if(!(env->map_array.lines[skip_blanks_up_to_down(env, i)]->line[i] == '1' && env->map_array.lines[skip_blanks_down_to_up(env, i)]->line[i] == '1'))
		{
			printf("ERROReuh %s %d:%c:%d\n",env->map_array.lines[skip_blanks_down_to_up(env, i)]->line, i,  env->map_array.lines[skip_blanks_up_to_down(env, i)]->line[i],  env->map_array.lines[skip_blanks_down_to_up(env, i)]->line[i]  );
		}
			// printf("nope :(ERROR %c\n", env->map_array.lines[i]->line[skip_blanks(env->map_array.lines[i]->line)]);
		i++;
	}
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
		printf("Error, there is not enought arguments.\n%s\n", USAGE);
		exit(EXIT_ARGS_FAILURE);
	}
	set_src_map(env, argv);
	if (argc == 3)
		check_save_arg(env, argv);
	if (parse_file(env) < RETURN_SUCCES)
	{
		printf("Error, while reading the file\n");
		free_env(env);
		exit(-RETURN_FAILURE);
	}
	//tmp to change
	check_map_for_holes(env);
	printf("ok %s %d %d %d\n", env->g_srcs[0].src, env->r.width, env->g_colors[0].color, env->map_array.size);

		for(int i = 0; env->map_array.size > i; i++)
			printf("RESULT %s, %u %d\n", env->map_array.lines[i]->line, env->map_array.lines[i]->size, i);
	free_env(env);
}
