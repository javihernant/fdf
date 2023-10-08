# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahernan <jahernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 17:18:21 by jahernan          #+#    #+#              #
#    Updated: 2022/11/11 15:51:22 by jahernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS= -I./include
DBG = 

NAME := libft.a
SRC := ft_atoi.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_bzero.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c 

SRC := $(addprefix src/,$(SRC))

BONUS_SRC := ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			ft_init_arr.c \
			ft_arr_handle_outofbounds.c \
			ft_arr_free.c \
			ft_strrev.c \
			ft_strcmp.c \
			ft_realloc.c \
			ft_int_sort.c

BONUS_SRC := $(addprefix src/,$(BONUS_SRC))

PRINTF_SRC := ft_printf.c \
			 ft_handle_conversion.c \
			 ft_print_value.c \
			 ft_convert_dec.c \
			 ft_convert_usig.c \
			 ft_convert_p.c \
			 ft_convert_str.c \
			 ft_convert_c.c \
			 ft_fix_flags.c \
			 ft_process_flags.c \
			 ft_process_precision.c \
			 ft_process_spec.c \
			 ft_process_width.c \
			 helper_one.c \
			 store_fts.c

PRINTF_SRC := $(addprefix src/ft_printf/,$(PRINTF_SRC))

GNL_SRC := get_next_line.c \
		  get_next_line_utils.c

GNL_SRC := $(addprefix src/,$(GNL_SRC))


COMPILED_OBJS = $(shell find . -name '*.o')

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(BONUS_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	ar rcs $@ $^

%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ $(DBG)

clean:
	rm -rf $(COMPILED_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.phony: all clean fclean re
