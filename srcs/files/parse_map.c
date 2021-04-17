/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/17 20:12:11 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"

int id_dir(int i, int j, char c, t_env *env){
	if(env->player_start.is_set == 1)
		return (-EXIT_FAILURE);
	env->player_start = (t_start){(t_position){i, j }, 1, c};
	return (EXIT_SUCCESS);
}

int id_mob(int i, int j, char c, t_env *env){
	return (EXIT_SUCCESS);
}


typedef struct			s_map_parsing
{
	char const			*authorized_chars;
	int					(*parser)(int i, int j, char c, t_env *);
}						t_map_parsing;

#define MAX_MAP_PARSING 3
static const t_map_parsing g_map_parsings[3] = {
	(t_map_parsing){AUTHORIZED_ON_MAP, NULL},
	(t_map_parsing){AUTHORIZED_ON_MAP_MOB, &id_mob},
	(t_map_parsing){AUTHORIZED_ON_MAP_DIR, &id_dir},
};

int test_line_for_map(char *line, t_env *env)
{
	int j;
	int i;
	char *ret;

	j = 0;
	i = 0;
	ret = NULL;
	while (line[i])
	{
		while (j < MAX_MAP_PARSING)
		{
			ret = ft_strchr(g_map_parsings[j].authorized_chars, line[i]);
			if (ret != NULL){
				if (g_map_parsings[j].parser)
					if (g_map_parsings[j].parser(i, j, line[i], env) < EXIT_SUCCESS)
						return (-EXIT_FAILURE);
				break;
			}
			j++;
		}
		if(ret == NULL){
			return (-EXIT_FAILURE);
		}
		j = 0;
		i++;
	}
	return (i);
}

int	parse_map_int(t_env *env, int fd, char *line, int i, int ret_gnl)
{
	char *nextLine;
	int line_size;
	t_map_line *tmp;

	line_size = 0;
	nextLine = NULL;
	if(!line) 
		return (-EXIT_FAILURE);
	line_size = test_line_for_map(line, env);
	if (line_size < EXIT_SUCCESS)
	{
		free(line);
		return (-EXIT_FAILURE);
	}
	else if(line[0])
	{
		ret_gnl = get_next_line(fd, &nextLine);
		if(ret_gnl >= 0)
		{
			if(parse_map_int(env, fd, nextLine, i+1, ret_gnl) < EXIT_SUCCESS){
				free(line);
				return (-EXIT_FAILURE);
			}
			tmp = (t_map_line*)malloc(sizeof(t_map_line));
			if(tmp == NULL)
				return (-EXIT_FAILURE);
			tmp->line = line;
			tmp->size = line_size;
			env->map_array.lines[i] = tmp;
			// env->map_array[i] = (t_map_line*)malloc(sizeof(t_map_line));;
		}
	}
	else if(ret_gnl == 0)
	{
		env->map_array.lines = (t_map_line**)malloc(sizeof(t_map_line*) * (i));
		if(env->map_array.lines == NULL)
			return (-EXIT_FAILURE);
		env->map_array.size = i;
		free(line);
	}
	else{
		free(line);
		return (-EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_map(t_env *env, int fd, char *line)
{
	int ret;
	
	env->map_array.size = -1;
	ret = parse_map_int(env, fd, ft_strdup(line), 0, 1);
	if(ret < EXIT_SUCCESS)
		return (ret);
	//Other map verification to check for holes

	return (ret);
}
