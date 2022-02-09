# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: potero-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:44 by potero-d          #+#    #+#              #
#    Updated: 2022/02/09 11:49:32 by potero-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = sl_map.c sl_print.c sl_map_errors.c sl_check_map.c\
	   sl_assets.c sl_exit.c sl_key_event.c sl_movement.c\
	   gnl/get_next_line_utils.c gnl/get_next_line.c\

LIBFT_PATH = libft/

OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o:%.c
		$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o) -I$(LIBFT_PATH)
RM = rm -f

$(NAME): $(OBJS)
		@make -C $(LIBFT_PATH) --silent
		$(CC) $(CFLAGS) $(OBJS) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I./libft -L./libft -lft
	#	$(CC) $(CFLAGS) $(OBJS) -lmlx -L/usr/X11/lib -lXext -lX11 -lm -o $(NAME)
all: $(NAME)

sanitize: $(OBJS)
		@make -C $(LIBFT_PATH) clean --silent
		$(CC) -o $(NAME) $(OBJS) -fsanitize=address -g -sanitize: $(OBJS)
		$(CC) -o $(NAME) $(OBJS) -fsanitize=address -g -OO

clean:
			$(RM) $(OBJS)
			@make -C $(LIBFT_PATH) clean --silent

fclean: clean
			$(RM) $(NAME)
			@make -C $(LIBFT_PATH) fclean --silent

re: fclean $(NAME)

.PHONY: all clean fcelan re