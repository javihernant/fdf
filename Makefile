NAME:=fdf
LIBFT = libft/libft.a
SRC:=debug1.c \
	 common_utils1.c \
	 mlx_utils1.c \
	 mlx_utils2.c \
	 mlx_utils3.c \
	 keys_utils1.c \
	 keys_utils2.c \
	 ft_draw_line.c \
	 ft_draw_line_utils.c \
	 draw_map.c \
	 map_utils1.c \
	 map_utils2.c \
	 map_utils3.c \
	 parse_map.c \
	 handle_mouse.c \
	 handle_mouse_utils.c \
	 matrix.c \
	 matrix2.c \
	 handle_keys.c \
	 prog_utils.c \
	 parse_utils1.c \
	 parse_utils2.c \
	 menu.c \
	 main.c
	 
#main.c


#ft_isometric.c \

SRC:=$(addprefix src/,$(SRC))
OBJ=$(SRC:.c=.o)

COMPILED_OBJS=$(shell find . -name '*.o')
IFLAGS=-I./libft/include -I./include -I/usr/include -Imlx_linux
LFLAGS=-L./libft -L/usr/lib -Lmlx_linux
LIBS=-lft -lmlx -lXext -lX11 -lm -lz
#DBG=-g 
CFLAGS=-Wall -Wextra -Werror -O3
CC=gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ) -o $(NAME) $(LIBS) $(DBG)

%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -o3 -c $< -o $@ $(DBG)

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(COMPILED_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus libft clean fclean re 
