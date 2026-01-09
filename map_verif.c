/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:19:59 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/09 16:14:52 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char 	**copy_map(char **map)
{
	int 	i;
	char 	**copy;
	
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) - (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
void	player_position(char **map, int *player_x, int *player_y)
{
	int 	i;
	int 	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][i] == 'P')
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
	if (map[i][j] == '1' || map[i][j] == 'V')
		return ;
	map[i][j] = 'V';
	flood_fill(map, i + 1, j);
	flood_fill(map, i - 1, j);
	flood_fill(map, i, j + 1);
	flood_fill(map, i, j - 1);
}

//if (!is_playable(map))
//{
//    printf("La map est pas jouable certains collectibles ou la sortie sont inaccessibles\n");
//    free_map(map);
//    return 1;
//}
