/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:07:12 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/15 14:59:25 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_data	*data)
{
	data->mouv++;
	ft_printf("Nombre de mouvements : %d\n", data->mouv);
	ft_printf("\033[32m\tTu as fini le jeu en : %d coups\n\033[0m", data->mouv);
	close_window(data);
}

int	data_init(t_data *data)
{
	data->mouv = 0;
	data->width = 64;
	data->height = 64;
	data->window = mlx_new_window(data->mlx, data->width * \
					count_colones(data->map), data->height * \
					count_lignes(data->map), "so_long");
	if (!data->window)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_arg(argc, argv))
		return (0);
	data.map = create_map(argv[1]);
	if (!parsing(&data))
	{
		free_my_map(data.map);
		return (0);
	}
	data.mlx = mlx_init();
	if (data.mlx == 0 || data_init(&data))
		exit(0);
	sprites_init(&data);
	mlx_loop_hook(data.mlx, &display, &data);
	mlx_key_hook(data.window, &key_parsing, &data);
	mlx_hook(data.window, 17, 1L << 1, &close_window, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
	free_my_map(data.map);
	return (1);
}
