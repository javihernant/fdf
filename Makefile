NAME:=fdf
LIBFT = libft/libft.a
SRC:=parse_test.c \
	 common_utils1.c \
	 map_utils.c \
	 parse_map.c

SRC:=$(addprefix src/,$(SRC))
OBJ=$(SRC:.c=.o)

COMPILED_OBJS=$(shell find . -name '*.o')
IFLAGS=-I./libft/include -I./include -I/usr/include -Imlx_linux
LFLAGS=-L./libft -L/usr/lib -Lmlx_linux
LIBS=-lft -lmlx -lXext -lX11 -lm -lz
DBG=-g -g3
CFLAGS=
#-Wall -Wextra -Werror
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
