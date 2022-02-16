/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/16 12:24:06 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	parse_value(char const *arg)
{
	int				tmp;
	char			*checker;
	unsigned int	checker_length;

	if (arg == NULL)
		return (-EXIT_FAILURE);
	tmp = ft_atoi(arg);
	checker = ft_itoa(tmp);
	checker_length = ft_strlen(checker);
	if (!(ft_strncmp(arg, checker, \
		checker_length) == 0 && ft_strlen(arg) == checker_length))
	{
		free(checker);
		return (-EXIT_FAILURE);
	}
	free(checker);
	return (tmp);
}
