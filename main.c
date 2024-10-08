/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:07:12 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/08 15:05:38 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data data;

	if (!check_arg(argc, argv)) // verifie les arg > 2, .ber et pas de map
		return (0);
	data.map = create_map(argv[1]); //creer la map en allant ligne par ligne dans le .ber
	if (!parsing(&data))
	{
		free_my_map(data.map);
		return (0);
	}
	return (1);
}
