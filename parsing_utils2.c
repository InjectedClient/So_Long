/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:01:56 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/15 15:12:16 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	first_line(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i ++;
	}
	return (1);
}

int	last_line(char **map)
{
	int	i;
	int	c;

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

int	first_char(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (0);
		i ++;
	}
	return (1);
}

int	last_char(char **map)
{
	int	i;
	int	j;

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
