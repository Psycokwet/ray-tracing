/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/05 17:11:14 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	args_parse(t_env *env, int argc, char const *argv[]){
	const char * name = argv[0];

	if(argc > 3){
		printf("Error, there is too much arguments.\n%s\n", USAGE);
		exit(EXIT_ARGS_FAILURE);
	}
	if(argc < 2){
		printf("Error, there is not enought arguments.\n%s\n", USAGE);
		exit(EXIT_ARGS_FAILURE);
	}
	set_src_map(env, argv);
	if(argc == 3)
		check_save_arg(env, argc, argv);
	if(parse_file(env) < RETURN_SUCCES){
		printf("Error, while reading the file %s\n", env->g_srcs[0].src);
		free_env(env);
		exit (-RETURN_FAILURE);
	}
	//tmp to change
	printf("ok %s %d %d\n", env->g_srcs[0].src, env->r.width, env->g_colors[0].color);
	free_env(env);
	
}