/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:21:46 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/10 16:16:44 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * verifie si une position (x, y) sur map est valide pour etre remplie;
 * xy doit etre > 0
 * map et map[xy] doit exister
 * la case doit etre 0, P ou C
 */
int is_valid(int x, int y, char **map)
{
	if ((x && y >= 0) && (map[x] && map[x][y]) && (map[x][y] == '0' || \
		map[x][y] == 'P' || map[x][y] == 'C'))
		return (1);
	return (0);
}
/**
 *  check si sortie 'E' est atteignable a partir de (x, y)
 * si la case actuelle est 'E' retoure 1
 * si la position est valide et non deja remplie par 'F'
 * marque la case comme remplie 'F'
 * appel recursivement la fonction pour cases adjacentes
 * aucune sortie trouvee-> 0
 * sortie trouvee -> 1
 */
int floodfill(int x, int y, char **map)
{
	if (map[x][y] == 'E')
		return (1);
	if (!is_valid(x, y, map) || map[x][y] == 'F')
		return (0);
	map[x][y] = 'F';
	if (floodfill(x - 1, y, map))
		return (1);
	if (floodfill(x + 1, y, map))
		return (1);
	if (floodfill(x, y - 1, map))
		return (1);
	if (floodfill(x, y + 1, map))
		return (1);
	return (0);
}
/**
 * check si la pos est pas deja F
 * si case contient 'C' incremente le compteur coin
 * marque la case comme remplie 'F'
 * pareil cases adjacentes
 */
void flood_fill_coins(int x, int y, char **map, int *coins)
{
	if (!is_valid(x, y, map) || map[x][y] == 'F')
		return ;
	if (map[x][y] == 'C')
		++*coins;
	map[x][y] = 'F';
	flood_fill_coins(x - 1, y, map, coins);
	flood_fill_coins(x + 1, y, map, coins);
	flood_fill_coins(x, y + 1, map, coins);
	flood_fill_coins(x, y - 1, map, coins);
}

t_position find_p(char **map)
{
	int i;
	int j;
	t_position pos;

	pos.x = -1;
	pos.y = -1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos.x = i;
				pos.y = j;
				return (pos);
			}
			j ++;
		}
		i ++;
	}
	return (pos);
}

