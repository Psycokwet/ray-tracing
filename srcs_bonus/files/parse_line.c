/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2022/02/16 11:30:40 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static const t_parsing	g_parsings[MAX_PARSING] = {
	(t_parsing){&is_map},
	(t_parsing){&set_colors_fc},
	(t_parsing){&set_srcs},
};

#define EXIT_PROCEED 6

int	free_and_return(char *s, int code)
{
	if (s)
		free(s);
	return (code);
}

int	cut_line(char *line, char *args[3])
{
	char	*cut;

	line = ft_strtrim(line, BLANK_CHARS);
	if (!line)
		return (-EXIT_FAILURE);
	cut = ft_strchr(line, ' ');
	if (!cut)
		return (free_and_return(line, EXIT_CODE_NOT_FOUND));
	args[1] = ft_strtrim(cut, BLANK_CHARS);
	if (!args[1])
		return (free_and_return(line, -EXIT_FAILURE));
	args[0] = ft_substr(line, 0, (int)(cut - line));
	free(line);
	if (!args[0])
		return (free_and_return(args[1], -EXIT_FAILURE));
	args[2] = NULL;
	return (EXIT_PROCEED);
}

int	ft_is_blank(char c)
{
	int	i;

	i = 0;
	while (BLANK_CHARS[i])
	{
		if (c == BLANK_CHARS[i])
			return (true);
		i++;
	}
	return (false);
}

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_is_blank(line[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

int	parse_line(t_env *datas, char *line)
{
	int		ret;
	int		command_id;
	char	*args[3];

	ret = -EXIT_CODE_NOT_FOUND;
	command_id = MAX_PARSING;
	ret = cut_line(line, args);
	if (ret == -EXIT_FAILURE)
		return (ret);
	if (ret == EXIT_CODE_NOT_FOUND)
	{
		if (is_line_empty(line) == false)
			return (EXIT_CODE_MAP_FOUND);
		else
			return (EXIT_CODE_NOT_FOUND);
	}
	while (--command_id >= 0)
	{
		ret = g_parsings[command_id].parser(datas, args);
		if (ret != EXIT_CODE_NOT_FOUND)
			break ;
	}
	free(args[0]);
	free(args[1]);
	return (ret);
}
