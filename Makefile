NAME =	so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm
RM = rm -rf

SRCS = parsing_utils3.c key_parsing.c display_map.c parsing_utils.c parsing_utils2.c map_parsing.c arg_parsing.c main.c map_init.c utils.c floodfill.c

OBJS = $(SRCS:.c=.o)

all:			$(NAME)
				@clear

$(NAME):		$(OBJS)
				make -C libft/
				make -C minilibx-linux/
				$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(MLX_FLAGS) libft/libft.a minilibx-linux/libmlx.a


clean:
				make clean -C libft/
				make clean -C minilibx-linux/
				$(RM) $(OBJS)
				@clear

fclean: 		clean
				$(RM) $(NAME) libft/libft.a libmlx_Linux.a

re: 			fclean all

.PHONY:			all clean fclean re
