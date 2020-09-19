# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfork <rfork@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/05 17:09:20 by rfork             #+#    #+#              #
#    Updated: 2020/01/13 20:23:37 by dovran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror
NAME = fractol
SRCS =	main.c	\
		points.c			points2.c	\
		images.c			picture.c	\
		keys.c				print_shapes.c	\
		hooks.c				mouse.c	\
		open_cl_buffers.c	open_cl_free.c	\
		open_cl_init.c		open_cl_read_build_run.c	\
		usage.c
OBJS = $(SRCS:.c=.o)

HEADERS = ft_buttons.h ft_cl_struct.h ft_fractol_struct.h ft_cl.h ft_fractol.h
SOURCE_HEADERS = $(addprefix ./includes/,$(HEADERS))
HEAD = $(addprefix -I,$(SOURCE_HEADERS))

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif
ifeq ($(detected_OS),Linux)
	MAKES := ./libft/libft.a  libs/minilibx/libmlx.a
	LIBMAKE := libs/minilibx
	LIB :=  -L libft -lft -L libs/minilibx -lmlx_Linux -lXext -lX11 -lm -framework OpenCL
	HEAD += -I./libs/minilibx/
endif
ifeq ($(detected_OS),Darwin)
	MAKES = ./libft/libft.a ./libs/minilibx_macos/libmlx.a
	LIBMAKE := libs/minilibx_macos
	LIB := -L libft -lft -L libs/minilibx_macos -lmlx -framework OpenGL -framework Appkit -framework OpenCL
	HEAD += -I./libs/minilibx_macos/
endif

.PHONY: clean fclean re
all: libs_refresh $(NAME)

%.o: %.c ${SOURCE_HEADERS}
	$(GCC) -c  $(HEAD) $<

libs_refresh:
	@make -C ./libft/
	@make -sC  $(LIBMAKE)

$(NAME): $(MAKES) $(OBJS)
	$(GCC) $(OBJS)  $(LIB) $(HEAD)  -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f *.d
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C $(LIBMAKE) clean

re: fclean all