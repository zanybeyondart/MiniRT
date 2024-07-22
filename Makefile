NAME = miniRT
CFLAGS = -Werror -Wall -Wextra
DEBUG_AD = -fsanitize=address
DEBUG_LEAK = -fsanitize=leak
SRC = $(patsubst %.c,%.o,$(wildcard Mandatory/src/*.c))
LIBFT = Libft
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

ifeq ($(shell uname), Linux)
	MLX = MLX/minilibx_linux
	MLX_FLAGS = -L$(MLX) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	MLX = MLX/minilibx_ogl
	MLX_FLAGS = -L$(MLX) -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(SRC)
	@cd $(MLX) && make
	@cd $(LIBFT) && make
	@cc $(MLX_FLAGS) ./libft/libft.a  $(DEBUG_AD) $^ -o $@

%.o: %.c
	@echo "$(GREEN)MiniRT:$(WHITE) Compiling $(notdir $<)$(RESET)"
	@$(CC) -c $< -o $@

clean:
	@cd $(MLX) && make clean
	@cd $(LIBFT) && make clean
	@echo "$(GREEN)MiniRT: $(WHITE)Removing all object files$(RESET)"
	@rm -f $(wildcard Mandatory/src/*.o)
	@echo "$(GREEN)MiniRT: $(WHITE) Object files cleared sucessfully$(RESET)"

fclean: clean
	@cd $(LIBFT) && make fclean
	@echo "$(GREEN)MiniRT: $(WHITE)Removing lib$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)MiniRT: $(WHITE)Lib removed sucessfully$(RESET)"

re: fclean all
