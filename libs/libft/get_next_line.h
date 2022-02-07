/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:24:42 by chbadad           #+#    #+#             */
/*   Updated: 2022/02/07 10:59:39 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define LINE_READ 1
# define EOF_REACHED 0
# define ERROR -1
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_gnllist
{
	int					fd;
	char				*save;
	char				*temp;
	struct s_gnllist	*next;
}		t_gnllist;

int		get_next_line(int fd, char **line);
int		create_next_line(char ***line, t_gnllist **curr, \
	int ret, t_gnllist **head);
t_gnllist	*lstadd_back(t_gnllist **alst, int fd);
t_gnllist	*ft_list_return_if(t_gnllist **head, int fd);
int		ft_newline_chr(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strdupcat(char *s1, char *s2, char **save);
char	*ft_strndup(const char *str, size_t len);
char	*ft_strtrimgnl(char *s1);
int		free_curr(t_gnllist **head, t_gnllist **curr, int res);

#endif
