NAME = libft.a
SRC = $(shell ls *.c)

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		ar -rcs $@ $^

all: $(NAME)

clean:
		rm -f $(OBJ)

re: clean all

fclean: clean
		rm -f $(NAME)
