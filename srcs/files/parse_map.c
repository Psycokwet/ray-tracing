/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/17 17:44:39 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"

int	parse_map_int(t_env *env, int fd, char *line, int i, int ret_gnl)
{
	char *nextLine;

	nextLine = NULL;
	if(!line)
		return (-EXIT_FAILURE);
	else if(line[0])
	{
		ret_gnl = get_next_line(fd, &nextLine);
		if(ret_gnl >= 0)
		{
			if(parse_map_int(env, fd, nextLine, i+1, ret_gnl) < EXIT_SUCCESS){
				free(line);
				return (-EXIT_FAILURE);
			}
			env->map_array[i] = line;
		}
	}
	else if(ret_gnl == 0)
	{
		env->map_array = (char**)malloc(sizeof(char*) * (i+1));
		if(env->map_array == NULL)
			return (-EXIT_FAILURE);
		env->map_array[i] = NULL;
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
	
	env->map_array = NULL;
	ret = parse_map_int(env, fd, ft_strdup(line), 0, 1);
printf("EXIT %d\n", ret);
	if(ret < EXIT_SUCCESS)
		return (ret);


	return (ret);
}
