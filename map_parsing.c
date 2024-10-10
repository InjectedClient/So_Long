/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:34:29 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/10 16:22:19 by nlambert         ###   ########.fr       */
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
	else if (!check_char(data->map))
		{
			ft_printf("Error\nMissing or wrong element");
			return (0);
		}
	else if (!check_walls(data->map))
		{
			ft_printf("Error\nInvalid Walls");
			return (0);
		}
	else if (!check_elements(data))
		return (0);
	else if (!check_path(data->map) || !check_coins(data))
	{
			ft_printf("Error\nNo valid path found");
			return (0);
	}
	return(1);
}

int check_elements(t_data *data)
{
	if (!check_P(data->map))
	{
		ft_printf("Error\nWrong player number");
		return (0);
	}
	else if (!check_E(data->map))
	{
		ft_printf("Error\nWrong exit number");
		return (0);
	}
	else if (!check_C(data))
	{
		ft_printf("Error\nCollectible number too low");
		return (0);
	}
	return (1);
}

int check_walls(char **map)
{
	if (!first_line(map))
		return (0);
	if (!last_line(map))
		return (0);
	if (!first_char(map))
		return (0);
	if (!last_char(map))
		return (0);
	return (1);
}

int check_path(char **map)
{
	char **map_dup;
	t_position posi;

	map_dup = map_copy(map);
	posi = find_p(map_dup);
	if (!floodfill(posi.x, posi.y, map_dup))
	{
		free_my_map(map_dup);
		return (0);
	}
	free_my_map(map_dup);
	return (1);
}

int check_coins(t_data *data)
{
	char **map_dup;
	int	total_coins;
	t_position posi;

	total_coins = 0;
	map_dup = map_copy(data->map);
	posi = find_p(map_dup);
	flood_fill_coins(posi.x, posi.y, map_dup, &total_coins);
	free_my_map(map_dup);
	if (total_coins != count_C(data))
		return (0);
	return (1);
}
