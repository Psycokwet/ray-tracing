/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_save_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/05 17:18:52 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"


#define MAX_PARSING		4

static const t_parsing g_parsings[MAX_PARSING] = {
	(t_parsing){&is_map},
	(t_parsing){&set_resolution},
	(t_parsing){&set_colorsFC},
	(t_parsing){&set_srcs},
};


int	set_srcs(t_env * env, const char **params)
{
	int i;
	int ret;

	ret = EXIT_CODE_NOT_FOUND;

	i = MAX_SRCS;
	char * code = params[0];
	while (--i >= 0)
	{
		if (ft_strncmp(code, env->g_srcs[i].code,
			env->g_srcs[i].size) == 0 && ft_strlen(code) == env->g_srcs[i].size)
		{
			if(env->g_srcs[i].src != NULL)
			{
				printf("%s is set twice or more times\n", code);
				ret = -EXIT_FAILURE;
				break;
			}
			else if(!params[1] || params[2]){
				printf("There is an issue with the source for %s\n",  code);
				ret = -EXIT_FAILURE;
				break;
			}
			env->g_srcs[i].src = ft_strdup(params[1]);
			ret = EXIT_CODE_FOUND;
		}
	}
	return (ret);
}

int is_map(t_env * env, const char **params){
	// return EXIT_CODE_MAP_FOUND;
	return EXIT_CODE_NOT_FOUND;
}

int set_resolution(t_env * env, const char **params){
	// return EXIT_CODE_FOUND;
	return EXIT_CODE_NOT_FOUND;
}

int set_colorsFC(t_env * env, const char **params){

	// return EXIT_CODE_FOUND;
	return EXIT_CODE_NOT_FOUND;
}


void	freeArray(char **splitted){
	int i;

	i = 0;
	for(i = 0; splitted[i] != NULL;i++){
		free(splitted[i]);
		splitted[i] = NULL;
	}
	free(splitted);
}

int		parse_line(t_env *datas, char *line)
{
	int ret;
	int command_id;
	char **splitted;

	ret = -EXIT_CODE_NOT_FOUND;
	command_id = MAX_PARSING;
	splitted = ft_split(line, ' ');
	if(!splitted[0]){
		free(splitted);
		return (EXIT_CODE_NOT_FOUND);
	}
	while (--command_id >= 0)
	{
		ret = g_parsings[command_id].parser(datas, splitted);
		if (ret != EXIT_CODE_NOT_FOUND){
			break;
		}
	}
	freeArray(splitted);
	splitted = NULL;
	return (ret);
}

void free_env(t_env *env){
	int i;

	i = 0;
	while(i < MAX_SRCS){
		if(env->g_srcs[i].src != NULL)
			free(env->g_srcs[i].src);
		env->g_srcs[i].src = NULL;
		i++;
	}
	env->conf.map_src = NULL;
}

void	init_srcs(t_env *env){
    env->g_srcs[CODE_NO] = (t_srcs){"NO", ft_strlen("NO"), NULL};
    env->g_srcs[CODE_SO] = (t_srcs){"SO", ft_strlen("SO"), NULL};
    env->g_srcs[CODE_EA] = (t_srcs){"EA", ft_strlen("EA"), NULL};
    env->g_srcs[CODE_WE] = (t_srcs){"WE", ft_strlen("WE"), NULL};
    env->g_srcs[CODE_S] = (t_srcs){"S", ft_strlen("S"), NULL};
}

void	init_colors(t_env *env){
    env->g_colors[CODE_FLOOR] = (t_colors){"F", 0, -1};
    env->g_colors[CODE_CEILING] = (t_colors){"C", 0, -1};
}



int	parse_file(t_env *env){
    int     fd;
    char    *line;
	int		ret;
	
	ret = -RETURN_FAILURE;
    init_srcs(env);
	init_colors(env);
    if ((fd = open(env->conf.map_src, O_RDONLY)) < 0)
    {
        printf("failed to open the map for reading\n");
        exit(EXIT_ARGS_FAILURE);
    }
    while (get_next_line(fd, &line) > 0)
    {
		ret = parse_line(env, line);
		if(ret == EXIT_CODE_MAP_FOUND){
			ret = parse_map(env, line, fd);
			break;
		}
		else if(0 > ret){
        	printf("-> %s\n", line);
			break;
		}
		else {
        	printf("-> %s\n", line);
        	free(line);
		}
    }
    free(line);
    close(fd);
	return (ret);
}

int parse_map(t_env *env, int fd, char *line){

    free(line);
}