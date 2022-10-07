NAME := fdf
CC := gcc
FILES := main render init_map helpers interface
SRCS := $(foreach src, $(FILES), $(addsuffix .c, $(src)))
OBJS := $(foreach obj, $(FILES), $(addsuffix .o, $(obj)))
WWW := -Wall -Wextra -Werror
MINILIB := -lmlx -framework OpenGL -framework AppKit
LIBFTINC := -I libft
LIBFT := $(LIBFTINC) -L libft/ -lft
CFLAGS := $(WWW) $(MINILIB) $(LIBFT)

all: $(NAME)

$(NAME): objects
	@echo "Compiling project binary\n"
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

objects:
	@make --no-print-directory -C ./libft
	@echo "Compiling project object files\n"
#	@echo $(FILES)
	@$(CC) $(LIBFTINC) $(WWW) -c $(SRCS) 

clean:
	@echo "Cleaning project object files\n"
	@rm -f $(OBJS)

fclean: clean
	@make --no-print-directory -C ./libft fclean
	@echo "Cleaning project binary\n"
	@rm -f $(NAME)

re: fclean all

run: re
	./$(NAME) test_maps/basictest.fdf

debug:
	@make -C ./libft testlib
	$(CC) $(SRCS) $(CFLAGS) -g -o $(NAME)

drun: fclean debug
	lldb $(NAME) 
