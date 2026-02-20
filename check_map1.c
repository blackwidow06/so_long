/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:02:05 by malavaud          #+#    #+#             */
/*   Updated: 2026/02/17 13:41:46 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_exist(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static int	check_len(int len, int *first_len)
{
	if (*first_len == -1)
		*first_len = len;
	else if (len != *first_len)
		return (0);
	return (1);
}

int	is_rectangular(int fd)
{
	char	c;
	int		len;
	int		first_len;
	int		bytes;

	first_len = -1;
	len = 0;
	bytes = read(fd, &c, 1);
	while (bytes > 0)
	{
		if (c == '\n')
		{
			if (!check_len(len, &first_len))
				return (0);
			len = 0;
		}
		else
			len++;
		bytes = read(fd, &c, 1);
	}
	if (bytes < 0)
		return (0);
	if (len > 0 && !check_len(len, &first_len))
		return (0);
	return (1);
}
