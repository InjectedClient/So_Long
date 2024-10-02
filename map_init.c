/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:35:40 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/02 16:31:48 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_lines(char *file)
{
	int	fd;
	int count;
	char *line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count ++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int read_and_stock(char ***map, int fd)
{
	int i;
	char *line;

	i = 0;
	line = get_next_line(fd); //lis la prem ligne
	while (line != NULL)
	{
		(*map)[i] = line; //stock la ligne en entier
		line = get_next_line(fd); //lis la suivante
		i ++;
	}
	(*map)[i] = 0;
	free(line);
	return(1);
}

char	**create_map(char *file)
{
	int		fd;
	int		nb_line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	nb_line = count_lines(file); 	//compte les lignes dans le fichier
	map = malloc(sizeof(char*) * (nb_line + 1)); 	//allouer de la memoire stocker le nombre de lignes
	if (!map)
	{
		close (fd);
		free (map);
		return (NULL);
	}
	if (!read_and_stock(&map, fd))
	{
		free_my_map(map);
		return (NULL);
	}
	close (fd);
	map = change_newlines(map);
	return (map); //retourner map
}

