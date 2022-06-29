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
CFLAGS := -Wall -Wextra -Werror
FILES := ft_printf.c
SOURCES := $(addprefix sources/, $(FILES))
O_FILES := $(FILES:.c=.o)
INCLUDES := includes/
LIBFT := libft/
NAME := libftprintf.a

$(NAME):
	@make andclean -C $(LIBFT)
	@$(CC) $(FLAGS) $(SOURCES) -I $(LIBFT) -I $(MLX) -L $(MLXFLAGS) -L libft/ -lft -o $(NAME)

debug:
	@make re -C $(LIBFT)
	@$(CC) $(FLAGS) -g $(SOURCES) -I $(LIBFT) -I $(MLX) -L $(MLXFLAGS) -L libft/ -lft -o debug

all: $(NAME)

clean:
	@rm -f $(O_FILES) debug
	@make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
