NAME = miniRT
#CFLAGS = -Werror -Wall -Wextra
#DEBUG_AD = -fsanitize=address
#DEBUG_LEAK = -fsanitize=leak
SRC = $(wildcard Mandatory/src/*.c) $(wildcard Mandatory/src/vec3_maths/*.c) $(wildcard Mandatory/src/cylinder/*.c) $(wildcard Mandatory/src/gnl/*.c) $(wildcard Mandatory/src/parse/*.c)
OBJ = $(SRC:.c=.o)
LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

ifeq ($(shell uname), Linux)
    MLX_DIR = MLX/minilibx_linux
    MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
    MLX_DIR = MLX/minilibx_ogl
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	@echo "$(GREEN)MiniRT: $(WHITE)Linking $(NAME)$(RESET)"
	@cd $(MLX_DIR) && make -s
	@$(CC) $(CFLAGS) $(DEBUG_AD) $(OBJ) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $@

%.o: %.c
	@echo "$(GREEN)MiniRT:$(WHITE) Compiling $(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	@echo "$(GREEN)MiniRT:$(WHITE) Compiling Libft$(RESET)"
	@cd $(LIBFT_DIR) && make -s

clean:
	@cd $(MLX_DIR) && make -s clean
	@cd $(LIBFT_DIR) && make -s clean
	@echo "$(GREEN)MiniRT: $(WHITE)Removing all object files$(RESET)"
	@rm -f $(OBJ)
	@echo "$(GREEN)MiniRT: $(WHITE)Object files cleared successfully$(RESET)"

fclean: clean
	@cd $(LIBFT_DIR) && make fclean -s
	@echo "$(GREEN)MiniRT: $(WHITE)Removing executable$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)MiniRT: $(WHITE)Executable removed successfully$(RESET)"

valgrind: re
	valgrind --leak-check=full ./$(NAME)

re: fclean all

.PHONY: all clean fclean re
