/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:12:46 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/15 15:18:03 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_colones(char **map)
{
	int	i;

	i = 0;
	while (map[0] && map[0][i])
		i ++;
	return (i);
}

int	count_lignes(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i ++;
	return (i);
}

int	check_p(char **map)
{
	int	i;
	int	j;
	int	count_p;

	j = 0;
	i = 0;
	count_p = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				count_p ++;
			i ++;
		}
		j ++;
	}
	if (count_p == 1)
		return (1);
	else
		return (0);
}

int	check_e(char **map)
{
	int	i;
	int	j;
	int	count_e;

	j = 0;
	i = 0;
	count_e = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				count_e ++;
			i ++;
		}
		j ++;
	}
	if (count_e == 1)
		return (1);
	else
		return (0);
}

int	check_c(t_data *data)
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
	if (count_c < 1)
		return (0);
	else
	{
		data->c = count_c;
		return (1);
	}
}
