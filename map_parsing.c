/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:34:29 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/03 17:13:32 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing(t_data *data)
{
	if (!check_map_size(data->map))
	{
		ft_printf("Error\nWrong map size");
		return (0);
	}
	if (!check_char(data->map))
		return (0);
	if (!check_elements(data))
		return (0);
	// verifier les caracteres dans la map (0,1, P, E, C) ou si carac different
	// verifier que la map est bordee de murs (pas de trous)
	return(1);
}

int	check_char(char **map)
{
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ICI
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
	if (x < 5 || y < 3)
		return (0);
	while (map[i] && map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
int check_elements(t_data *data)
{
	if (!check_P(data->map))
	{
		ft_printf("Error\nWrong player number");
		return (0);
	}
	else  if (!check_E(data->map))
	{
		ft_printf("Error\nWrong exit number");
		return (0);
	}
	else  if (!check_C(data))
	{
		ft_printf("Error\nCollectible number too low");
		return (0);
	}
	return (1);
}
