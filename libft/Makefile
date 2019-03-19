
NAME = libft.a
FLAGS = -Wall -Werror -Wextra
SRCS  = $(wildcard *.c)
OBJECTS = $(SRCS:.c=.o)
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs libft.a $(OBJECTS)
	@ranlib $(NAME)
	@printf "\r$(NAME) $(GREEN)✔                                    $(NC)\n"

$(OBJECTS): %.o:%.c
	@printf "\rCompiling $<                 "
	@gcc $(FLAGS) -c $< -o $@

clean:
	@printf "$(NAME) clean: $(YELLOW)✔$(NC)\n"
	@rm -f $(OBJECTS)

fclean: clean
	@printf "$(NAME) fclean: $(YELLOW)✔$(NC)\n"
	@rm -f $(NAME)

re: fclean all

test:
	@echo $(OBJECTS)