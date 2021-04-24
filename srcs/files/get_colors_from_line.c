/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_from_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/04/24 17:31:26 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "get_next_line.h"

int	fill_rgb(int *result, char **splitted)
{
	int		i;
	int		rgb[3];

	i = 0;
	while (i < 3)
	{
		rgb[i] = parse_value(splitted[i]);
		if (rgb[i] < 0)
			return (-EXIT_FAILURE);
		i++;
	}
	*result = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	return (EXIT_SUCCESS);
}

int	get_colors_from_line(const char *line)
{
	char	**splitted;
	int		ret;
	int		result;

	splitted = ft_split(line, ',');
	if (!splitted[0])
	{
		free(splitted);
		return (-EXIT_FAILURE);
	}
	ret = fill_rgb(&result, splitted);
	free_array(splitted);
	splitted = NULL;
	if (ret == EXIT_SUCCESS)
		return (result);
	return (ret);
}
