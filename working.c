/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:34:02 by oespion           #+#    #+#             */
/*   Updated: 2018/04/28 16:03:21 by oespion          ###   ########.fr       */
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

int		get_next_line(const int fd, char **line)
{
	static t_struct	*list;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	int				r;
	int				i;

	if (fd < 0 || fd > OPEN_MAX || fd == 1 || fd == 2)
		return (ERROR);
	if (!list)
	{
		if (!(list = (t_struct*)malloc(sizeof(t_struct))))
			return (ERROR);
		list->str = 0;
	}
	if (list->str)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i + 1] == '\0')
			{
				*line = ft_strdup(list->str);
				free(list->str);
				if ((*line)[i] == '\n')
					(*line)[i] = '\0';
				break ;
			}
			else if (list->str[i] == '\n')
			{
				*line = ft_strnew(BUFF_SIZE);
				*line = ft_memmove(*line, list->str, find_n(list->str) - 1);
				list->str = ft_strsub(list->str, find_n(list->str),
					ft_strlen(list->str) - find_n(list->str));
				printf("list->str = --%s--\n", list->str);
				return (CONTINUE);
			}
			i++;
		}
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(*line))
			*line = ft_strnew(0);
		buff[ret] = 0;
		if (find_n(buff) == -1)
			*line = ft_strfjoin(*line, buff);
		else
		{
			i = 0;
			*line = ft_strfjoin(*line, buff);
			while ((*line)[i] != '\n')
				i++;
			(*line)[i] = '\0';
			i = 0;
			list->str = ft_strnew(BUFF_SIZE);
			r = find_n(buff);
			while (buff[r])
				list->str[i++] = buff[r++];
			return (CONTINUE);
		}
	}
	return (END);
}
