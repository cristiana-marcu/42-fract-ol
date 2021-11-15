# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cristianamarcu <cristianamarcu@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 16:47:15 by cmarcu            #+#    #+#              #
#    Updated: 2021/11/15 18:41:05 by cristianama      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c #TODO No vale poner asterisco
OBJS	=	$(SRCS:.c=.o)

NAME	=	fractol

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address
RM	= rm -f
INCLUDES = -I./includes/
MLX = ./mlx/
MLX_LINK = -L $(MLX) -l mlx -framework OpenGL -framework AppKit

INCLUDE_LIBFT	= ./srcs/libft

 %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -Imlx -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(MLX_LINK) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
