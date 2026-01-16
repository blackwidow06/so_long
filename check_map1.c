/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:02:05 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/16 11:03:42 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_exist(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("le fichier n'existe pas\n");
		return (0);
	}
	close(fd);
	return (1);
}
int	is_rectangular(int fd)
{
	char	line[MAX_LINE];
	int		len;
	int 	first_len = -1;
	int		bytes = 1;

	while (bytes > 0)
	{
		len = 0;
		while (len < MAX_LINE - 1 && bytes > 0)
		{
			bytes = read(fd, &line[len], 1);
			if (bytes > 0 && line[len] != '\n')
				len++;
		}
		if (bytes <= 0 && len == 0)
			return (1);
		if (len == 0)
			break;
		if (first_len == -1)
			first_len = len;
		else if (len != first_len)
				return (0);
	}
	return (1);
}
int map_not_empty(char *map)
{
	int		fd;
	char	c;
	int		bytes;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);

	bytes = read(fd, &c, 1);
	close(fd);
	if (bytes <= 0)
		return (0);
	return (1);
}