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

void	set_src_map(t_env *env, char const *argv[]){
	int s1;
	int s2;

	s1 =  ft_strlen(MAP_EXT);
	s2 =  ft_strlen(argv[1]);
	if(ft_memcmp(MAP_EXT, argv[1] + s2 - s1, s1) != 0){
		printf("Error, the first argument has a wrong extension fit.\n %s", USAGE);
		exit(1);
	}
	env->conf.map_src = argv[1];
}