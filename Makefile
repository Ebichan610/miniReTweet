# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 15:07:09 by ebichan           #+#    #+#              #
#    Updated: 2026/04/28 17:25:32 by ebichan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm
# MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES    = -I. -Ilibft -Iminilibx

LIBFT_DIR   = libft
MLX_DIR     = minilibx

LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

NAME = miniRT

SRCS =	src/misc/error.c\
	src/misc/free_elem.c\
	src/misc/free.c\
	src/misc/ft_atof.c\
	src/misc/ft_split_space.c\
	src/misc/utils.c\
	src/parse/apply.c\
	src/parse/get_next_line.c\
	src/parse/in_range.c\
	src/parse/parse1.c\
	src/parse/parse2.c\
	src/parse/read_file.c\
	src/raytracing/color_calc.c\
	src/raytracing/drawing_picture.c\
	src/raytracing/lighting.c\
	src/raytracing/ray.c\
	src/raytracing/shadow.c\
	src/raytracing/vec_calc.c\
	src/raytracing/hit_object/hit_cylinder.c\
	src/raytracing/hit_object/hit_plane.c\
	src/raytracing/hit_object/hit_sphere.c\
	src/raytracing/hit_object/hit_object.c\
	src/raytracing/hit_object/initialize_hit_structure.c\
	src/init.c\
	src/main.c\
	src/mlx_hook.c
		
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
