/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 10:04:29 by oespion           #+#    #+#             */
/*   Updated: 2018/04/23 13:07:18 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	while (av[i])
	{
		printf ("%s\n", av[i]);
		fd = open(av[i], 0);
		while (get_next_line(fd, &line) == 0)
		{
			printf("%s\n", line);
			ft_strdel(&line);
		}
		++i;
	}
	return (0);
}
