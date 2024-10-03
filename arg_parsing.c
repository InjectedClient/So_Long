/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:15:40 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/03 11:48:43 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	the_ber(char **argv)
{
	int len;

	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'r')
		return (0);
	else if (argv[1][len - 2] != 'e')
		return (0);
	else if (argv[1][len - 3] != 'b')
		return (0);
	else if (argv[1][len - 4] != '.')
		return (0);
	return (1);
}

int	check_arg(int argc, char **argv)
{
	int map;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments !\n");
		return (0);
	}
	if (!the_ber(argv))
	{
		ft_printf("Error\nFUCK YOU RICHIE! This is not a .ber file\n");
		return (0);
	}
	map = open(argv[1], O_RDONLY);
	if (map < 0)
	{
		ft_printf("Error\nFile not found\n");
		return (0);
	}
	return (1);
}
