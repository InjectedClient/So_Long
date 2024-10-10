/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:41:13 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/10 15:46:46 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	up(t_data *data)
{
	if (data->map[data->perso_y + 1][data->perso_x] != '1')
	{
		if (data->map[data->perso_y + 1][data->perso_x] != 'E'
			&& data->c != 0)
		{
			data->map[data->perso_y][data->perso_x] = '0';
			data->map[data->perso_y + 1][data->perso_x] = 'P';
		}
		else if (data->map[data->perso_y + 1][data->perso_x] != 'E'
			&& data->c == 0)
		{
			data->map[data->perso_y][data->perso_x] = '0';
			data->map[data->perso_y + 1][data->perso_x] = 'P';
		}
		else if (data->map[data->perso_y + 1][data->perso_x] == 'C'
			&& data->c != 0)
			data->c -= 1;
		else if (data->map[data->perso_y + 1][data->perso_x] == 'E'
			&& data->c == 0)
			end_game(data);
		data->mouv++;
		ft_printf("Nombre de mouvements : %d\n", data->mouv);
	}
}

static void	down(t_data *data)
{
	if (data->map[data->perso_y - 1][data->perso_x] != '1')
	{
		if (data->map[data->perso_y - 1][data->perso_x] != 'E'
			&& data->c != 0)
		{
			data->map[data->perso_y][data->perso_x] = '0';
			data->map[data->perso_y - 1][data->perso_x] = 'P';
		}
		else if (data->map[data->perso_y - 1][data->perso_x] != 'E'
			&& data->c == 0)
		{
			data->map[data->perso_y][data->perso_x] = '0';
			data->map[data->perso_y - 1][data->perso_x] = 'P';
		}
		else if (data->map[data->perso_y - 1][data->perso_x] == 'C'
			&& data->c != 0)
			data->c -= 1;
		else if (data->map[data->perso_y - 1][data->perso_x] == 'E'
			&& data->c == 0)
			end_game(data);
		data->mouv++;
		ft_printf("Nombre de mouvements : %d\n", data->mouv);
	}
}

static void	right(t_data *data)
{
	if (data->map[data->perso_y][data->perso_x + 1] != '1')
	{
		if (data->map[data->perso_y][data->perso_x + 1] != 'E'
			&& data->c != 0)
		{
			data->map[data->perso_y][data->perso_x] = '0';
			data->map[data->perso_y][data->perso_x + 1] = 'P';
		}
		else if (data->map[data->perso_y][data->perso_x + 1] != 'E'
			&& data->c == 0)
		{
			data->map[data->perso_y][data->perso_x] = '0';
			data->map[data->perso_y][data->perso_x + 1] = 'P';
		}
		else if (data->map[data->perso_y][data->perso_x + 1] == 'C'
			&& data->c != 0)
			data->c -= 1;
		else if (data->map[data->perso_y][data->perso_x + 1] == 'E'
			&& data->c == 0)
			end_game(data);
		data->mouv++;
		ft_printf("Nombre de mouvements : %d\n", data->mouv);
	}
}

static void	left(t_data *data)
{
	if (data->map[data->perso_y][data->perso_x - 1] != '1')
	{
		if (data->map[data->perso_y][data->perso_x - 1] != 'E'
			&& data->c != 0)
		{
			data->map[data->perso_y][data->perso_x] = '0';
			data->map[data->perso_y][data->perso_x - 1] = 'P';
		}
		else if (data->map[data->perso_y][data->perso_x - 1] != 'E'
			&& data->c == 0)
		{
			data->map[data->perso_y][data->perso_x] = '0';
			data->map[data->perso_y][data->perso_x - 1] = 'P';
		}
		else if (data->map[data->perso_y][data->perso_x - 1] == 'C'
			&& data->c != 0)
			data->c -= 1;
		else if (data->map[data->perso_y][data->perso_x - 1] == 'E'
			&& data->c == 0)
			end_game(data);
		data->mouv++;
		ft_printf("Nombre de mouvements : %d\n", data->mouv);
	}
}

int	key_parsing(int key, t_data *data)
{
	data->c = check_C(data);
	if (key == UP)
		up(data);
	else if (key == DOWN)
		down(data);
	else if (key == RIGHT)
		right(data);
	else if (key == LEFT)
		left(data);
	else if (key == ESC)
		close_window(data);
	return (0);
}
