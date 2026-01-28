/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:19:59 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/28 16:21:05 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	player_position(char **map, int *player_x, int *player_y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*player_x = j;
				*player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int i, int j)
{
	if (i < 0 || j < 0 || !map[i] || !map[i][j])
		return ;
	if (map[i][j] == '1' || map[i][j] == 'V')
		return ;
	map[i][j] = 'V';
	flood_fill(map, i + 1, j);
	flood_fill(map, i - 1, j);
	flood_fill(map, i, j + 1);
	flood_fill(map, i, j - 1);
}

//int 	playable(char **map)
//{
//	char **copy = copy_map(map);
//	int	player_x;
//	int	player_y;
//	int	playable = 1;
//	int	i;
//	int	j;

//	if (!copy)
//		return (0);
//	player_position(copy, &player_x, &player_y);
//	flood_fill(copy, player_x, player_y);
//	i = 0;
//	while (copy[i])
//	{
//		printf("%s\n", copy[i]);
//		i++;
//	}
//	printf("\n");
//	i = 0;
//	while (copy[i])
//	{
//		j = 0;
//		while (copy[i][j])
//		{
//			if (copy[i][j] == 'C' || copy[i][j] == 'E')
//				playable = 0;
//			j++; 
//		}
//		i++;
//	}
//	i = 0;
//	while (copy[i])
//	{
//		free(copy[i]);
//		i++;
//	}
//	free(copy);
//	return (playable);
//}

int	playable(char **map)
{
	char	**copy;
	int		x;
	int		y;
	int		i;
	int		j;

	copy = copy_map(map);
	if (!copy)
		return (0);
	find_player(copy, &x, &y);
	flood_fill(copy, x, y);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
				return (free_map(copy), 0);
			j++;
		}
		i++;
	}
	free_map(copy);
	return (1);
}
