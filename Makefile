# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 15:07:09 by ebichan           #+#    #+#              #
#    Updated: 2026/04/13 18:37:19 by yebi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

# MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES    = -I. -Ilibft -Iminilibx

LIBFT_DIR   = libft
MLX_DIR     = minilibx

LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

NAME = miniRT

SRCS =	misc/error.c\
	misc/free_elem.c\
	misc/free.c\
	misc/ft_atof.c\
	misc/ft_split_space.c\
	misc/utils.c\
	parse/apply.c\
	parse/get_next_line.c\
	parse/in_range.c\
	parse/parse1.c\
	parse/parse2.c\
	parse/read_file.c\
	raytracing/color_calc.c\
	raytracing/drawing_picture.c\
	raytracing/lighting.c\
	raytracing/ray.c\
	raytracing/shadow.c\
	raytracing/vec_calc.c\
	raytracing/hit_object/hit_cylinder.c\
	raytracing/hit_object/hit_plane.c\
	raytracing/hit_object/hit_sphere.c\
	init.c\
	main.c\
	mlx_hook.c
		
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
