/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:28:42 by oespion           #+#    #+#             */
/*   Updated: 2018/04/27 19:01:42 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_print_line(t_struct *list, char **line, char *buff)
{
	int		r;
	char	*tmp;
	char	*s;

	r = 0;
	list->strleft = ft_strdup(buff);
	if (ft_memchr(buff, '\n', BUFF_SIZE + 1))
	{
		*line = ft_strjoin(*line, buff);
		tmp = *line;
		while (*tmp != '\n')
			tmp++;
		*tmp = '\0';
		s = ft_memchr(buff, '\n', BUFF_SIZE + 1);
		return (0);
	}
	*line = ft_strjoin(*line, buff);
	return (1);
}

void	ft_leftover(t_struct *list, char **line)
{
	int	r;
	int	i;

	i = 0;
	r = 0;
	while (list->strleft[r] != '\n' && list->strleft[r + 1]
			&& list->strleft[r])
		r++;
	r++;
	i = r;
	while (list->strleft[i])
		i++;
	if (!(*line = (char*)malloc(sizeof(char) * i)))
		return ;
	i = 0;
	while (list->strleft[r] != '\0')
	{
		*line[i] = list->strleft[r];
		i++;
		r++;
	}
}

void	ft_check_strleft(t_struct *list, char **line)
{
	int	r;
	int	i;

	i = 0;
	r = 0;
	if (!list->strleft)
		return ;
	while (list->strleft[r])
	{
		if (list->strleft[r] == '\n')
		{
			r++;
			if (!(*line = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
				return ;
			while (list->strleft[r] != '\0')
			{
				(*line)[i] = list->strleft[r];
				i++;
				r++;
			}
			(*line)[i] = '\0';
			return ;
		}
		r++;
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_struct	*list;
	int				ret;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || fd > OPEN_MAX || fd == 1 || fd == 2)
		return (ERROR);
	if (!list)
	{
		if (!(list = (t_struct*)malloc(sizeof(t_struct))))
			return (ERROR);
		list->strleft = 0;
	}
	ft_check_strleft(list, line);
	list->fd = fd;
	if (!list->strleft)
		*line = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = 0;
		if (ft_print_line(list, line, buff) == 0)
			break ;
	}
	return (0);
}
