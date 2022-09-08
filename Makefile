# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 13:28:28 by mtissari          #+#    #+#              #
#    Updated: 2022/06/29 16:50:20 by mtissari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY := all re clean fclean make
CC := gcc
CFLAGS := -Wall -Wextra -Werror -c
FILES := ft_printf.c flags_set.c ft_itoa_base.c char_and_string.c parcer.c \
		handle_base.c handle_ints.c handle_numbers.c precision.c
O_FILES := $(FILES:.c=.o)
INCLUDES := -I includes
LIBFT := libft
NAME := libftprintf.a
S_PATH := sources/
SOURCES := $(addprefix  $(S_PATH), $(FILES))

all: $(NAME)

$(NAME):
	@make re -C $(LIBFT)
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) -lft
	ar -rcs $(NAME) $(O_FILES)

clean:
	@rm -f $(O_FILES) debug
	@make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
