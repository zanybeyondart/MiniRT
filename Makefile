NAME = miniRT
CFLAGS = -Werror -Wall -Wextra
DEBUG_AD = -fsanitize=address
DEBUG_LEAK = -fsanitize=leak
SRC = $(wildcard Mandatory/src/*.c)
OBJ = $(patsubst %.c,%.o,$(wildcard Mandatory/src/*.c))
BONUS = 
LIBFT = $(wildcard Libft/*.c)

$(NAME): $(OBJ)
	cc $^ -o $@

all: $(NAME)