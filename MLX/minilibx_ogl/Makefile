#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -w
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

%.o: %.c
	@echo "$(GREEN)MLX:$(WHITE) Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.m
	@echo "$(GREEN)MLX:$(WHITE) Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NOM):	$(OBJ)
	@ar -rcs $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@echo "$(GREEN)MLX: $(WHITE)Removing lib$(RESET)"
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@echo "$(GREEN)MLX: $(WHITE)Lib removed sucessfully$(RESET)"

re: clean all
