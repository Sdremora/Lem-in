# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 14:51:35 by hharvey           #+#    #+#              #
#    Updated: 2019/02/21 17:34:19 by sdremora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in
INCLUDES := include/ libft/
SRC_DIR := src/
OBJ_DIR := out/
SRC := $(patsubst $(SRC_DIR)%, %, $(wildcard src/*.c))

LIB_DIR := libft/
LIB := $(LIB_DIR)libft.a

OBJ := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
FLAGS := -Wall -Wextra -Werror
DEBUG_FLAGS := -g -O0

VPATH := $(SRC_DIR) $(OBJ_DIR) $(INCLUDES)
.PHONY: all run debug add_dflags clean fclean re echo

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
		gcc -g $(OBJ) $(LIB) $(addprefix -I,$(INCLUDES)) -o $@

$(OBJ_DIR)%.o: %.c
	gcc $(FLAGS) -c $(addprefix -I,$(INCLUDES)) $< -o $@

$(LIB):
	$(MAKE) -C $(LIB_DIR) all

debug: add_dflags all

add_dflags:
	$(eval FLAGS = $(DEBUG_FLAGS))

run:
	./lem-in < maps/2.map

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

echo:
	@echo $(SRC)
	@echo $(OBJ)
