# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 08:46:14 by mchamma           #+#    #+#              #
#    Updated: 2024/03/05 11:45:04 by mchamma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Werror -Wextra -Wall -g3

SRC_DIR = src/
OBJ_DIR = obj/

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

INC = -I inc -I lib/libft/inc/
LIB = -L lib/libft/ -lft

#--------------------//-------------------#

all: $(NAME)

$(NAME): libft $(OBJ)
	cc $(OBJ) $(INC) $(LIB) -o $(NAME)

libft:
	$(MAKE) -C lib/libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(dir $@)
	cc $(FLAGS) $(INC) -c $< -o $@

#--------------------//-------------------#

clean:
	$(MAKE) -C lib/libft clean
	rm -rf $(OBJ_DIR)
	clear

fclean: clean
	$(MAKE) -C lib/libft fclean
	rm -f $(NAME)
	clear

re: fclean all
	make clean

test:
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	# ./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

#--------------------//-------------------#

.PHONY: all clean fclean re test

# leaks --atExit -- ./push_swap 1 2 3