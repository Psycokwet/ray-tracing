/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/05 15:45:27 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	void	*mlx;
	
	printf("ah que cou %d, %s\n", argc, argv[0]);
	ft_isalnum('e');
	if (!(mlx = mlx_init()))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf("OK (use_xshm %d pshm_format %d %d)\n",((t_xvar *)mlx)->use_xshm,((t_xvar *)mlx)->pshm_format, create_trgb(1,1, 1, 1));

	/* code */
	return 0;
}
