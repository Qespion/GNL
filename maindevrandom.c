/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maindevrandom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 18:26:36 by oespion           #+#    #+#             */
/*   Updated: 2018/04/30 18:34:59 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int		i;
	int		ret;

	if (ac == 2)
	i = open(av[1], 0);
	while ((ret = get_next_line(i, &line)) > 0)
	{
		printf("%d\n", ret);
		printf("%s\n", line);
	}
	free(line);
	return (0);
}
