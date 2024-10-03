/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:07:45 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/03 17:12:31 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct s_data {
	char  **map;
	int	collectible;
}	t_data;

// Parsing
int	check_arg(int argc, char **argv);
int	parsing(t_data *data);
int check_map_size(char **map);
int count_colones(char **map);
int count_lignes(char **map);
int check_P(char **map);
int check_E(char **map);
int check_C(t_data *data);
int	check_char(char **map);
// int check_walls(char **map);
int check_elements(t_data *data);

// Map Init
char	**create_map(char *file);
int read_and_stock(char ***map, int fd);
int count_lines(char *file);
void free_my_map(char **map);
char **change_newlines(char **map);
void	print_map(char **map);

# endif
