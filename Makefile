# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 13:28:28 by mtissari          #+#    #+#              #
#    Updated: 2022/10/13 19:28:34 by mtissari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY := all re clean fclean make
CC := gcc
CFLAGS := -Wall -Wextra -Werror -c
FILES := ft_printf.c flags_set.c ft_itoa_base.c char_and_string.c parcer.c \
		handle_base.c handle_ints.c handle_float.c handle_pointer.c \
		number_modifiers.c precision.c ft_ftoa.c
O_FILES := $(FILES:.c=.o)
INCLUDES := -I includes
LIBFT := libft
NAME := libftprintf.a
S_PATH := sources/
SOURCES := $(addprefix  $(S_PATH), $(FILES))

# COLORS

BLUEB :=  \033[1;34m
PURPLEB := \033[1;95m
GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;93m
YELLOWB := \033[1;93m
RESET := \033[0m

all: $(NAME)

$(NAME):
	@echo "$(YELLOWB)Creating $(LIBFT)...$(RESET)"
	@make re -C $(LIBFT)
	@cp libft/libft.a $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES)
	@ar -rcs $(NAME) $(O_FILES)
	@echo "$(GREEN)Created $(BLUEB)$(@)$(RESET)"

clean:
	@rm -f $(O_FILES) debug
	@make -C $(LIBFT) clean
	@echo "$(YELLOWB)Libft$(YELLOW) cleaned$(RESET)"
	@echo "$(BLUEB)Object files$(RED) deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@echo "$(GREEN)$(PURPLEB)$(NAME) $(RED)deleted$(RESET)"

re: fclean all
