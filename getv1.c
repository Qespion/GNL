/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 10:45:51 by oespion           #+#    #+#             */
/*   Updated: 2018/04/27 18:55:42 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_struct	*ft_new(t_struct *strleft, const int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	if (!(strleft = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	strleft->allstring = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!strleft->allstring)
			strleft->allstring = ft_strdup(buff);
		else
		{
			tmp = strleft->allstring;
			strleft->allstring = ft_strjoin(strleft->allstring, buff);
			free(tmp);
		}
	}
	strleft->start = 0;
	return (strleft);
}

int			ft_print_line(t_struct *strleft, char **line)
{
	int	r;
	int	len;

	r = 0;
	len = strleft->start;
	while (strleft->allstring[len] != '\n' && strleft->allstring[len] != '\0')
		len++;
	len -= strleft->start;
	if (len == 0)
	{
		*line = "\0";
		return (0);
	}
	*line = ft_strsub(strleft->allstring, strleft->start, len);
	strleft->start = strleft->start + len + 1;
	if (strleft->allstring[strleft->start - 1] == '\0'
			&& strleft->allstring[strleft->start - 2] == '\n')
		return (0);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_struct	*strleft;

	if (fd < 0 || fd > OPEN_MAX || fd == 1 || fd == 2)
		return (-1);
	if (!(strleft))
	{
		strleft = ft_new(strleft, fd);
		if (!strleft->allstring)
			return (-1);
	}
	if (ft_print_line(strleft, line) == 0)
		return (0);
	return (1);
}
