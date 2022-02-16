/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_from_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/16 12:11:32 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	fill_rgb(int *result, char **splitted)
{
	int		i;
	int		rgb[3];
	char	*trimmed;

	i = 0;
	while (i < 3)
	{
		trimmed = ft_strtrim(splitted[i], BLANK_CHARS);
		if (!trimmed)
			return (-EXIT_FAILURE);
		rgb[i] = parse_value(trimmed);
		free(trimmed);
		if (rgb[i] < 0 || rgb[i] > 255)
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
