/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:07:45 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/10 16:20:53 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define UP		115
# define DOWN	119
# define LEFT	97
# define RIGHT	100
# define ESC	65307

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct s_position {
	int x;
	int y;
} t_position;

typedef struct s_data {
	int		mouv;
	int		columns;
	int		lines;
	int		width;
	int		height;
	int		perso_x;
	int		perso_y;
	int		c;
	char	**map;
	void	*mlx;
	void	*window;
	void	*perso;
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*exit;
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
int check_walls(char **map);
int check_elements(t_data *data);
int first_line(char **map);
int last_line(char **map);
int first_char(char **map);
int last_char(char **map);
int check_path(char **map);
char **map_copy(char **map);
t_position find_p(char **map);
int is_valid(int x, int y, char **map);
int floodfill(int x, int y, char **map);
void flood_fill_coins(int x, int y, char **map, int *coins);
int check_coins(t_data *data);

// Map Init
char	**create_map(char *file);
int read_and_stock(char ***map, int fd);
int count_lines(char *file);
void free_my_map(char **map);
char **change_newlines(char **map);
void	print_map(char **map);

void	*sprites_init(t_data *data);
int		data_init(t_data *data);
int	close_window(t_data *data);
void	display_utils(t_data *data, int i, int j);
void	display_mouv_count(t_data *data);
int	display(t_data *data);
int	key_parsing(int key, t_data *data);
void	end_game(t_data	*data);
int count_C(t_data *data);

# endif
