/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:46:55 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/08 15:29:30 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *file)
{
	int fd;
	int count;
	char *line;

	count  = 0;
	fd = open(file, O_RDONLY);
	while (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
char **read_map(char *file)
{
	char	**map;
	int 	line;
	int 	fd;
	int 	i;
	int 	lines;

	lines = count_lines(file);
	if (lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
int 	map_lines(char **map)
{
	int 	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
int 	map_char(char **map)
{
	int 	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}
int 	valid_chars(int **map)
{
	int 	i;
	int 	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1') &&
				(map[i][j] != '0') &&
				(map[i][j] != 'P') &&
				(map[i][j] != 'C') &&
				(map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}