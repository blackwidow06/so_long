/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:36:18 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/07 12:38:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MAX_LINE 1024

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
//int	main(void)
//{
//	int	fd;

//	if (!file_exist("map.txt"))
//		return (1);
		
//	if (!map_not_empty("map.txt"))
//    {
//        printf("le fichier map est vide\n");
//        return 1;
//    }

//    fd = open("map.txt", O_RDONLY);
//    if (fd < 0)
//        return 1;

//    if (is_rectangular(fd))
//        printf("La map est rectangulaire\n");
//    else
//        printf("La map n'est pas rectangulaire\n");

//    close(fd);
//    return 0;

//}
int	check_walls(char **map)
{
	int	i;
	int	j;
	int	lines;
	int	cols;

	lines = 0;
	while (map[lines] != NULL)
		lines++;
	if (lines < 3)
		return (0);
	cols = 0;
	while (map[0][cols] != '\0')
		cols++;
	j = 0;
	while (j < cols)
		if (map[0][j] != '1' || map[lines - 1][j++] != '1')
			return (0);
	i = 1;
	while (i < lines - 1)
	{
		if (map[i][0] != '1')
			return (0);
		j = 0;
		while (map[i][j])
			j++;
		if (map[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
int	one_exit(char **map)
{
	int	i;
	int	j;
	int	nbr_exit;

	nbr_exit = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				nbr_exit++;
			j++;
		}
		i++;
	}
	if (nbr_exit != 1)
		return (0);
	return (1);
}
int	one_player(char **map)
{
	int	i;
	int	j;
	int	nbr_player;

	nbr_player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				nbr_player++;
			j++;
		}
		i++;
	}
	return (nbr_player == 1);
}
int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	nbr_collectible;

	nbr_collectible = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				nbr_collectible++;
			j++;
		}
		i++;
	}
	return (nbr_collectible >= 1);
}
int	main(void)
{
	char *map[] =
	{
		"111111",
		"1P0C01",
		"100001",
		"1C00E1",
		"111111",
		NULL
	};
	if (!check_walls(map))
	{
		printf("erreur la map n'est pas entourée de murs\n");
		return (1);
	}
	if (!count_collectibles(map))
	{
		printf("Erreur : la map doit contenir au moins un collectible\n");
		return (1);
	}
	if (!one_player(map))
	{
		printf("Erreur la map doit contenir exactement une position de départ\n");
		return (1);
	}
	if (!one_exit(map))
	{
		printf("Erreur la map doit contenir exactement une sortie\n");
		return (1);
	}
	printf("La map est valide\n");
		return (0);
}
