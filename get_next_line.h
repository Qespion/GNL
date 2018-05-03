/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:17:57 by oespion           #+#    #+#             */
/*   Updated: 2018/05/01 15:18:46 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000000
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include "libft/includes/libft.h"

int				get_next_line(const int fd, char **line);

typedef struct	s_struct
{
	char		*str;
}				t_struct;

#endif
