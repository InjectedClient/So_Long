/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:34:24 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/15 15:15:08 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_c(t_data *data)
{
	int	i;
	int	j;
	int	count_c;

	j = 0;
	i = 0;
	count_c = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				count_c ++;
			i ++;
		}
		j ++;
	}
	return (count_c);
}

char	**map_copy(char **map)
{
	int		i;
	char	**map_copy;
	int		lines;

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

int	check_char(char **map)
{
	int	i;
	int	j;

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

int	check_map_size(char **map)
{
	int	x;
	int	y;
	int	i;

	x = count_colones(map);
	y = count_lignes(map);
	i = 0;
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
