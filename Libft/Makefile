NAME = libft.a
SRC = $(patsubst %.c,%.o,$(wildcard *.c))
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

all: $(NAME)

$(NAME): $(SRC)
	@ar -rcs $@ $^
	@echo "$(GREEN)Libft: $(WHITE)Compilation done! $(RESET)"

%.o: %.c
	@echo "$(GREEN)Libft:$(WHITE) Compiling $<$(RESET)"
	@$(CC) -c $< -o $@

clean:
	@echo "$(GREEN)Libft: $(WHITE)Removing all object files$(RESET)"
	@rm -f $(wildcard *.o)
	@echo "$(GREEN)Libft: $(WHITE) Object files cleared sucessfully$(RESET)"

re: clean all

fclean: clean
	@echo "$(GREEN)Libft: $(WHITE)Removing lib$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Libft: $(WHITE)Lib removed sucessfully$(RESET)"
