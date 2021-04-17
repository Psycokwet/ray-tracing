/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_from_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/17 17:15:01 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"

int		get_colors_from_line(const char *line)
{
	char	**splitted;
	int		rgb[3];
	int		i;
	int		ret;

	ret = EXIT_SUCCESS;
	i = 0;
	splitted = ft_split(line, ',');
	if (!splitted[0])
	{
		free(splitted);
		return (-EXIT_FAILURE);
	}
	while (i < 3)
	{
		rgb[i] = parse_value(splitted[0]);
		if (rgb[i] < 0)
		{
			ret = (-EXIT_FAILURE);
			break ;
		}
		i++;
	}
	free_array(splitted);
	splitted = NULL;
	if (ret == EXIT_SUCCESS)
		return (create_trgb(0, rgb[0], rgb[1], rgb[2]));
	return (ret);
}
