# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/13 00:31:45 by mrida             #+#    #+#              #
#    Updated: 2026/01/03 04:28:02 by aalkhati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

INC_DIR		= includes
SRC_DIR		= src
OBJ_DIR		= obj

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
			  $(SRC_DIR)/algorithms/complex_sort.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
			$(RM) -r $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		all

.PHONY:		all clean fclean re bonus