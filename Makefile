# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 10:41:41 by malavaud          #+#    #+#              #
#    Updated: 2026/02/14 14:37:15 by malavaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c \
			  read_map.c \
			  map_utils.c \
			  map_utils2.c \
			  check_map1.c \
			  check_map2.c \
			  parse_map.c \
			  playable_map1.c \
			  playable_map2.c \
			  display.c \
			  key_handler.c \
			  init.c \
			  gnl/get_next_line.c \
			  gnl/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES	= -I. -I$(MLX_DIR) -Ignl

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re