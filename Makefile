# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/13 00:31:45 by mrida             #+#    #+#              #
#    Updated: 2026/01/28 19:54:58 by aalkhati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

INC_DIR		= includes
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft
PRINTF_DIR	= ft_printf

LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/libftprintf.a

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/stack/stack_init.c \
			  $(SRC_DIR)/stack/stack_operations.c \
			  $(SRC_DIR)/operations/swap.c \
			  $(SRC_DIR)/operations/push.c \
			  $(SRC_DIR)/operations/rotate.c \
			  $(SRC_DIR)/operations/reverse_rotate.c \
			  $(SRC_DIR)/parsing/parse_args.c \
			  $(SRC_DIR)/parsing/validate_input.c \
			  $(SRC_DIR)/utils/is_sorted.c \
			  $(SRC_DIR)/utils/indexing.c \
			  $(SRC_DIR)/utils/disorder.c \
			  $(SRC_DIR)/algorithms/adaptive_sort.c \
			  $(SRC_DIR)/algorithms/simple_sort.c \
			  $(SRC_DIR)/algorithms/medium_sort.c \
			  $(SRC_DIR)/algorithms/complex_sort.c\
			  $(SRC_DIR)/utils/free_split.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all:		$(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
			make -C $(LIBFT_DIR)

$(PRINTF):
			make -C $(PRINTF_DIR)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
			$(RM) -r $(OBJ_DIR)
			make -C $(LIBFT_DIR) clean
			make -C $(PRINTF_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(LIBFT_DIR) fclean
			make -C $(PRINTF_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re