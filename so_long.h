/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:07:45 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/02 16:08:39 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct s_data {
	char  **map;
}	t_data;

// Parsing
int	check_arg(int argc, char **argv);

// Map Init
char	**create_map(char *file);
int read_and_stock(char ***map, int fd);
int count_lines(char *file);
void free_my_map(char **map);
char **change_newlines(char **map);
void	print_map(char **map);

# endif
