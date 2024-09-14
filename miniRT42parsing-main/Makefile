CC = cc
CFLAGS	= 

NAME = miniRT
SRC = ./Mandatory/src/main.c\
	   ./Mandatory/src/objects.c\
	   ./Mandatory/src/colors.c\
	   ./Mandatory/src/parse/read_file.c\
	   ./Mandatory/src/parse/check_type1.c\
	   ./Mandatory/src/parse/check_type2.c\
	   ./Mandatory/src/parse/print_type_utils.c\
	   ./Mandatory/src/parse/check_range.c\
	   ./Mandatory/src/parse/parse_type.c\
	   ./Mandatory/src/gnl/get_next_line.c\
	   ./Mandatory/src/gnl/get_next_line_utils.c\


OBJS := $(SRC:.c=.o)

LIBFT_DIR = ./Libft/  # Path to your libft folder
LIBFT = $(LIBFT_DIR)libft.a  # Path to the libft library

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)  #Call libft makefile

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)  -L$(LIBFT_DIR) -lft 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	rm -f $(OBJS) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: clean fclean all

.PHONY: all clean fclean re