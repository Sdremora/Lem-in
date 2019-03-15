
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

GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color

VPATH := $(SRC_DIR) $(OBJ_DIR) $(INCLUDES)
.PHONY: all run debug add_dflags clean fclean re echo

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIB) $(OBJ)
		@gcc $(OBJ) $(LIB) $(addprefix -I,$(INCLUDES)) -o $@
		@printf "\r$(NAME) $(GREEN)✔$(NC)                                        \n"

$(OBJ_DIR):
		@mkdir out

$(OBJ_DIR)%.o: %.c
	@printf "\rCompiling $<                 "
	@gcc $(FLAGS) -c $(addprefix -I,$(INCLUDES)) $< -o $@

$(LIB):
	@$(MAKE) -C $(LIB_DIR) all

debug: add_dflags all

add_dflags:
	$(eval FLAGS = $(DEBUG_FLAGS))

run:
	./lem-in < maps/1.map

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	@printf "$(NAME) clean: $(YELLOW)✔$(NC)\n"
	@rm -rf $(OBJ_DIR)
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	@printf "$(NAME) fclean: $(YELLOW)✔$(NC)\n"
	@/bin/rm -f $(NAME)

re: fclean all

echo:
	@echo $(SRC)
	@echo $(OBJ)
