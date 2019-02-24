
NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRCS  = $(wildcard *.c)

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs libft.a $(OBJECTS)

$(OBJECTS): %.o:%.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	@echo $(OBJECTS)