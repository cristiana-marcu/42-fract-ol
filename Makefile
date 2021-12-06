# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 16:47:15 by cmarcu            #+#    #+#              #
#    Updated: 2021/12/06 13:45:44 by cmarcu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol
#INCLUDE_LIBFT	= ./srcs/libft
SRC_PATH	=	srcs/
OBJ_PATH	=	obj/

SOURCES		=	main.c \
				utils.c \
				key_hook.c \
				fractol.c \
				color.c \
				mandelbrot.c

SRCS		=	$(addprefix $(SRC_PATH), $(SOURCES))
OBJS		=	$(patsubst $(SRC_PATH)%, $(OBJ_PATH)%, $(SRCS:.c=.o))

CC	= gcc
CFLAGS		=	-Wall -Wextra -Werror $(SANITIZE)
SANITIZE	=	-g3 -fsanitize=address
RM			=	rm -f
INCLUDES	=	-Iincludes/
MLX			=	mlx/
MLX_LINK	=	-L $(MLX) -l mlx -framework OpenGL -framework AppKit

 $(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SANITIZE) $(OBJS) $(INCLUDES) $(MLX_LINK) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
