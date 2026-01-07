# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 10:41:41 by malavaud          #+#    #+#              #
#    Updated: 2026/01/05 14:34:50 by malavaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror

NAME = so_long

ARCS = -ar rcs

SOURCE = 
	
HEADER = 

OBJ = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(ARCS) $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
