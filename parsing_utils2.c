/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:01:56 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/07 15:42:35 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'C' && \
				map[i][j] != 'E' && map[i][j] != '0' && \
				map[i][j] != '1')
				return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}
int check_map_size(char **map)
{
	int x;
	int y;
	int i;

	x = count_colones(map);
	y = count_lignes(map);
	i = 0;
	//ft_printf("%d\n", x);
	//ft_printf("%d\n", y);
	if (x < 3 || y < 3)
		return (0);
	while (map[i] && map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
int first_line(char **map)
{
	int i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i ++;
	}
	return (1);
}

int last_line(char **map)
{
	int i;
	int c;

	c = count_lignes(map) - 1;
	i = 0;
	while (map[c][i])
	{
		if (map[c][i] != '1')
			return (0);
		i ++;
	}
	return (1);
}

int first_char(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (0);
		i ++;
	}
	return (1);
}
int last_char(char **map)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(map[0]) - 1;
	while (map[i])
	{
		if (map[i][j] != '1')
			return (0);
		i ++;
	}
	return (1);
}

char **map_copy(char **map)
{
	int i;
	char **map_copy;
	int lines;

	i = 0;
	lines = count_lignes(map);
	map_copy = malloc(sizeof(char *) * (lines + 1));
	if (!map_copy)
	{
		free(map_copy);
		return (0);
	}
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i ++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}
