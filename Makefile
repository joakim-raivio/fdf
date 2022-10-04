NAME := fdf
CC := gcc
FILES := \
	example
SRCS := $(foreach src, $(FILES), $(addsuffix .c, $(src)))
OBJS := $(foreach obj, $(FILES), $(addsuffix .o, $(obj)))
WWW := -Wall -Wextra -Werror
MINILIB := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
LIBFT := -I libft/includes -L libft/ -lft
CFLAGS := $(WWW) $(MINILIB) $(LIBFT)

all: $(NAME)

$(NAME): objects
	@echo "Compiling project binary\n"
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

objects:
	@make --no-print-directory -C ./libft
	@echo "Compiling project object files\n"
#	@echo $(FILES)
	@$(CC) $(SRCS) $(CFLAGS) -c

clean:
	@echo "Cleaning project object files\n"
	@rm -f $(OBJS)

fclean: clean
	@make --no-print-directory -C ./libft fclean
	@echo "Cleaning project binary\n"
	@rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

debug:
	@make -C ./libft testlib
	@$(CC) $(SRCS) $(FLAGS) -g -o $(NAME)

drun: fclean debug
	lldb $(NAME)
