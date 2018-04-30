/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:43:02 by oespion           #+#    #+#             */
/*   Updated: 2018/04/30 18:37:10 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_n(char *str)
{
	int	r;

	r = 0;
	while (str[r])
	{
		if (str[r] == '\n')
			return (r + 1);
		r++;
	}
	return (-1);
}

int	ft_strleft(t_struct *lst, char **line)
{
	int		r;

	r = 0;
	if (!lst->str)
		return (0);
	while (lst->str[r])
	{
		if (lst->str[r] == '\n')
		{
			*line = ft_strnew(BUFF_SIZE);
			*line = ft_memmove(*line, lst->str, find_n(lst->str) - 1);
			lst->str = ft_strsub(lst->str, find_n(lst->str),
				ft_strlen(lst->str) - find_n(lst->str));
			return (1);
		}
		r++;
	}
	*line = lst->str;
	lst->str = NULL;
	return (0);
}

int		ft_read(t_struct *lst, char **line, const int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		i;
	char	*tmp;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (find_n(buff) == -1)
			*line = ft_strfjoin(*line, buff);
		else
		{
			i = 0;
			*line = ft_strfjoin(*line, buff);
			tmp = *line;
			lst->str = ft_strsub(buff, find_n(buff), BUFF_SIZE - find_n(buff));
			ft_strdel(&tmp);
			while ((*line)[i] != '\n')
				i++;
			(*line)[i] = '\0';
			return (1);
		}
	}
	return ret == -1 ? -1 : 0;
}

int		get_next_line(const int fd, char **line)
{
	static t_struct	*lst;
	int				ruff;

	if (!line || fd < 0 || fd > OPEN_MAX || fd == 1 || fd == 2)
		return (-1);
	if (!lst)
	{
		if (!(lst = (t_struct*)malloc(sizeof(t_struct))))
			return (-1);
		lst->start = 0;
		lst->str = 0;
	}
	*line = ft_strnew(0);
	if (ft_strleft(lst, line) == 1)
		return (1);
	ruff = ft_read(lst, line, fd);
	if (ruff == -1)
		return (-1);
	return (*line)[0] != '\0' || ruff == 1 ? 1 : 0;
}
