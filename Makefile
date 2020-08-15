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

GCC = gcc
NAME = fractol
SRCS = points.c      points2.c \
       images.c     main.c              \
       keys.c       print_shapes.c  \
       hooks.c     \
       mouse.c    picture.c open_cl.c read_program.c
OBJS = $(SRCS:.c=.o)
DEPENDS = ${OBJS:.o=.d} 
HEAD = -I ./includes/

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
	MAKES = ./libs/libft.a ./libs/minilibx_macos/libmlx.a 
	LIBMAKE := libs/minilibx_macos
	LIB := -L libft -lft -L libs/minilibx_macos -lmlx -framework OpenGL -framework Appkit -framework OpenCL
	HEAD += -I./libs/minilibx_macos/
endif

.PHONY: clean fclean re
all: $(NAME)

%.o: %.c
	$(GCC) -c  $(HEAD) $<

$(MAKES):
	make -C  ./libft
	make -sC  $(LIBMAKE)

-include ${DEPENDS}

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

# find_library(MLX mlx minilibx/libmlx.a)
# target_link_libraries(YOUR_PROJECT_NAME
#         "-framework AppKit"
#         "-framework OpenGL"
#         "-framework OpenCL"
#         ${MLX}
#         )